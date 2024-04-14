// Description: 2_InterceptionSystem.cpp
// 프로그래머스 문제: 요격 시스템
// 난이도 2

#include "2_InterceptionSystem.h"
#include <algorithm>

bool cmp(vector<int>& a, vector<int>& b)
{
    return a[1] < b[1];
}

int InterceptionSystem::solution(vector<vector<int>> targets) {
    int answer = 0;
    std::sort(targets.begin(), targets.end(), cmp);
    int target = -1;
    for (int i = 0; i < targets.size(); i++)
    {
        if (targets[i][0] >= target)
        {
            target = targets[i][1];
            answer++;
        }
    }
    return answer;
}

void InterceptionSystem::testCase()
{
    vector<vector<int>> targets = { {4,5},{4,8},{10,14},{11,13},{5,12},{3,7},{1,4} };
	cout << solution(targets) << endl;
}