# Signals
A signal is a notification to a process that an event has occurred. Signals are sometimes described as software interrupts.

Signals are analogous to hardware interrupts in that they interrupt the normal flow of execution of a program; in most cases, it is

not possible to predict exactly when a signal will arrive.

## How a signal is generated ?

- hardware exepstions (malformed machine-language instruction, deviding by zero ...)
- terminal generated signals (Controll-C ...)
- a software events happen (timer went off, child process terminated ...)

## Signal actions

upon delevery of a signal, a process carries one of the followig default actions

- a signal is ignored, that is declaired by the kernerl
- a process is terminated, this is referd to as abnormal process termination
- a core dump file is generated and the process is terminated
- the process is stopped excution
- proces is resumed

## Signal dispositions

a program can change the default actions cused by a signal with the following dispositions

- the default action
- the signal is ignored
- a signal handler is excuted

```c
void (*signal(int sig, void (*func)(int)))(int); // return previous signal disposition or SEG_ERR on error
```
## Signal handlers

A signal handler is a function that is called when a specified signal is delivered to a process.

invocation of a handler may stop the main program at ny time and then the kernerl calls the handler on behalf of the process and then when the handler
returns the excution of program resumed

![image](img/sgina-delevery-and-handle-excution.png)

sigint handler example:
```c
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void handler(int sig) {
 printf("Boom!\n");
}

int main()
{
 if (signal(SIGINT, handler) == SIG_ERR)
 	exit(0);

 for (int j = 0; ; j++) {
 	printf("%d\n", j);
 	sleep(1);
 }
}
```

## Send Signals

a process can send signals with the kill() system call

```
int kill(pid_t pid, int sig); // return 0 on success otherwise return -1
```

- pid > 0 -> the signal is sent to the specified signal pid
- pid = 0 -> the signal is sent to every process in same process group including the calling process
- pdi = -1 -> the signal is sent to every process which the calling process have permission to except itself
- pid < -1 -> the signala is sent to all processes in the process group whos id equal to |pid|

## Process permissions

- CAP_KILL can send a signal to every process
- the init process (ID = 1) can only resive signals
- unprivilaged process can send signals only if the user id of the sending process is equal to 
- SIGCONT is a special signal that a unprivilage process can send it to any other process in the same session

## Cheking if a process exists

if we pass 0 signal to kill system call it merely do error cheking to see if a process can be signaled.
if kill system call faild with the ESRCH error then the signal doesn't exist, if the error is EPERM then we dont have permission to signal that process and if it succeeds then the process exists and can be signaled

## Signal sets

many system calls need a singal group as an argument
```c
int sigempyset(sigset_t *set); // initialize an empy signal set
int sigfillate(sigset_t *set); // initialize a singal set with all signals

```

we can add/remove a signal from a set
```c
int sigaddset(sigset_t *set, int signo); // add a signal to signal set
int sigdelset(sigset_t *set, int signo); // delete a signal from a signal set
```

we can check if a signal in a set
```c
int sigismember(const sigset_t *set, int signo);
```

## Signal mask
For each process, the kernel maintains a signal mask—a set of signals whose delivery to the process is currently blocked.
If a signal that is blocked is sent to a process, delivery of that signal is delayed until it is unblocked by being removed from the
process signal mask.

we can add a signal to the signal mask set by:
-  When a signal handler is invoked, the signal that caused its invocation can be
automatically added to the signal mask
- When a signal handler is established with sigaction(), it is possible to specify an
additional set of signals that are to be blocked when the handler is invoked.
- The sigprocmask() system call can be used at any time to explicitly add signals to,
and remove signals from, the signal mask
```c
int sigprocmask(int how, const sigset_t *set, sigset_t *oset);
```
we can pass the how argument the following
- SIG_BLOCK The signals specified in the signal set pointed to by set are added to the signal mask. In other words, the signal mask is set to the union of its current
value and set.
- SIG_UNBLOCK The signals in the signal set pointed to by set are removed from the signal
mask. Unblocking a signal that is not currently blocked doesn’t cause an
error to be returned.
- SIG_SETMASK The signal set pointed to by set is assigned to the signal mask.

## Pending signals

If a process receives a signal that it is currently blocking, that signal is added to the
process’s set of pending signals. When (and if) the signal is later unblocked, it is
then delivered to the process, we can get the currenlty pending signals with the following:
```c
int sigpending(sigset_t *set);
```
## Interprocess communication (IPC)

rom one viewpoint, we can consider signals as a form of interprocess communication (IPC). However, signals suffer a number of limitations as an IPC mechanism. First, by comparison with other methods of IPC that we examine in later chapters, program- ming with signals is cumbersome and difficult. The reasons for this are as follows:
- The asynchronous nature of signals means that we face various problems, including reentrancy requirements, race conditions, and the correct handling of global variables from signal handlers. (Most of these problems do not occur if we are using sigwaitinfo() or signalfd() to synchronously fetch signals.)
- Standard signals are not queued. Even for realtime signals, there are upper limits on the number of signals that may be queued. This means that in order to avoid loss of information, the process receiving the signals must have a method of informing the sender that it is ready to receive another signal. The most obvious method of doing this is for the receiver to send a signal to the sender.

## Signal handlers

If a process receives a signal, the process has a choice of action for that kind of signal. The process can ignore the signal, can specify a handler function, or accept the default action for that kind of signal