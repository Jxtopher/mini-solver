//
// @Author: Jxtopher
// @License: *
// @Date: 2018-10
// @Version: *
// @Purpose: *
// 

#ifndef FIRSTIMPROVEMENT_H
#define FIRSTIMPROVEMENT_H

#include <random>

#include "optimizationAlgorithm.h"
#include "../problem/evaluation.h"

using namespace std;

template<class SOL>
class FirstImprovement : public OptimizationAlgorithm<SOL> {
    public:
    FirstImprovement(unsigned int N, unsigned int buget) : _buget(buget) {
        mt_rand.seed(static_cast<unsigned long int>(time(0)));
        rid = new uniform_int_distribution<unsigned int>(0, N-1);
    }

    ~FirstImprovement() {
        delete rid;
    }
    
    void operator()(SOL &s, Evaluation<SOL> &e) { 
        if (!s.fitnessIsValid(0)) {
            e.full(s);
        }

        unsigned int i = 0;
        while (i < _buget || s.fitness(0) < s.sizeArray()) {
            unsigned int fitnessBefore = s.fitness(0);
            

            #ifdef DEBUG
            cout<<s.fitness(0)<<" ";
            s.show();
            #endif

            unsigned int ret = rid->operator()(mt_rand);

            if (s(ret) == 1) 
                s(ret, 0);
            else 
                s(ret, 1);

            e.full(s);

            if (fitnessBefore > s.fitness(0)) {
                if (s(ret) == 1) 
                    s(ret, 0);
                else 
                    s(ret, 1);
            }

            e.full(s);

            i++;
        }

        
        #ifdef DEBUG
        cout<<s.fitness(0)<<" ";
        s.show();
        #endif
        
    }

    protected:
        unsigned int _buget;
        mt19937 mt_rand;
        uniform_int_distribution<unsigned int> *rid;
};

#endif