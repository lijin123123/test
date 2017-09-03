#include <iostream>
#include <string>
struct info
{
	char log[100];
};
void log_c( const char* l)
{
	std::cout<<l<<std::endl;
	char p[100];
        p=l;
	info i;
	i.log=p;
	std::cout<<i.log<<std::endl;
}
int main()
{
        std::string jj="hello";
         
	log_c(jj.c_str());
}
