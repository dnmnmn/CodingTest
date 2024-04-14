#include "../CodingTest.h"

class MazeEscape : public CodingTest
{
public:
	MazeEscape() {};
	~MazeEscape() {};
	void testCase() override;
	void testCase2();
public:
	int solution(vector<string> maps);
	int BFS(vector<vector<int>>& matrix, int start_row, int start_col, int target_row, int target_col);
};