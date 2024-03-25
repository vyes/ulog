#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <sys/time.h>
#include <string.h>

#include "ulog.h"

static int debug = 0xff;

#define BUFSIZE 1024
static char buf[BUFSIZE];

void ulog_set_level(int lvl) {
	debug = lvl;
}
int ulog_get_level(void) {
	return debug;
}

void ulog(char f, const char *tgt, const char *fmt, ...) {
	int nb;
	struct timeval now;

	gettimeofday(&now, NULL);
	if (tgt == NULL) {
		nb = snprintf(buf, BUFSIZE, "%lu.%06lu (%c): %s\n", now.tv_sec, now.tv_usec, f, fmt);
	} else {
		nb = snprintf(buf, BUFSIZE, "%lu.%06lu (%c) [%s]: %s\n", now.tv_sec, now.tv_usec, f, tgt, fmt);
	}
	if (nb < 0 || (size_t)nb >= BUFSIZE) {
		return;
	}

	va_list ap;
	va_start(ap, fmt);
	vfprintf(stderr, buf, ap);
	va_end(ap);
}

void dlog(int lvl, const char *tgt, const char *fmt, ...) {
	int nb;
	struct timeval now;

	if(lvl > debug) return;

	gettimeofday(&now, NULL);
	if (tgt == NULL) {
		nb = snprintf(buf, BUFSIZE, "%lu.%06lu (D%d): %s\n", now.tv_sec, now.tv_usec, lvl, fmt);
	} else {
		nb = snprintf(buf, BUFSIZE, "%lu.%06lu (D%d) [%s]: %s\n", now.tv_sec, now.tv_usec, lvl, tgt, fmt);
	}
	if (nb < 0 || (size_t)nb >= BUFSIZE) {
		return;
	}

	va_list ap;
	va_start(ap, fmt);
	vfprintf(stderr, buf, ap);
	va_end(ap);
}
