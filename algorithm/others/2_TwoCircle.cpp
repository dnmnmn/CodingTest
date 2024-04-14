// Description: 2_TwoCircle.cpp
// 프로그래머스 문제: 두 원 사이의 정수 쌍
// 난이도 2

#include "2_TwoCircle.h"

long long TwoCircle::solution(int r1, int r2)
{
	long long answer = 0;
	int min = 0;
	int max = 0;
	// pow(i, 2) 를 미리 계산해서 사용하면 메모리 범위 문제로 오답이 나올 수 있음
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