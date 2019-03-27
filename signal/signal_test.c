#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <setjmp.h>

jmp_buf buf;
void handler(int sig);
int main(int argc, char const *argv[])
{
    printf("start %s\n", __func__);
    if (SIG_ERR == signal(SIGALRM, handler))
    {
        printf("failed to set signal handler.\n");
    }
    if (setjmp(buf) == 0)
    {
        printf("publish abort\n");
    }
    alarm(5);
    while (1)
    {
    }

    return 0;
}

void handler(int sig)
{
    printf("catch signal  : %d\n", sig);
    if (sig == SIGALRM)
    {
        /* code */
        printf("exit");
        //exit(1);
    }
    longjmp(buf, 1);
}