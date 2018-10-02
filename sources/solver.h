//
// @Author: Jxtopher
// @License: *
// @Date: 2018-10
// @Version: *
// @Purpose: *
// 

#ifndef SOLVER_H
#define	SOLVER_H

class Solver {
	public:
		Solver() {

		}
		virtual ~Solver() {
			
		}
		virtual void operator()() = 0;
};

#endif