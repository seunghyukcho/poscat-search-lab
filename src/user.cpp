#include "tester.h"

using namespace std;

/*
 * You have to implement this part!
 * @params
 * - board : The board info. It is 4 x 4, starts from 1, not 0.
 *           ith row, jth col element can be accessed by board[i][j].
 * - ans : You have to insert your answers to this vector. You can understand how you insert it through the sample code
 *         pr is typedef pair<int, int>. If it is impossible, just left ans empty.
 * 
 * @answer format
 * - pr.first = start point. It is a integer of two digits. first digit means row number, second digit means second number.
 * - pr.second = end point. It is a integer of two digits. first digit means row number, second digit means second number.
 * ex) (13, 31) : move (row 1, col 3) to (rol 3, col 1)
 */
void Tester::solution(char board[][5], std::vector<pr>& ans)
{
	// You should replace the code under with yours!
	bool flag = true;
    char init[5][5];
    for(int j = 1; j <= 4; j++){
        for(int i = 1; i <= 4; i++){
            init[i][j] = board[i][j]; // Initial state of the chess board is in board
        }
    }
    
    if(!flag)
    	return; // If Impossible or already successful state(only one object exists), just return.
    else
    {
    	// else, insert your answer in ans vector.
    	ans.push_back({ 13, 31 });
    	ans.push_back({ 32, 41 });
    }
}


