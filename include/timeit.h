#ifndef TIMEIT_H
#define TIMEIT_H

#include <time.h>

#ifdef CLOCK_PROCESS_CPUTIME_ID
/* cpu time in the current process */
#define CLOCKTYPE CLOCK_PROCESS_CPUTIME_ID
#else
/* this one should be appropriate to avoid errors on multiprocessors systems */
#define CLOCKTYPE CLOCK_MONOTONIC
#endif

/* s is the cost time, cb is the callback function
 * usage:
 * TIMEIT(s, sum2, a, b);
 * printf("sum2 takes %lf s\n", s);
 **/
#define TIMEIT(s, cb, ...)	double s;\
							do {\
								struct timespec tsi, tsf;\
								clock_gettime(CLOCKTYPE, &tsi);\
								cb(__VA_ARGS__);\
								clock_gettime(CLOCKTYPE, &tsf);\
								double elaps_s = difftime(tsf.tv_sec, tsi.tv_sec);\
								long elaps_ns = tsf.tv_nsec - tsi.tv_nsec;\
								s = elaps_s + ((double)elaps_ns) / 1.0e9;\
							} while (0)


static double time_it(int (*action)(int), int arg)
{
    struct timespec tsi, tsf;

    clock_gettime(CLOCKTYPE, &tsi);
    action(arg);
    clock_gettime(CLOCKTYPE, &tsf);

    double elaps_s = difftime(tsf.tv_sec, tsi.tv_sec);
    long elaps_ns = tsf.tv_nsec - tsi.tv_nsec;
    return elaps_s + ((double)elaps_ns) / 1.0e9;
}

#endif
