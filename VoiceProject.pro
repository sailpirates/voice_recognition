# NOTICE:
#
# Application name defined in TARGET has a corresponding QML filename.
# If name defined in TARGET is changed, the following needs to be done
# to match new name:
#   - corresponding QML filename must be changed
#   - desktop icon filename must be changed
#   - desktop filename must be changed
#   - icon definition filename in desktop file must be changed
#   - translation filenames have to be changed

# The name of your application
TARGET = VoiceProject

CONFIG += sailfishapp

SOURCES += src/VoiceProject.cpp \
    src/hound_driver.cpp \
    src/recorder.cpp

OTHER_FILES += qml/VoiceProject.qml \
    qml/cover/CoverPage.qml \
    qml/pages/FirstPage.qml \
    qml/pages/SecondPage.qml \
    rpm/VoiceProject.changes.in \
    rpm/VoiceProject.spec \
    rpm/VoiceProject.yaml \
    translations/*.ts \
    VoiceProject.desktop

SAILFISHAPP_ICONS = 86x86 108x108 128x128 256x256

INCLUDEPATH += $$PWD/src/houndify_sdk/c_foundations
INCLUDEPATH += $$PWD/src/houndify_sdk/SalmonEye
INCLUDEPATH += $$PWD/src/houndify_sdk/JSON
INCLUDEPATH += $$PWD/src/houndify_sdk/Numbers
INCLUDEPATH += $$PWD/src/houndify_sdk/ReferenceCounting
INCLUDEPATH += $$PWD/src/houndify_sdk/HoundJSON
INCLUDEPATH += $$PWD/src/houndify_sdk/GoldenRetriever
INCLUDEPATH += $$PWD/src/houndify_sdk/HTTP
INCLUDEPATH += $$PWD/src/houndify_sdk/HoundRequester

DEPENDPATH += $$PWD/src/houndify_sdk/c_foundations
DEPENDPATH += $$PWD/src/houndify_sdk/SalmonEye
DEPENDPATH += $$PWD/src/houndify_sdk/JSON
DEPENDPATH += $$PWD/src/houndify_sdk/Numbers
DEPENDPATH += $$PWD/src/houndify_sdk/ReferenceCounting
DEPENDPATH += $$PWD/src/houndify_sdk/HoundJSON
DEPENDPATH += $$PWD/src/houndify_sdk/GoldenRetriever
DEPENDPATH += $$PWD/src/houndify_sdk/HTTP
DEPENDPATH += $$PWD/src/houndify_sdk/HoundRequester

# to disable building translations every time, comment out the
# following CONFIG line
CONFIG += sailfishapp_i18n
#HEADERS +=  $$PWD/src/houndify_sdk/Common/RegEx.h \
#            $$PWD/src/houndify_sdk/c_foundations/auto_array.h \
#            $$PWD/src/houndify_sdk/c_foundations/auto_array_implementation.h \
#            $$PWD/src/houndify_sdk/c_foundations/basic.h \
#            $$PWD/src/houndify_sdk/c_foundations/buffer_print.h \
#            $$PWD/src/houndify_sdk/c_foundations/code_point.h \
#            $$PWD/src/houndify_sdk/c_foundations/diagnostic.h \
#            $$PWD/src/houndify_sdk/c_foundations/memory_allocation.h \
#            $$PWD/src/houndify_sdk/c_foundations/memory_allocation_test.h \
#            $$PWD/src/houndify_sdk/c_foundations/merge_dense_integer_arrays.h \
#            $$PWD/src/houndify_sdk/c_foundations/print_formatting/bytewise_hex_pointer_conversion.h \
#            $$PWD/src/houndify_sdk/c_foundations/print_formatting/division_floating_point_conversion.h \
#            $$PWD/src/houndify_sdk/c_foundations/print_formatting/floating_point_output_caller.h \
#            $$PWD/src/houndify_sdk/c_foundations/print_formatting/floating_point_output_conversion.h \
#            $$PWD/src/houndify_sdk/c_foundations/print_formatting/floating_point_plug_in.h \
#            $$PWD/src/houndify_sdk/c_foundations/print_formatting/pointer_plug_in.h \
#            $$PWD/src/houndify_sdk/c_foundations/print_formatting/sprintf_floating_point_conversion.h \
#            $$PWD/src/houndify_sdk/c_foundations/print_formatting/sprintf_pointer_conversion.h \
#            $$PWD/src/houndify_sdk/c_foundations/print_formatting.h \
#            $$PWD/src/houndify_sdk/c_foundations/string_aam.h \
#            $$PWD/src/houndify_sdk/c_foundations/string_index.h \
#            $$PWD/src/houndify_sdk/c_foundations/trace.h \
#            $$PWD/src/houndify_sdk/c_foundations/try.h \
#            $$PWD/src/houndify_sdk/c_foundations/version.h \
#            $$PWD/src/houndify_sdk/c_foundations/__asr_memcheck.h \
#            $$PWD/src/houndify_sdk/GoldenRetriever/Fetch.h \
#            $$PWD/src/houndify_sdk/GoldenRetriever/FetchEnable.h \
#            $$PWD/src/houndify_sdk/GoldenRetriever/GoldenRetriever.h \
#            $$PWD/src/houndify_sdk/GoldenRetriever/GoldenRetrieverPosixSockets.h \
#            $$PWD/src/houndify_sdk/HoundJSON/BuildInfoJSON.h \
#            $$PWD/src/houndify_sdk/HoundJSON/ClientMatchCommandJSON.h \
#            $$PWD/src/houndify_sdk/HoundJSON/ClientMatchJSON.h \
#            $$PWD/src/houndify_sdk/HoundJSON/ClientStateJSON.h \
#            $$PWD/src/houndify_sdk/HoundJSON/ClientVerticalStateJSON.h \
#            $$PWD/src/houndify_sdk/HoundJSON/CommandResultJSON.h \
#            $$PWD/src/houndify_sdk/HoundJSON/ConversationStateJSON.h \
#            $$PWD/src/houndify_sdk/HoundJSON/HoundMessageJSON.h \
#            $$PWD/src/houndify_sdk/HoundJSON/HoundPartialTranscriptJSON.h \
#            $$PWD/src/houndify_sdk/HoundJSON/HoundServerJSON.h \
#            $$PWD/src/houndify_sdk/HoundJSON/HoundUpdateJSON.h \
#            $$PWD/src/houndify_sdk/HoundJSON/RequestInfoJSON.h \
#            $$PWD/src/houndify_sdk/HoundRequester/build_info.h \
#            $$PWD/src/houndify_sdk/HoundRequester/HoundCloudRequester.h \
#            $$PWD/src/houndify_sdk/HoundRequester/HoundHMACSHA256.h \
#            $$PWD/src/houndify_sdk/HoundRequester/HoundRequester.h \
#            $$PWD/src/houndify_sdk/HoundRequester/HoundSharedDoneFlag.h \
#            $$PWD/src/houndify_sdk/HoundRequester/HoundUnixTimeStamp.h \
#            $$PWD/src/houndify_sdk/HTTP/URL.h \
#            $$PWD/src/houndify_sdk/JSON/JSONArrayGenerator.h \
#            $$PWD/src/houndify_sdk/JSON/JSONBooleanGenerator.h \
#            $$PWD/src/houndify_sdk/JSON/JSONCheckingHandler.h \
#            $$PWD/src/houndify_sdk/JSON/JSONCoreIntegerGenerator.h \
#            $$PWD/src/houndify_sdk/JSON/JSONDoubleGenerator.h \
#            $$PWD/src/houndify_sdk/JSON/JSONHandler.h \
#            $$PWD/src/houndify_sdk/JSON/JSONHoldingArrayGenerator.h \
#            $$PWD/src/houndify_sdk/JSON/JSONHoldingGenerator.h \
#            $$PWD/src/houndify_sdk/JSON/JSONIncrementalParse.h \
#            $$PWD/src/houndify_sdk/JSON/JSONIntegerGenerator.h \
#            $$PWD/src/houndify_sdk/JSON/JSONIntegerLowerBoundOnlyGenerator.h \
#            $$PWD/src/houndify_sdk/JSON/JSONIntegerRangeGenerator.h \
#            $$PWD/src/houndify_sdk/JSON/JSONIntegerUnboundRangeGenerator.h \
#            $$PWD/src/houndify_sdk/JSON/JSONNullGenerator.h \
#            $$PWD/src/houndify_sdk/JSON/JSONNumberGenerator.h \
#            $$PWD/src/houndify_sdk/JSON/JSONObjectGenerator.h \
#            $$PWD/src/houndify_sdk/JSON/JSONObjectValueGenerator.h \
#            $$PWD/src/houndify_sdk/JSON/JSONParallelGenerator.h \
#            $$PWD/src/houndify_sdk/JSON/JSONParse.h \
#            $$PWD/src/houndify_sdk/JSON/JSONRep.h \
#            $$PWD/src/houndify_sdk/JSON/JSONStringGenerator.h \
#            $$PWD/src/houndify_sdk/JSON/JSONWriter.h \
#            $$PWD/src/houndify_sdk/Numbers/OInteger.h \
#            $$PWD/src/houndify_sdk/ReferenceCounting/RCHandle.h \
#            $$PWD/src/houndify_sdk/ReferenceCounting/ReferenceCounted.h \
#            $$PWD/src/houndify_sdk/SalmonEye/i_integer.h \
#            $$PWD/src/houndify_sdk/SalmonEye/o_integer.h \
#            $$PWD/src/houndify_sdk/SalmonEye/platform_dependent.h \
#            $$PWD/src/houndify_sdk/SalmonEye/rational.h \
#            $$PWD/src/houndify_sdk/SalmonEye/source_location.h \
#            $$PWD/src/houndify_sdk/SalmonEye/unicode.h \
#            $$PWD/src/houndify_sdk/SampleCppClient/sample_hound_driver.h \
#            $$PWD/src/houndify_sdk/SampleCppClient/sample_hound_driver_system_dependent.h \
HEADERS += $$PWD/src/hound_driver.h \
           $$PWD/src/recorder.h

#SOURCES +=  $$PWD/src/houndify_sdk/GoldenRetriever/Fetch.cpp \
#            $$PWD/src/houndify_sdk/GoldenRetriever/FetchEnable.cpp \
#            $$PWD/src/houndify_sdk/GoldenRetriever/FetchLowLevelPosixSocketsNoScript.cpp \
#            $$PWD/src/houndify_sdk/HoundJSON/BuildInfoJSON.cpp \
#            $$PWD/src/houndify_sdk/HoundJSON/ClientMatchCommandJSON.cpp \
#            $$PWD/src/houndify_sdk/HoundJSON/ClientMatchJSON.cpp \
#            $$PWD/src/houndify_sdk/HoundJSON/ClientStateJSON.cpp \
#            $$PWD/src/houndify_sdk/HoundJSON/ClientVerticalStateJSON.cpp \
#            $$PWD/src/houndify_sdk/HoundJSON/CommandResultJSON.cpp \
#            $$PWD/src/houndify_sdk/HoundJSON/ConversationStateJSON.cpp \
#            $$PWD/src/houndify_sdk/HoundJSON/HoundMessageJSON.cpp \
#            $$PWD/src/houndify_sdk/HoundJSON/HoundPartialTranscriptJSON.cpp \
#            $$PWD/src/houndify_sdk/HoundJSON/HoundServerJSON.cpp \
#            $$PWD/src/houndify_sdk/HoundJSON/HoundUpdateJSON.cpp \
#            $$PWD/src/houndify_sdk/HoundJSON/RequestInfoJSON.cpp \
#            $$PWD/src/houndify_sdk/HoundRequester/build_info.cpp \
#            $$PWD/src/houndify_sdk/HoundRequester/HoundCloudRequester.cpp \
#            $$PWD/src/houndify_sdk/HoundRequester/HoundHMACSHA256.cpp \
#            $$PWD/src/houndify_sdk/HoundRequester/HoundRequester.cpp \
#            $$PWD/src/houndify_sdk/HoundRequester/HoundSharedDoneFlagSingleThreaded.cpp \
#            $$PWD/src/houndify_sdk/HoundRequester/HoundUnixTimeStampFromANSICTime.cpp \
#            $$PWD/src/houndify_sdk/JSON/JSONArrayGenerator.cpp \
#            $$PWD/src/houndify_sdk/JSON/JSONBooleanGenerator.cpp \
#            $$PWD/src/houndify_sdk/JSON/JSONCheckingHandler.cpp \
#            $$PWD/src/houndify_sdk/JSON/JSONDoubleGenerator.cpp \
#            $$PWD/src/houndify_sdk/JSON/JSONIncrementalParse.cpp \
#            $$PWD/src/houndify_sdk/JSON/JSONIntegerGenerator.cpp \
#            $$PWD/src/houndify_sdk/JSON/JSONNullGenerator.cpp \
#            $$PWD/src/houndify_sdk/JSON/JSONNumberGenerator.cpp \
#            $$PWD/src/houndify_sdk/JSON/JSONObjectGenerator.cpp \
#            $$PWD/src/houndify_sdk/JSON/JSONParallelGenerator.cpp \
#            $$PWD/src/houndify_sdk/JSON/JSONParse.cpp \
#            $$PWD/src/houndify_sdk/JSON/JSONRep.cpp \
#            $$PWD/src/houndify_sdk/JSON/JSONStringGenerator.cpp \
#            $$PWD/src/houndify_sdk/JSON/JSONWriter.cpp \
#            $$PWD/src/houndify_sdk/Numbers/OInteger.cpp \
#            $$PWD/src/houndify_sdk/c_foundations/buffer_print.c \
#            $$PWD/src/houndify_sdk/c_foundations/diagnostic.c \
#            $$PWD/src/houndify_sdk/c_foundations/memory_allocation.c \
#            $$PWD/src/houndify_sdk/c_foundations/memory_allocation_test.c \
#            $$PWD/src/houndify_sdk/c_foundations/merge_dense_integer_arrays.c \
#            $$PWD/src/houndify_sdk/c_foundations/print_formatting/bytewise_hex_pointer_conversion.c \
#            $$PWD/src/houndify_sdk/c_foundations/print_formatting/division_floating_point_conversion.c \
#            $$PWD/src/houndify_sdk/c_foundations/print_formatting/floating_point_output.c \
#            $$PWD/src/houndify_sdk/c_foundations/print_formatting/sprintf_floating_point_conversion.c \
#            $$PWD/src/houndify_sdk/c_foundations/print_formatting/sprintf_pointer_conversion.c \
#            $$PWD/src/houndify_sdk/c_foundations/print_formatting.c \
#            $$PWD/src/houndify_sdk/c_foundations/string_aam.c \
#            $$PWD/src/houndify_sdk/c_foundations/string_index.c \
#            $$PWD/src/houndify_sdk/c_foundations/trace.c \
#            $$PWD/src/houndify_sdk/SalmonEye/i_integer.c \
#            $$PWD/src/houndify_sdk/SalmonEye/o_integer.c \
#            $$PWD/src/houndify_sdk/SalmonEye/rational.c \
#            $$PWD/src/houndify_sdk/SalmonEye/source_location.c \
#            $$PWD/src/houndify_sdk/SalmonEye/unicode.c

# German translation is enabled as an example. If you aren't
# planning to localize your app, remember to comment out the
# following TRANSLATIONS line. And also do not forget to
# modify the localized app name in the the .desktop file.
TRANSLATIONS += translations/VoiceProject-de.ts

include(src/houndify_sdk/houndify.pri)

LIBS += -lcrypto -lssl
QT += multimedia network
