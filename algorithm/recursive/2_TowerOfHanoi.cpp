// Description: 2_TowerOfHanoi.cpp
// 프로그래머스 문제: 하노이의 탑
// 난이도 2

#include "2_TowerOfHanoi.h"

void TowerOfHanoi::recursive(vector<vector<int>>* answer, int start, int temp, int goal, int n)
{
	vector<int> v;
	if (n == 1)
	{
		v.push_back(start);
		v.push_back(goal);
		answer->push_back(v);
	}
	else
	{
		recursive(answer, start, goal, temp, n - 1);
		v.push_back(start);
		v.push_back(goal);
		answer->push_back(v);
		recursive(answer, temp, start, goal, n - 1);
	}
}

vector<vector<int>> TowerOfHanoi::solution(int n)
{
	vector<vector<int>> answer;
	recursive(&answer, 1, 2, 3, n);
	return answer;
}

void TowerOfHanoi::testCase()
{
	auto result = solution(3);
	for (auto& v : result)
	{
		for (auto& i : v)
		{
			cout << i << " ";
		}
		cout << endl;
	}
}