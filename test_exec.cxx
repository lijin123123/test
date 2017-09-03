#include <unistd.h>
#include <iostream>
#include <vector>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
int main()
{
	char* init_env[]={"LOG=/tmp/lijin","filename=hh",NULL};
	int status;
	const pid_t child_id =fork();
	if(child_id == 0)
	{
		const char* pathname="/bin/sh";
		if(execle(pathname,"sh","/tmp/lijin/test_exec.sh","lijin","want",(char*)0,init_env)<0)
		{
			std::cout<<errno<<strerror(errno)<<std::endl;
		}	
	}
	else
	{
		pid_t pid=waitpid(child_id,&status,0);
		if(WIFEXITED(status))
		{
			int exit_status = WEXITSTATUS(status);
			return exit_status;
		}
		else
		{
			return WEXITSTATUS(status);
		}
	}
}
