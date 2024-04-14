// Description: 2_TwoCircle.cpp
// ���α׷��ӽ� ����: �� �� ������ ���� ��
// ���̵� 2

#include "2_TwoCircle.h"

long long TwoCircle::solution(int r1, int r2)
{
	long long answer = 0;
	int min = 0;
	int max = 0;
	// pow(i, 2) �� �̸� ����ؼ� ����ϸ� �޸� ���� ������ ������ ���� �� ����
	for (int i = 1; i <= r2; i++)
	{
		if (pow(r1, 2) < pow(i, 2)) min = 0;
		else min = ceil(sqrt(pow(r1, 2) - pow(i, 2)));
		max = floor(sqrt(pow(r2, 2) - pow(i, 2)));
		answer += max - min + 1;
	}
	answer = answer * 4;
	return answer;
}

void TwoCircle::testCase()
{
	int r1 = 2;
	int r2 = 3;
	cout << solution(r1, r2) << endl;
}