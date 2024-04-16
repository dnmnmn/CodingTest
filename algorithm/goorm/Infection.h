#include "../CodingTest.h"

class Infection : public CodingTest
{
public:
	Infection() {};
	~Infection() {};
	void testCase() override;
public:
	int solution(int n, int k, int* arr);
};