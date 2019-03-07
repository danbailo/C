#include<stdio.h>
#include <time.h>
struct timespec TIMER_START,TIMER_END;
long unsigned int timer(int f){
	if(f){
		clock_gettime(CLOCK_MONOTONIC_RAW, &TIMER_START);
		return 0;  
	}
	clock_gettime(CLOCK_MONOTONIC_RAW, &TIMER_END);
	return (TIMER_END.tv_sec - TIMER_START.tv_sec) * 1000000000 + (TIMER_END.tv_nsec - TIMER_START.tv_nsec);
}
int main(){
	timer(1);//start
	for(int i=0;i<10000000;i++);
	printf("operation took %lu nanoseconds\n",timer(0)); //end
	return 0;
}