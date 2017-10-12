#include "main.hpp"
#include <list>
#include <stdio.h>
#include "mydog.hpp"


#define _DEFVAL(value) = value
unsigned long scheduling_loops             _DEFVAL(0);
unsigned long last_timer_cycle             _DEFVAL(0);

unsigned long watchdog_interval            _DEFVAL(2000);
unsigned long watchdog_minor_threshold     _DEFVAL(500);
unsigned long watchdog_minor_maxtriggers   _DEFVAL(120);
unsigned long watchdog_major_threshold     _DEFVAL(3000);
unsigned long watchdog_major_maxtriggers   _DEFVAL(10);
unsigned long watchdog_reset               _DEFVAL(600000);


int main(int argc, char *argv[])
{
    int max_sched_loops = 1000;

    mydog * mydog1 = new mydog(watchdog_interval);

    int loops = max_sched_loops;

    task_list *running_tasks;
    /* Now we process calls that are on the run queue. */
    running_tasks = get_running_tasks();

    task * last = NULL;

    printf("Start to run ... \n");
    task_list::iterator iter;
    while(1){
        for(iter = running_tasks->begin(); iter != running_tasks->end(); iter++) {
            if (last) {
                last -> run();
                printf("run the %d times.", max_sched_loops - loops);
            }
            last = *iter;
        }
        if(last){
            last -> run();
        }
    }
}
