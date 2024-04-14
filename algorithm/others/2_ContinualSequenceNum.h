#include "../CodingTest.h"

class ContinualSequenceNum : public CodingTest
{
public:
	ContinualSequenceNum() {};
	~ContinualSequenceNum() {};
	void testCase() override;
	vector<int> solution(vector<int> sequence,int n);
};