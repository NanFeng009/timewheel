#include <stdio.h>
#include "time.hpp"
#include "mydog.hpp"
#include "time.hpp"

extern unsigned long getmilliseconds();
void mydog::dump()
{
    printf("mydog dump\n");
}

mydog::mydog(int interval)
{
    this->interval = interval;
    this->last_trigger = getmilliseconds();
}

bool mydog::run()
{
    getmilliseconds();

    unsigned long trigger_time = this->last_trigger + this->interval;

    // Check if either mydog has taken longer than expected to run,
    // and if so, warn that we are overloaded.
    if ( clock_tick > trigger_time ) {
        last_trigger = clock_tick;
        printf("be trigger and time is %lu \n", last_trigger);
    }

    setPaused(); // Return this task to a paused state
    return true;
}

// Returns the clock_tick when this task should next run
unsigned int mydog::wake()
{
    return last_trigger + interval;
}
