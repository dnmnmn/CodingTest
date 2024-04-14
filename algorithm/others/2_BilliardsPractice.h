#include "../CodingTest.h"

class BilliardsPractice : public CodingTest
{
public:
	BilliardsPractice() {};
	~BilliardsPractice() {};
	void testCase() override;
public:
	vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls);
	int distance(int x1, int y1, int x2, int y2);
};