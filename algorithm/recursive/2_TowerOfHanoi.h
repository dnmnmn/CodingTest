#include "../CodingTest.h"

class TowerOfHanoi : public CodingTest
{
public:
	TowerOfHanoi() {};
	~TowerOfHanoi() {};
	void testCase() override;
	vector<vector<int>> solution(int n);
	void recursive(vector<vector<int>>* answer, int start, int temp, int goal, int n);
};