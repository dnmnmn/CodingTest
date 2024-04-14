// Description: 2_TaskProcess.cpp
// 프로그래머스 문제: 과제 진행하기
// 난이도 2

#include "2_TaskProcess.h"

vector<string> TaskProcess::solution(vector<vector<string>> plans) {
    vector<string> answer;
    stack <int> st;
    map<int, int> clocks;
    vector<pair<int, int>> times;
    int current = 0;
    for (int i = 0; i < plans.size(); i++)
    {
        int del = plans[i][1].find(':');
        string hour = plans[i][1].substr(0, del);
        string minit = plans[i][1].substr(del + 1, del + 3);
        int time = stoi(hour) * 60 + stoi(minit);
        clocks.insert(make_pair(time, i));
        times.push_back(make_pair(time, stoi(plans[i][2])));
    }
    for (auto iter : clocks)
    {
        while (true)
        {
            if (st.empty())
            {
                st.push(iter.second);
                current = iter.first;
                break;
            }
            int index = st.top(); // 이전 값
            if (current + times[index].second > iter.first) // 이전값의 종료시간이 다음값의 시작시간보다 늦을때
            {
                st.push(iter.second);
                times[index].second = (current + times[index].second - iter.first);
                current = iter.first;
                break;
            }
            else if (current + times[index].second == iter.first)
            {
                auto top = st.top();
                st.pop();
                answer.push_back(plans[index][0]);
                st.push(iter.second);
                current = iter.first;
                break;
            }
            else
            {
                auto top = st.top();
                st.pop();
                answer.push_back(plans[index][0]);
                current = current + times[index].second;
            }
        }
    }
    while (!st.empty())
    {
        answer.push_back(plans[st.top()][0]);
        st.pop();
    }
    return answer;
}

void TaskProcess::testCase()
{
    vector<vector<string>> plans = { {"korean", "11:40", "30"},{"english", "12:10", "20"},{"math", "12:30", "40"} };
    vector<string> correct = { "korean", "english", "math" };
	auto result = solution(plans);
    if (correct == result)
		cout << "Correct" << endl;
    else
		cout << "Wrong" << endl;
    testCase2();
    testCase3();
}

void TaskProcess::testCase2()
{
    vector<vector<string>> plans = { {"science", "12:40", "50"},{"music", "12:20", "40"},{"history", "14:00", "30"},{"computer", "12:30", "100"} };
	vector<string> correct = { "science", "history", "computer", "music" };
	auto result = solution(plans);
	if (correct == result)
		cout << "Correct" << endl;
	else
		cout << "Wrong" << endl;
}

void TaskProcess::testCase3()
{
    vector<vector<string>> plans = { {"aaa", "12:00", "20"},{"bbb", "12:10", "30"},{"ccc", "12:40", "10"} };
	vector<string> correct = { "bbb", "ccc", "aaa" };
	auto result = solution(plans);
	if (correct == result)
		cout << "Correct" << endl;
	else
		cout << "Wrong" << endl;
}