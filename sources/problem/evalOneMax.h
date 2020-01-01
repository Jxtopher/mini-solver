//
// @Author: Jxtopher
// @License: *
// @Date: 2018-10
// @Version: *
// @Purpose: *
// 

#ifndef EVALONEMAX_H
#define EVALONEMAX_H

#include "../solution/solutionArray.h"
#include "evaluation.h"

template<class SOL>
class EvalOneMax : public Evaluation<SOL> {
    public:
    
    EvalOneMax() {

    }
    
    virtual ~EvalOneMax() {

    }

    void full(SOL &s) {
        unsigned int sum = 0;
        for (unsigned int i = 0 ; i < s.sizeArray() ; i++) {
            sum += s(i);
        }

        s.fitness(0, sum);
    }

    /*void incremental(SolutionArray const &s) const {

    }*/

    private:
};

#endif