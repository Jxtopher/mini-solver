//
// @Author: Jxtopher
// @License: *
// @Date: 2018-10
// @Version: *
// @Purpose: *
// 

#ifndef SOLVERONEMAX_H
#define	SOLVERONEMAX_H

#include "solver.h"


#include "problem/evalOneMax.h"
#include "optimizationAlgorithm/firstImprovement.h"


class SolverOneMax : public Solver {
    public:

    SolverOneMax() {

    }
    ~SolverOneMax() {

    }

    void operator()() {
	unsigned int N = 100;
	SolutionArray<unsigned int, bool> s(1, N);
	
	EvalOneMax<SolutionArray<unsigned int, bool> > eOneMax;

	FirstImprovement<SolutionArray<unsigned int, bool> > algoFI(N, 400);

	algoFI(s, eOneMax);
    }

    private:

};

#endif
