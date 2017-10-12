#ifndef __TIME__
#define __TIME__
extern unsigned long getmilliseconds();
extern unsigned long long getmicroseconds();
void sipp_usleep(unsigned long usec);

extern unsigned long clock_tick;


#endif
