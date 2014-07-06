#ifndef TARGET_H
#define TARGET_H

#ifdef _WIN32
    #include <winsdkver.h>
    #define _WIN32_WINNT 0x0501
    #include <sdkddkver.h>
#endif

#endif // TARGET_H
