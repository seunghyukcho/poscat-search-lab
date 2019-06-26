#include "tester.h"
#include "colormode.h"
#include <string>
#include <cmath>
#include <algorithm>
#include <fstream>

Tester::Tester()
{
	for(int i = 1; i <= TEST_NUMBER; i++)
		importTestCase(i);
}

void Tester::debug(char board[][5])
{
	for(int i = 1; i <= 4; i++)
	{
		for(int j = 1; j <= 4; j++)
			std::cout << board[i][j];
		std::cout << '\n';
	}
}

void Tester::importTestCase(int testCase)
{
	std::ifstream inFile("./testfiles/input" + std::to_string(testCase) + ".txt");
	std::string line;

	if(!inFile)
	{
		std::cout << "Testcase #" << testCase << " file not exists... Plz check your ./testfiles folder" << std::endl;
		exit(1);
	}

	try 
	{
		inFile >> isValid[testCase];
		for(int row = 1; row <= 4; row++)
		{
			inFile >> line;
			for(int col = 1; col <= 4; col++)
				testCases[testCase][row][col] = line[col - 1];
		}
	}
	catch(...)
	{
		std:: cout << "Testcase #" << testCase << " has wrong format... Plz check your file in ./testfiles folder" << std::endl;
		exit(1);
	}
}

void Tester::testAll()
{
	int correctTestCases = 0, result;
	std::string message;
	Color::Modifier red(Color::FG_RED);
	Color::Modifier blue(Color::FG_BLUE);
	Color::Modifier def(Color::FG_DEFAULT);
	Color::Modifier green(Color::FG_GREEN);

	std::cout << "\n***Start Testing!***" << std::endl << std::endl;

	for(int t = 1; t <= TEST_NUMBER; t++)
	{
		std::cout << "[TC #";
		if(t < 10) std::cout << "0";
		std::cout << t << "] ";
		result = test(t);

		switch(result)
		{
			case 0:
				correctTestCases++;
				std::cout << green;
				message = "CORRECT!";
				break;
			case 1:
				std::cout << red;
				message = "WRONG ANSWER";
				break;
			case 2:
				std::cout << red;
				message = "INVALID MOVEMENT";
				break;
			default:
				message = "System Error... Plz contact to the developer";
		}

		std::cout << message << def << std::endl;
	}

	std::cout << "\nTotal Result: " << correctTestCases << " / " << TEST_NUMBER << std::endl;
	if(correctTestCases == TEST_NUMBER)
	{
		std::cout << green << "\nCongratulations! You've passed all the tests! Have a good day :)" << def << std::endl;
	}
}

/*
 * return values 
 * true : simulation has successfully finished.
 * false : invalid movement
 */
bool Tester::simulation(char board[][5], std::vector<pr>& process)
{
	int startx, starty, endx, endy;
	int diffx, diffy;
	int row, col, dirx, diry;
	char horse;

	for(pr action : process)
	{
		startx = action.first / 10, starty = action.first % 10;
		endx = action.second / 10, endy = action.second % 10;
		diffx = abs(startx - endx);
		diffy = abs(starty - endy);

		if(startx == endx && starty == endy)
			return false;
		if(startx < 1 || starty < 1 || endx < 1 || endy < 1)
			return false;
		if(startx > 4 || starty > 4 || endx > 4 || endy > 4)
			return false;

		if(startx < endx) dirx = 1;
		else if(startx > endx) dirx = -1;
		else dirx = 0;

		if(starty < endy) diry = 1;
		else if(starty > endy) diry = -1;
		else diry = 0;

		horse = board[startx][starty];
		if(board[endx][endy] == '.')
			return false;
		if(horse != '.' && horse != 'K' && horse != 'P')
		{
			for(int row = startx + dirx, col = starty + diry; 
				row != endx && col != endy; row += dirx, col += diry)
				if(board[row][col] != '.')
					return false;
		}

		if(horse == '.')
			return false;
		else if(horse == 'E')
		{
			if(diffx > 1 || diffy > 1)
				return false;
		}
		else if(horse == 'Q')
		{
			if(diffx * diffy != 0 && diffx != diffy)
				return false;
		}
		else if(horse == 'K')
		{
			if(diffx * diffy != 2)
				return false;
		}
		else if(horse == 'B')
		{
			if(diffx != diffy)
				return false;
		}
		else if(horse == 'R')
		{
			if(diffx * diffy != 0)
				return false;
		}
		else if(horse == 'P')
		{
			if(diffx * diffy != 1 || startx < endx)
				return false;
		}
		else
			return false;

		board[endx][endy] = horse;
		board[startx][starty] = '.';
	}

	return true;
}

bool Tester::isCorrect(char board[][5])
{
	int cnt = 0;
	for(int row = 1; row <= 4; row++)
		for(int col = 1; col <= 4; col++)
			if(board[row][col] != '.')
				cnt++;

	return (cnt == 1 ? true : false);
}

/*
 * return values 
 * 0 : correct answer
 * 1 : correct movements, but wrong answer
 * 2 : invalid movements
 */
int Tester::test(int testCase)
{
	char board[5][5];
	bool result;
	std::vector<pr> ans;

	for(int row = 1; row <= 4; row++)
		memcpy(board[row] + 1, testCases[testCase][row] + 1, 4 * sizeof(char));
	solution(board, ans);

	for(int row = 1; row <= 4; row++)
		memcpy(board[row] + 1, testCases[testCase][row] + 1, 4 * sizeof(char));
	result = simulation(board, ans);

	if(!result)
		return 2;

	if(!isValid[testCase] && ans.size() == 0)
		return 0;
	else if(isValid[testCase] && isCorrect(board))
		return 0;

	return 1;
}