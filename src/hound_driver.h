#ifndef HOUND_DRIVER
#define HOUND_DRIVER


#include <stdio.h>
#include <string.h>
#include "HoundCloudRequester.h"
extern "C"
{
    #include "o_integer.h"
}
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

#include <QString>
#include <QByteArray>

class HoundRequester;
extern QByteArray hound_driver(QString audioUrl);

class LocalPartialHandler : public HoundRequester::PartialHandler
{
    private:
        bool show_transcript;

    public:
        LocalPartialHandler(bool show_transcript) : show_transcript(show_transcript)  { }
        ~LocalPartialHandler(void)  { }

        void handle(HoundPartialTranscriptJSON *partial)
        {
            if (show_transcript)
            {
                fprintf(stderr, "Partial Transcript: `%s'.\n", partial->getPartialTranscript().c_str());
            }
        }
};

#endif /* HOUND_DRIVER_H */
