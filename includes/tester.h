#ifndef TESTER_H
#define TESTER_H

#include <iostream>
#include <vector>
#define TEST_NUMBER 10

typedef std::pair<int, int> pr;

class Tester
{
private:
	char testCases[TEST_NUMBER + 1][5][5];
	bool isValid[TEST_NUMBER + 1];

public:
	Tester();
	void importTestCase(int testCase);
	void testAll();
	int test(int testCase);
	void solution(char board[][5], std::vector<pr>& ans);
	bool isCorrect(char board[][5]);
	bool simulation(char board[][5], std::vector<pr>& process);
};

#endif