//#include <cstdio.h>
#include <iostream>
int main()
{
std::cout<<"cout";    //terminal display: cout stream have a buffer, flush 
std::cerr<<"error"<<std::endl;   // output the error immediately
std::clog<<"log"<<std::endl;   //same as error stream ,but when the buffer is full then display the log(same as the cout stream in this point) 
}
