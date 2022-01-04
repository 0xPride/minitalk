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

![image](https://github.com/project-HOSSAM/minitalk/img/sgina-delevery-and-handle-excution.png)

sigint handler example
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
