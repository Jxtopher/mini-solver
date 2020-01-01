//
// @Author: Jxtopher
// @License: *
// @Date: 2018-10
// @Version: *
// @Purpose: *
// 

#ifndef SOLUTIONARRAY_H
#define SOLUTIONARRAY_H

#include "solution.h"

template<typename TYPE_FITNESS, typename TYPE_SOL>
class SolutionArray : public Solution<TYPE_FITNESS> {
public:
	SolutionArray(unsigned int const numberOfObjective, unsigned int const sizeArray) : 
	Solution<TYPE_FITNESS>(numberOfObjective),
	_sizeArray(sizeArray) {
		DEBUG_TRACE("Creation SolutionArray");
		array = new TYPE_SOL[sizeArray];
		
	}
	
	SolutionArray(SolutionArray const & s) :
		Solution<TYPE_FITNESS>(s),
		_sizeArray(s._sizeArray) {
		
		array = new TYPE_SOL[_sizeArray];
		
		for (unsigned int i = 0 ; i < _sizeArray ; i++) {
			array[i] = s.array[i];
		}
	}
	
	virtual ~SolutionArray() {
		DEBUG_TRACE("Delete SolutionArray");
		delete[] array;
	}
	
	SolutionArray & operator=(SolutionArray const & s) {
		Solution<TYPE_FITNESS>::operator=(s);
		if (_sizeArray != s._sizeArray) {
			//this->~SolutionArray();
			_sizeArray = s._sizeArray;
			array = new TYPE_SOL[_sizeArray];
		}
		
		for (unsigned int i = 0 ; i < _sizeArray ; i++) {
			array[i] = s.array[i];
		}
		
		return *this;
	}
	
	
	void operator()(unsigned int const index, TYPE_SOL const value) {
		assert(index < _sizeArray);
		if (array[index] != value) {
			for (unsigned int i = 0 ; i < this->_numberOfObjective ; i++)
				this->_fitnessIsValid[i] = false;
			array[index] = value;
		}
	}
	
	TYPE_SOL operator()(unsigned int const index) const {
		assert(index < _sizeArray);
		return array[index];
	}
	
	unsigned int sizeArray() const {
		return _sizeArray;
	}

	void show() const {
		for (unsigned int i = 0 ; i < _sizeArray ; i++)
			std::cout<<array[i];
		std::cout<<std::endl;
	}
	
	friend std::ostream & operator << (std::ostream &out, const SolutionArray<TYPE_FITNESS, TYPE_SOL> &s) {
		for (unsigned int i = 0 ; i < s.numberOfObjective() ; i++)
			out << s.fitness(i);
		out <<" : ";
		for (unsigned int i = 0 ; i < s.sizeArray() ; i++)
			out<<s(i)<<" ";
		return out;
	}

private:
	TYPE_SOL *array;
	unsigned int _sizeArray;
	
};

#endif


