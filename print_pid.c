#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>
                                                                                                                             
int main(int argc,char **argv)
{

	printf("Process %s from level %s is terminating...\n",argv[0],argv[1]);

return 0;
}
