//
// @Author: Jxtopher
// @License: *
// @Date: 2018-10
// @Version: *
// @Purpose: *
// 

#ifndef EVALUATION_H
#define EVALUATION_H

template<class SOL>
class Evaluation {
public:
	Evaluation() {

	}

	~Evaluation() {

	}
	
	virtual void full(SOL &s) = 0;
	
	/*void incremental(SOL const &s) = 0;*/
	
private:
	
};

#endif