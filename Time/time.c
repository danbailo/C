#include <stdio.h>

#include <sys/time.h>
#include <time.h>


struct timespec TIMER_START, TIMER_END;
long unsigned int timer(int f){
    if(f){
        clock_gettime(CLOCK_MONOTONIC_RAW, &TIMER_START);
        return 0;  
    }
    clock_gettime(CLOCK_MONOTONIC_RAW, &TIMER_END);
    return (TIMER_END.tv_sec - TIMER_START.tv_sec) * 1000000 + (TIMER_END.tv_nsec - TIMER_START.tv_nsec) / 1000;
}

int main(int argc, char const *argv[]){
	
	timer(1);
    sleep(1);
    printf("%lu\n",timer(0));

	return 0;
}