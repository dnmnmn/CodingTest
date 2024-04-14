#include "2_MazeEscape.h"

// 너비 우선 탐색 함수
int MazeEscape::BFS(vector<vector<int>>& matrix, int start_row, int start_col, int target_row, int target_col) {
    int dr[] = { -1, 1, 0, 0 }; // 상, 하, 좌, 우
    int dc[] = { 0, 0, -1, 1 };
    int rows = matrix.size(); // 행 수
    int cols = matrix[0].size(); // 열 수
    vector<vector<bool>> visited(rows, vector<bool>(cols, false)); // 방문 여부를 저장하는 배열
    vector<vector<int>> distance(rows, vector<int>(cols, 0)); // 각 위치에 도달하는데 걸리는 이동 횟수
    queue<pair<int, int>> q; // 큐

    visited[start_row][start_col] = true; // 시작 지점 방문 표시
    q.push({ start_row, start_col }); // 시작 지점 큐에 삽입

    while (!q.empty()) {
        pair<int, int> current = q.front(); // 현재 위치
        q.pop(); // 큐에서 제거

        int row = current.first;
        int col = current.second;

        // 목표 지점에 도달한 경우, 해당 위치의 이동 횟수 반환
        if (row == target_row && col == target_col) {
            return distance[row][col];
        }

        // 상하좌우 이동을 위한 반복문
        for (int i = 0; i < 4; ++i) {
            int new_row = row + dr[i];
            int new_col = col + dc[i];

            // 새로운 위치가 범위 내에 있고, 벽이 아니며, 방문하지 않은 곳일 경우
            if (new_row >= 0 && new_row < rows && new_col >= 0 && new_col < cols &&
                matrix[new_row][new_col] != 1 && !visited[new_row][new_col]) {
                visited[new_row][new_col] = true; // 방문 표시
                distance[new_row][new_col] = distance[row][col] + 1; // 이동 횟수 기록
                q.push({ new_row, new_col }); // 큐에 삽입
            }
        }
    }

    // 목표 지점에 도달하지 못한 경우, -1 반환
    return -1;
}

int MazeEscape::solution(vector<string> maps) {
    int answer = 0;
    int start_row = 0; // 시작 지점 행
    int start_col = 0; // 시작 지점 열
    int target_row = 0; // 목표 지점 행
    int target_col = 0; // 목표 지점 열
    int lever_row = 0; // 레버
    int lever_col = 0;
    vector<vector<int>> matrix(maps.size(), vector<int>(maps[0].size(), 0)); // 맵을 저장하는 2차원 배열
    for (int i = 0; i < maps.size(); i++)
    {
        for (int j = 0; j < maps[i].size(); j++)
        {
            if (maps[i][j])
            {
                if (maps[i][j] == 'S')
                {
                    start_row = i;
                    start_col = j;
                }
                else if (maps[i][j] == 'E')
                {
                    target_row = i;
                    target_col = j;
                }
                else if (maps[i][j] == 'L')
                {
                    lever_row = i;
                    lever_col = j;
                }
                // 벽 = 1, 길 = 0
                else if (maps[i][j] == 'X')
                {
                    matrix[i][j] = 1;
                }
            }
        }
    }
    int lever_distance = BFS(matrix, start_row, start_col, lever_row, lever_col);
    if (lever_distance == -1) return -1;
    else answer += lever_distance;
    int exit_distance = BFS(matrix, lever_row, lever_col, target_row, target_col);
    if (exit_distance == -1) return -1;
    else answer += exit_distance;
    return answer;
}

void MazeEscape::testCase()
{
    vector<string> maps = { "SOOOL", "XXXXO", "OOOOO", "OXXXX", "OOOOE" };
	int correct = 16;
	auto result = solution(maps);
    if (result == correct)
    {
		cout << "Correct" << endl;
	}
    else
    {
		cout << "Wrong" << endl;
	}
    testCase2();
}

void MazeEscape::testCase2()
{
    vector<string> maps = { "LOOXS", "OOOOX", "OOOOO", "OOOOO", "EOOOO" };
    int correct = -1;
    auto result = solution(maps);
    if (result == correct)
    {
        cout << "Correct" << endl;
    }
    else
    {
        cout << "Wrong" << endl;
    }
}