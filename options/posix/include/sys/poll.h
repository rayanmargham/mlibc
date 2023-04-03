#ifndef _SYS_POLL_H
#define _SYS_POLL_H

#include <bits/types.h>
#include <bits/sigset_t.h>
#include <bits/ansi/timespec.h>
#include <abi-bits/poll.h>
#include <abi-bits/signal.h>
#include <mlibc-config.h>

typedef __mlibc_size nfds_t;

#ifdef __cplusplus
extern "C" {
#endif

struct pollfd {
	int fd;
	short events;
	short revents;
};

int poll(struct pollfd *, nfds_t, int);

#if __MLIBC_LINUX_OPTION
int ppoll(struct pollfd *fds, nfds_t nfds, const struct timespec *timeout_ts, const sigset_t *sigmask);
#endif // __MLIBC_LINUX_OPTION

#ifdef __cplusplus
}
#endif

#endif // _SYS_POLL_H
