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

class HoundRequester;
extern int hound_driver(HoundRequester *requester);

#endif /* HOUND_DRIVER_H */
