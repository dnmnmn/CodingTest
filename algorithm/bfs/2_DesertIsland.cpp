#include "2_DesertIsland.h"

int DesertIsland::BFS(int start_row, int start_col)
{
	int days = 0;
	queue<pair<int, int>> track;
	track.push(make_pair(start_row, start_col));
	while (!track.empty())
	{
		auto current = track.front();
		track.pop();
		if(maps[current.first][current.second] == 0) continue;
		days += maps[current.first][current.second];
		maps[current.first][current.second] = 0;
		for (int dist = 0; dist < 4; dist++)
		{
			int next_row = current.first + (dist == 0) - (dist == 1);
			int next_col = current.second + (dist == 2) - (dist == 3);
			if(next_row < 0 || next_row >= maps.size() || next_col < 0 || next_col >= maps[0].size()) continue;
			if (maps[next_row][next_col] != 0)
			{
				track.push(make_pair(next_row, next_col));
			}
		}
	}
	return days;
}

vector<int> DesertIsland::solution(vector<string> _maps) {
    vector<int> answer;
	
	// maps initialize
	maps.resize(_maps.size(), std::vector<int>(_maps[0].size(), 0));
	for (int i = 0; i < _maps.size(); i++)
	{
		for (int j = 0; j < _maps[i].size(); j++)
		{
			if(_maps[i][j] == 'X')
				maps[i][j] = 0;
			else
				maps[i][j] = _maps[i][j] - '0';
		}
	}

	// BFS
	for (int i = 0; i < _maps.size(); i++)
	{
		for (int j = 0; j < _maps[i].size(); j++)
		{
			if (maps[i][j] != 0)
			{
				answer.push_back(BFS(i, j));
			}
		}
	}
	sort(answer.begin(), answer.end());
	if (answer.empty())
		answer.push_back(-1);
    return answer;
}

void DesertIsland::testCase()
{
	vector<string> _maps = { "X591X", "X1X5X", "X231X", "1XXX1" };
	vector<int> result = solution(_maps);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	cout << endl;
	testCase2();
}

void DesertIsland::testCase2()
{
	vector<string> _maps = { "XXX","XXX","XXX" };
	vector<int> correct = { -1 };
	auto result = solution(_maps);
	if (correct == result)
		cout << "Correct" << endl;
}