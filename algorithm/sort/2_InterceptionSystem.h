#include "../CodingTest.h"

class InterceptionSystem : public CodingTest
{
public:
	InterceptionSystem() {};
	~InterceptionSystem() {};
	void testCase() override;
public:
	int solution(vector<vector<int>> target);
};