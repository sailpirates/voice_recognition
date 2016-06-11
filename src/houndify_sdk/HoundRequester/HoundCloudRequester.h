/* file "HoundCloudRequester.h" */

/* Copyright 2014, 2015 SoundHound, Incorporated.  All rights reserved. */


#ifndef HOUNDCLOUDREQUESTER_H
#define HOUNDCLOUDREQUESTER_H

#include <string>
#include "HoundRequester.h"
#include "RequestInfoJSON.h"
#include "HoundServerJSON.h"
#include "HoundPartialTranscriptJSON.h"
#include "Fetch.h"


class HoundCloudRequester : public HoundRequester
  {
  private:
    std::string text_request_url_base;
    std::string voice_request_url_base;
    std::string client_id;
    std::string client_key;
    std::string user_id;

    void set_up_fetch(Fetch *fetcher, ConversationStateJSON *conversation_state,
                      RequestInfoJSON *request_info);

  public:
    HoundCloudRequester(const char *client_id, const char *client_key,
            const char *user_id,
            const char *text_request_url_base = default_text_request_url_base(),
            const char *voice_request_url_base =
                    default_voice_request_url_base());
    ~HoundCloudRequester(void)  { }

    HoundServerJSON *do_text_request(const char *query,
            ConversationStateJSON *conversation_state,
            RequestInfoJSON *request_info);
    VoiceRequest *start_voice_request(ConversationStateJSON *conversation_state,
            RequestInfoJSON *request_info,
            PartialHandler *partial_handler = NULL);

    static const char *default_text_request_url_base(void);
    static const char *default_voice_request_url_base(void);
  };


#endif /* HOUNDCLOUDREQUESTER_H */
