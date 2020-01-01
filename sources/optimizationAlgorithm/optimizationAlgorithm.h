//
// @Author: Jxtopher
// @License: *
// @Date: 2018-10
// @Version: *
// @Purpose: *
// test

#ifndef OPTIMIZATIONALGORITHM_H
#define OPTIMIZATIONALGORITHM_H

template<class SOL>
class OptimizationAlgorithm {
    public:
        OptimizationAlgorithm() {

        }
        virtual ~OptimizationAlgorithm() {

        }
    
        virtual void operator()(SOL &s, Evaluation<SOL> &e) = 0;


    private:

};

#endif