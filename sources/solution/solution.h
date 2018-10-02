//
// @Author: Jxtopher
// @License: *
// @Date: 2018-10
// @Version: *
// @Purpose: *
// 

#ifndef SOLUTION_H
#define SOLUTION_H

#include <cassert>
#include "../macro.h"

template<typename TYPE_FITNESS>
class Solution {
	public:
		Solution(Solution const & s) :
			_numberOfObjective(s._numberOfObjective) {
			DEBUG_TRACE("Constructeur de copie Solution");
			_fitness = new TYPE_FITNESS[_numberOfObjective];
			_fitnessIsValid = new bool[_numberOfObjective];
			for(unsigned int i = 0 ; i < _numberOfObjective ; i++) {
				_fitness[i] = s._fitness[i];
				_fitnessIsValid[i] = s._fitnessIsValid[i];
			}
		}
		
		Solution(unsigned int const numberOfObjective): 
			_numberOfObjective(numberOfObjective) {
			DEBUG_TRACE("Creation Solution");
			_fitness = new TYPE_FITNESS[_numberOfObjective];
			_fitnessIsValid = new bool[_numberOfObjective];
			for(unsigned int i = 0 ; i < _numberOfObjective ; i++)
				_fitnessIsValid[i] = false;
		}
		
		Solution & operator=(Solution const & s) {
			if (_numberOfObjective != s._numberOfObjective) {
				this->~Solution();
				_numberOfObjective = s._numberOfObjective;
				_fitness = new TYPE_FITNESS[_numberOfObjective];
				_fitnessIsValid = new bool[_numberOfObjective];
				for(unsigned int i = 0 ; i < _numberOfObjective ; i++)
					_fitnessIsValid[i] = false;
			}
			
			for(unsigned int i = 0 ; i < _numberOfObjective ; i++) {
				_fitness[i] = s._fitness[i];
				_fitnessIsValid[i] = s._fitnessIsValid[i];
			}
			return *this;
		}
		
		~Solution() {
			DEBUG_TRACE("Delete Solution");
			delete [] _fitness;
			delete [] _fitnessIsValid;
		}
		
		bool fitnessIsValid(unsigned int numObjectif) const {
			assert(numObjectif < _numberOfObjective);
			return _fitnessIsValid[numObjectif];	
		}
		
		void fitness(unsigned int numObjectif, TYPE_FITNESS value) {
			assert(numObjectif < _numberOfObjective);
			_fitness[numObjectif] = value;
			_fitnessIsValid[numObjectif] = true;
		}
		
		TYPE_FITNESS fitness(unsigned int numObjectif) const {
			assert(numObjectif < _numberOfObjective);
			return _fitness[numObjectif];
		}

		unsigned int numberOfObjective() const {
			return _numberOfObjective;
		}
		

	protected:
		unsigned int _numberOfObjective;
		TYPE_FITNESS *_fitness;
		bool *_fitnessIsValid;
};


#endif
