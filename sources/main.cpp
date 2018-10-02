//
// @Author: Jxtopher
// @License: *
// @Date: 2018-10
// @Version: *
// @Purpose: *
// 

#include <iostream>
#include <cstdlib>

#include "macro.h"

#include "solverOnemax.h"


using namespace std;

void version(string name_software, string num_version);

void version(string name_software, string num_version) {
	std::cout<<"*************************************"<<std::endl;
	std::cout<<"[+] *** "<<name_software<<" ***"<<std::endl;
	std::cout<<"[+] Day compilation : "<<__DATE__<<" "<<__TIME__<<std::endl;
	std::cout<<"[+] Version : "<<num_version<<std::endl;
	std::cout<<"*************************************"<<std::endl;
}

int main(int argc, char **argv, char **envp) {

	DEBUG_TRACE("Start of the program")

	SolverOneMax sOneMax;
	sOneMax();


	DEBUG_TRACE("Stop program")
	return EXIT_SUCCESS;
}
