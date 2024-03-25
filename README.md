# ulog

ulog.h:
```C
void ulog_set_level(int lvl);
int ulog_get_level(void);

void ulog(char f, const char *tgt, const char *fmt, ...);
void dlog(int lvl, const char *tgt, const char *fmt, ...);

#define INFO(...) ulog('I', NULL, __VA_ARGS__)
#define ERR(...) ulog('E', NULL, __VA_ARGS__)
#define WARN(...) ulog('W', NULL, __VA_ARGS__)
#define D(lvl, ...) dlog(lvl, NULL, __VA_ARGS__)

#define ULOG_INFO(tgt, ...) ulog('I', tgt, __VA_ARGS__)
#define ULOG_ERROR(tgt, ...) ulog('E', tgt, __VA_ARGS__)
#define ULOG_WARNING(tgt, ...) ulog('W', tgt, __VA_ARGS__)
#define ULOG_DEBUG(lvl, tgt, ...) dlog(lvl, tgt, __VA_ARGS__)
```
