#include "../CodingTest.h"

class DesertIsland : public CodingTest
{
public:
	DesertIsland() {};
	~DesertIsland() {};
	void testCase() override;
	void testCase2();
public:
	vector<int> solution(vector<string> maps);
	int BFS(int start_row, int start_col);
public:
	vector<vector<int>> maps;

};