#include "../CodingTest.h"

class TaskProcess : public CodingTest
{
public:
	TaskProcess() {};
	~TaskProcess() {};
	void testCase() override;
	void testCase2();
	void testCase3();
public:
	vector<string> solution(vector<vector<string>> plans);
};