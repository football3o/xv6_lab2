#include "types.h"
#include "user.h"

int main(int argc, char *argv[])
{
	
	int PScheduler(void);
	int aging(void);

  printf(1, "\n This program tests the correctness of your lab#2\n");
  if (atoi(argv[1]) == 1)
	PScheduler();
	else if (atoi(argv[1]) == 2)
	aging();
	else 
	 printf(1, "\ntype \"lab2_test 1\" to test priority scheduling, \"lab2_test 2\" to test aging \n");
	return 0;
 }
  
    
int PScheduler(void){
		 
    // use this part to test the priority scheduler. Assuming that the priorities range between range between 0 to 31
    // 0 is the highest priority and 31 is the lowest priority.  

  int pid;
  int i,j,k;
  
    printf(1, "\n  Step 2: testing the priority scheduler and setpriority(int priority)) systema call:\n");
    printf(1, "\n  Step 2: Assuming that the priorities range between range between 0 to 31\n");
    printf(1, "\n  Step 2: 0 is the highest priority. All processes have a default priority of 10\n");
    printf(1, "\n  Step 2: The parent processes will switch to priority 0\n");
    setpriority(0);
    for (i = 0; i <  3; i++) {
	pid = fork();
    printf(1, "\n  new pid = %d \n",pid);
	if (pid > 0 ) {
		continue;}
	else if ( pid == 0) {

		setpriority(30-10*i);	
		for (j=0;j<50000;j++) {
			for(k=0;k<1000;k++) {
				asm("nop"); }}
		printf(1, "\n child# %d with priority %d has finished! \n",getpid(),30-10*i);		
		exit();
        }
        else {
			printf(2," \n Error \n");
			
        }
	}

	if(pid > 0) {
		for (i = 0; i <  3; i++) {
			wait();

		}
                     printf(1,"\n if processes with highest priority finished first then its correct \n");
    }
	exit();		
	return 0;
}

int aging(void){
	int pid;
  int i,j,k;
	 setpriority(0);
    for (i = 0; i <  3; i++) {
	pid = fork();
    printf(1, "\n  new pid = %d \n",pid);
	if (pid > 0 ) {
		continue;}
	else if ( pid == 0) {

		setpriority(30-10*i);	
		for (j=0;j<50000;j++) {
			for(k=0;k<1000;k++) {
				asm("nop"); }}
		printf(1, "\n child# %d with initial priority %d has finished! \n",getpid(),30-10*i);	
		printf(1, "\n child# %d with new priority %d has finished! \n",getpid(),getpriority());	
		exit();
        }
        else {
			printf(2," \n Error \n");
			
        }
	}

	if(pid > 0) {
		printf(1, "\n Parent %d with initial priority %d \n",getpid(),getpriority());
		for (i = 0; i <  3; i++) {
			wait();
		}
		printf(1, "\n Parent %d with new priority %d \n",getpid(),getpriority());
        printf(1,"\n if processes with highest priority finished first then its correct \n");
    } 
	exit();
	return 0;
}