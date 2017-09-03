#include <unistd.h>
#include <sys/times.h>
#include <iostream>
#include <cstdlib>
#include <sys/errno.h>
#include <string.h>
#include <iomanip>
int main()
{
	char* init_env[]={"LOG=/tmp/lijin","filename=hh",NULL};
	int sc_clk_tck;
	sc_clk_tck = sysconf(_SC_CLK_TCK);
	
	struct tms begin_tms,end_tms;
	clock_t begin,end;
	system("date");
	begin = times(&begin_tms);
	pid_t child_pid =fork();
	if(child_pid == 0)
	{
		const char* pathname = "/bin/sh"; 
		sleep(1);
		if(execle(pathname,"sh","/tmp/lijin/test_exec.sh","lijin","want",(char*)0,init_env)<0)
		{
			std::cout<<errno<<strerror(errno)<<std::endl;
		}
			
	}
	else
	{
	sleep(3);
	end = times(&end_tms);
        }

        std::cout<<std::setprecision(8)<<"real time"<<(double)(end-begin)/(double)sc_clk_tck<<std::endl;
	std::cout<<std::setprecision(8)<<"user time"<<std::setprecision(8)<<(double)((end_tms.tms_utime - begin_tms.tms_utime))<<std::endl;
	std::cout<<std::setprecision(8)<<"sys time"<<(end_tms.tms_stime - begin_tms.tms_stime)/(double)sc_clk_tck<<std::endl;
	std::cout<<std::setprecision(8)<<"child user time"<<(end_tms.tms_cutime - begin_tms.tms_cutime)/(double)sc_clk_tck<<std::endl;
	std::cout<<std::setprecision(8)<<"child sys time"<<(end_tms.tms_cstime - begin_tms.tms_cstime)/(double)sc_clk_tck<<std::endl;
}


