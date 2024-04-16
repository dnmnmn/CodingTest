#include "2_ConvertNum.h"

int ConvertNum::solution(int x, int y, int n) {
    int answer = 2e9;
    int max = y - x + 1;
    bool* visited = new bool[max];
    memset(visited, 0, max);
    queue<pair<int, int>> s;
    s.push(make_pair(x, 0));
    while (!s.empty())
    {
        auto values = s.front();
        s.pop();
        if (values.second > answer) break;
        int index = values.first - x;
        if (visited[index] == true) continue;
        visited[index] = true;
        if (values.first == y)
        {
            if (answer > values.second)
                answer = values.second;
        }
        if (values.first + n <= y)
            s.push(make_pair(values.first + n, values.second + 1));
        if (values.first * 2 <= y)
            s.push(make_pair(values.first * 2, values.second + 1));
        if (values.first * 3 <= y)
            s.push(make_pair(values.first * 3, values.second + 1));
    }
    delete[] visited;
    if (answer == 2e9)
        answer = -1;
    return answer;
}

void ConvertNum::testCase()
{
	int x = 10;
	int y = 40;
	int n = 30;
	int result = solution(x, y, n);
    if (result == 1)
	    cout << "Correct" << endl;
    else
        cout << "Wrong" << endl;
}