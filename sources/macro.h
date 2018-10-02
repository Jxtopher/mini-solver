//
// @Author: Jxtopher
// @License: *
// @Date: 2018-10
// @Version: *
// @Purpose: Macro
// 

#ifndef MACRO_H
#define MACRO_H

#include <sstream>
#include <iostream>
#include <stdexcept>

#ifdef DEBUG
#define DEBUG_TRACE(msg) std::cerr<<"[+] "<<__FILE__<<":"<<__LINE__<<" "<<msg<<std::endl;	
#define DEBUG_VAR(variable) std::cerr<<"[+] "<<__FILE__<<":"<<__LINE__<<" "<<#variable << " = " << (variable) << std::endl;
#else
#define	DEBUG_TRACE(msg) 
#define DEBUG_VAR(variable)
#endif



#define THROW(msg) {std::ostringstream ss;\
			ss << __FILE__<<":"<<__LINE__<<":"<<msg;\
			throw std::logic_error(ss.str());}



#endif

