#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#define TOTAL_FORK 5
int main(){
	pid_t pids[TOTAL_FORK], pid;
	int runProcess = 0;
	int state;
	while(runProcess < TOTAL_FORK){
		pids[runProcess] = fork();
		if(pids[runProcess] < 0){
			printf("Error in Process : %d\n",runProcess);
			return -1;
		}else if(pids[runProcess] == 0){
			// Child Process
			printf("Child %ld\n",(long)getpid());
			sleep(5);
			exit(0);
		}else{
			// Parent Process
			printf("Parent %ld, child %ld, runProcess: %d\n",(long)getpid(),(long)pids[runProcess],runProcess);
		}
		runProcess++;
	}
	return 0;
}
