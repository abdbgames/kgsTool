#ifndef SYS_TIME_H
#ifdef _WIN32
#define SYS_TIME_H
#include <windows.h>
#include <time.h>
typedef struct timespec {
	time_t tv_sec;
	long tv_nsec;
} timespec_t;
#endif
#endif /* SYS_TIME_H */