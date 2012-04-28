#include <stdio.h>



//preprocessed definitions of structs from libev3 ev.h


//dummy struct, only for compile
typedef struct ev_loop
{
  int dummy;
} ev_loop;


typedef double ev_tstamp;


//base "watcher struct"
typedef struct ev_watcher
{
  int active; int pending; int priority; void *data;
  void (*cb)(struct ev_loop *loop, struct ev_watcher *w, int revents);
} ev_watcher;


//inherited "watcher list"
typedef struct ev_watcher_list
{
  int active; int pending; int priority; void *data;
  void (*cb)(struct ev_loop *loop, struct ev_watcher_list *w, int revents);
  struct ev_watcher_list *next;
} ev_watcher_list;



//struct with no aliasing warning
typedef struct ev_io_good
{
  ev_watcher watcher;
  struct ev_watcher_list *next;

  int fd;
  int events;
} ev_io_good;


//original struct with warning
typedef struct ev_io
{
  int active; int pending; int priority; void *data;
  void (*cb)(struct ev_loop *loop, struct ev_io *w, int revents);
  struct ev_watcher_list *next;

  int fd;
  int events;
} ev_io;



int main (int argc, char **argv)
{
    ev_io watcher;
    ev_io_good watcherg;

    //warning
    ((ev_watcher *) (void *) (&watcher))->active=17;

    printf("active (warning):%d\n",watcher.active);


    //no warning
    ((ev_watcher *) (void *) (&watcherg))->active=42;
    printf("active (no warning):%d\n",watcherg.watcher.active);
    return 0;
}
