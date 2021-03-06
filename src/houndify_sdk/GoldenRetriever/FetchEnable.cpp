/* file "FetchEnable.cpp" */

/* Copyright 2012-2015 SoundHound, Incorporated.  All rights reserved. */


#include "FetchEnable.h"
#include <stddef.h>


static bool disabled = false;
static bool ignore = false;
static const char *disable_reason = NULL;


extern void disable_fetches(const char *reason)
  {
    disable_reason = reason;
    disabled = true;
  }

extern void set_ignore_fetch_disable(void)
  {
    ignore = true;
  }

extern void enable_fetches(void)
  {
    disabled = false;
  }

extern bool fetches_are_enabled(void)
  {
    return ignore || !disabled;
  }

extern const char *fetch_disable_reason(void)
  {
    return disable_reason;
  }
