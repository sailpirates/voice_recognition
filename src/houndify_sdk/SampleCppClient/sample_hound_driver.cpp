/* file "sample_hound_driver.cpp" */

/* Copyright 2014, 2015 SoundHound, Incorporated.  All rights reserved. */


#include "sample_hound_driver.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <errno.h>
#include "RequestInfoJSON.h"
#include "HoundServerJSON.h"
#include "HoundPartialTranscriptJSON.h"
#include "ConversationStateJSON.h"
#include "HoundRequester.h"
#include "Fetch.h"
#include "sample_hound_driver_system_dependent.h"


extern int sample_hound_driver(HoundRequester *requester)
  {
    bool done = false;
    ConversationStateJSON *conversation_state = NULL;
    srand(get_random_seed());

    char session_id[41];
    for (size_t num = 0; num < 10; ++num)
      {
        char bits[3];
        bits[0] = (char)(rand());
        bits[1] = (char)(rand());
        bits[2] = (char)(rand());
        base64url_encode_three(&(session_id[num * 4]), &(bits[0]));
      }
    session_id[40] = 0;

    while (true)
      {
        std::string line = get_user_input_line(&done);
        if (done)
            break;

        RequestInfoJSON *request_info = new RequestInfoJSON();
        request_info->setUnitPreference(RequestInfoJSON::UnitPreference_US);
        char request_id[41];
        for (size_t num = 0; num < 10; ++num)
          {
            char bits[3];
            bits[0] = (char)(rand());
            bits[1] = (char)(rand());
            bits[2] = (char)(rand());
            base64url_encode_three(&(request_id[num * 4]), &(bits[0]));
          }
        request_id[40] = 0;
        request_info->setRequestID(request_id);
        request_info->setSessionID(session_id);
        RequestInfoJSON::TypeClientVersion client_version;
        client_version.key = 0;
        client_version.choice0 = "1.0";
        request_info->setClientVersion(client_version);

        HoundServerJSON *hound_result;
        if ((strncmp(line.c_str(), "-audio ", 7) == 0) ||
            (strncmp(line.c_str(), "-transcript-audio ", 18) == 0) ||
            (strncmp(line.c_str(), "-slow-transcript-audio ", 23) == 0))
          {
            bool go_slowly =
                    (strncmp(line.c_str(), "-slow-transcript-audio ", 23) == 0);
            bool show_transcript =
                    ((strncmp(line.c_str(), "-transcript-audio ", 18) == 0) ||
                     (strncmp(line.c_str(), "-slow-transcript-audio ", 23) ==
                      0));
            class LocalPartialHandler : public HoundRequester::PartialHandler
              {
              private:
                bool show_transcript;

              public:
                LocalPartialHandler(bool show_transcript) :
                        show_transcript(show_transcript)  { }
                ~LocalPartialHandler(void)  { }

                void handle(HoundPartialTranscriptJSON *partial)
                  {
                    if (show_transcript)
                      {
                        fprintf(stderr, "Partial Transcript: `%s'.\n",
                                partial->getPartialTranscript().c_str());
                      }
                  }
              };
            LocalPartialHandler partial_handler(show_transcript);
            HoundRequester::VoiceRequest *request =
                    requester->start_voice_request(conversation_state,
                            request_info, &partial_handler);
            const char *file_name = &(line.c_str()[0]);
            while (*file_name != ' ')
                ++file_name;
            ++file_name;
            FILE *audio_fp = fopen(file_name, "rb");
            if (audio_fp == NULL)
              {
                fprintf(stderr, "Error trying to open audio file `%s': %s\n",
                        file_name, strerror(errno));
                return 1;
              }
            while (true)
              {
#define CHUNK_BYTE_COUNT 2052
                unsigned char buffer[CHUNK_BYTE_COUNT];
                size_t byte_count =
                        fread(&(buffer[0]), 1, CHUNK_BYTE_COUNT, audio_fp);
                if (byte_count > 0)
                    request->add_audio(byte_count, &(buffer[0]));
                if (byte_count < CHUNK_BYTE_COUNT)
                    break;
                if (go_slowly)
                    wait_half_a_second();
#undef CHUNK_BYTE_COUNT
              }
            fclose(audio_fp);
            hound_result = request->finish();
            if (hound_result != NULL)
                hound_result->add_reference();
            delete request;
          }
        else
          {
            hound_result = requester->do_text_request(line.c_str(),
                    conversation_state, request_info);
            if (hound_result != NULL)
                hound_result->add_reference();
          }

        if (hound_result == NULL)
            return 1;

        if (conversation_state != NULL)
            conversation_state->remove_reference();
        if (hound_result->hasAllResults())
          {
            if (hound_result->countOfAllResults() == 0)
              {
                printf("No match.\n");
                conversation_state = NULL;
              }
            else
              {
                CommandResultJSON *command =
                        hound_result->elementOfAllResults(0);
                printf("Result: %s\n",
                       command->getWrittenResponseLong().c_str());
                if (command->hasConversationState())
                  {
                    conversation_state = command->getConversationState();
                    conversation_state->add_reference();
                  }
                else
                  {
                    conversation_state = NULL;
                  }
              }
          }
        else if (hound_result->hasErrorMessage())
          {
            printf("Error from server: %s\n",
                   hound_result->getErrorMessage().c_str());
            conversation_state = NULL;
          }
        else
          {
            printf("No result or error from server.\n");
            conversation_state = NULL;
          }

        hound_result->remove_reference();
      }

    if (conversation_state != NULL)
        conversation_state->remove_reference();

    return 0;
  }
