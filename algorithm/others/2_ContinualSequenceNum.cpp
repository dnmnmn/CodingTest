// Description: 2_ContinualSequenceNum.cpp
// 프로그래머스 문제: 연속된 부분 수열의 합
// 난이도 2

#include "2_ContinualSequenceNum.h"

vector<int> ContinualSequenceNum::solution(vector<int> sequence, int n)
{
	vector<int> answer(2, 0);
	int sum = sequence[0];
	int min_element = sequence.size();
	int first = 0;
	int last = 0;
	while (true)
	{
		if (sum < n)
		{
			last++;
			if (sequence.size() <= last) break;
			sum += sequence[last];
			continue;
		}
		else if (sum == n)
		{
			if (min_element > last - first)
			{
				min_element = last - first;
				answer[0] = first;
				answer[1] = last;
			}
		}
		sum -= sequence[first];
		first++;
	}
	return answer;
}

void ContinualSequenceNum::testCase()
{
	vector<int> sequence = { 2, 2, 2, 2, 2 };
	int n = 6;
	auto result = solution(sequence, n);
	for (auto i : result)
	{
		cout << i << " ";
	}
	cout << endl;
}