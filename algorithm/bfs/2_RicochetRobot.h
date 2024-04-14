#pragma once
#include "../CodingTest.h"

class RicochetRobot : public CodingTest
{
public:
	RicochetRobot() {};
	~RicochetRobot() {};
	struct pos_state
	{
		int x = 0;
		int y = 0;
		int count = 0;
	};
	void testCase() override;
	int solution(vector<string> board);
};