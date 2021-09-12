#include <sys/types.h> 
#include <stdlib.h> 
#include <stdio.h> 
#include <unistd.h> 
#include <sys/wait.h> 

int main(int argc,char **argv) 
{ 
char *argp[3]; /* for print_pid args */ 
char arglevel[10]; 
int status, degree, height, 
level, children; 
int i; 
pid_t *pids; 
pid_t pid; 

if( argc < 3 ) 
{ 
printf("usage: degree[int] height[int]\n"); 
exit(1); 
} 
else { 
degree = atoi(argv[1]); 
height = atoi(argv[2]);
 
if (argc == 3) /* Root is at height 0 */ 
level = 1; 
else 
level = atoi(argv[2]); 
} 

for ( i = 0; i < degree; i++ ) 
{ 
pids = (pid_t *) 
malloc(sizeof(pid_t)); 
} 

for ( i = 0; i < 2; i++ ) 
{ 
argp[i] = (char *) 
malloc(sizeof(char)*10); 
} 

/* Fill in argp for print_pid */ 
sprintf(argp[0],"%s","print_pid"); 
sprintf(argp[1],"%d",level); 
argp[2] = NULL; 

/* for leaf nodes */ 
if ( level == height ) 
{ 
sprintf(argp[1],"%d",level); 
execv("print_pid",argp); 
return 0; 
} 

/* Fill in argv for process_tree */ 
sprintf(argv[0],"%s","process_tree"); 
sprintf(arglevel,"%d",level+1); 
argv[3] = arglevel; 
argv[4] = NULL; 

/* for others */ 
for ( i = 0; i < degree; i++ ) { 

/* Fork error */ 
if((pid = fork()) < 0) 
{ 
printf("Error in forking...\n"); 
exit(1); 
}
 
/* Child */ 
else if ( pid == 0 ) { 
execv("process_tree",argv);
 
/* the following code is only executed if the above execv fails */ 
perror("execv"); 
exit(EXIT_FAILURE); 
} 

/* Parent */ 
else { 
continue; 
}
 
} 
/* Parent */
 
/*WHAT TO DO*/ 

execv("print_pid", argp); 
/* the following code is only executed if the above execv fails */ 
perror("execv"); 
exit(EXIT_FAILURE); 
return 1; 
} 

/****************/ 
/* print_pid.c */ 
/**************/ 
#include <unistd.h> 
#include <sys/types.h> 
#include <stdio.h> 

int main(int argc,char ** argv) 
{ 
printf("Process %d from level %d is terminating...\n",getpid(),atoi(argv[1])); 
return; 
}
 
Some outputs 
$ ./process_tree 4 5 
Process 5858 from level 5 is terminating... 
Process 5859 from level 5 is terminating... 
Process 5860 from level 5 is terminating... 
Process 5856 from level 1 is terminating... 
Process 5857 from level 5 is terminating... 

./process_tree 6 7 
Process 5874 from level 7 is terminating... 
Process 5875 from level 7 is terminating... 
Process 5876 from level 7 is terminating... 
Process 5877 from level 7 is terminating... 
Process 5879 from level 7 is terminating... 
Process 5873 from level 1 is terminating... 
$ Process 5878 from level 7 is 
terminating... 
