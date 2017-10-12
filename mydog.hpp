#ifndef __MYDOG__
#define __MYDOG__

#include "task.hpp"

class mydog : public task
{
    public:
        unsigned int wake();
        mydog(int interval);
        bool run();
        void dump();
    private:
        int interval;
        unsigned long last_trigger;
};


#endif
