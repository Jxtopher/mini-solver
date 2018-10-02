//
// @Author: Jxtopher
// @License: *
// @Date: 2018-10
// @Version: *
// @Purpose: *
// 

#include <cstdlib>
#include <iostream>

#include "../sources/solution/solution.h"
#include "../sources/solution/solutionArray.h"

using namespace std;


int main(void) {
	
	SolutionArray<int, int> sa1(5, 200);
	sa1.fitness(3, 2);
	sa1.fitness(4, 23);
	sa1(50, 44);
	SolutionArray<int, int> sa2(sa1);
	assert(2 == sa2.fitness(3));
	
	SolutionArray<int, int> sa3(1, 5);
	sa3 = sa1;
	assert(2 == sa3.fitness(3));
	assert(23 == sa3.fitness(4));
	assert(44 == sa3(50));
	
	
	return EXIT_SUCCESS;
}