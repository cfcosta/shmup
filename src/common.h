#ifndef H_COMMON
    #define H_COMMON
    
    #include <signal.h>

    int quit = 0;
    void catch_signal(int signal)
    {
        quit = 1;
    }
#endif
