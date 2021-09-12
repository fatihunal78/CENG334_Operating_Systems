#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc,char **argv)
{

char *args[3];
int level,child;
int status;
int i;
pid_t pid;

level = atoi(argv[1]);
child = atoi(argv[2]);

args[0]=malloc(sizeof(char)*10);
args[1]=malloc(sizeof(char)*10);

for ( i = 0; i < child; i++ )
{
	if(level > 0)
	{
		do
		{
		pid = fork();                                                                                                                }
		while(pid<0);                                                                                                                             
		if ( pid == 0 )
		{
		i=-1;
		level--;
		continue;
		}                                                                                                                                                                                                                                         
		else if (pid > 0);

		else
		{
		printf("error!\n");
		}
	} else break;

}

if (level > 0)
{
	for(i=0 ; i<child ; i++)
	{
	wait(&status);
	}
}

for(i=0; i<10; i++) 
{ 
        args[0][i] = '\0'; 
        args[1][i] = '\0'; 
} 

sprintf(args[0],"%d",getpid());
sprintf(args[1],"%d",level);
args[2]=NULL;

if(level>0)
execv("print_pid", args);

return 0;

}
