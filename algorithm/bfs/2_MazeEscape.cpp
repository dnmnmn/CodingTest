#include "2_MazeEscape.h"

// �ʺ� �켱 Ž�� �Լ�
int MazeEscape::BFS(vector<vector<int>>& matrix, int start_row, int start_col, int target_row, int target_col) {
    int dr[] = { -1, 1, 0, 0 }; // ��, ��, ��, ��
    int dc[] = { 0, 0, -1, 1 };
    int rows = matrix.size(); // �� ��
    int cols = matrix[0].size(); // �� ��
    vector<vector<bool>> visited(rows, vector<bool>(cols, false)); // �湮 ���θ� �����ϴ� �迭
    vector<vector<int>> distance(rows, vector<int>(cols, 0)); // �� ��ġ�� �����ϴµ� �ɸ��� �̵� Ƚ��
    queue<pair<int, int>> q; // ť

    visited[start_row][start_col] = true; // ���� ���� �湮 ǥ��
    q.push({ start_row, start_col }); // ���� ���� ť�� ����

    while (!q.empty()) {
        pair<int, int> current = q.front(); // ���� ��ġ
        q.pop(); // ť���� ����

        int row = current.first;
        int col = current.second;

        // ��ǥ ������ ������ ���, �ش� ��ġ�� �̵� Ƚ�� ��ȯ
        if (row == target_row && col == target_col) {
            return distance[row][col];
        }

        // �����¿� �̵��� ���� �ݺ���
        for (int i = 0; i < 4; ++i) {
            int new_row = row + dr[i];
            int new_col = col + dc[i];

            // ���ο� ��ġ�� ���� ���� �ְ�, ���� �ƴϸ�, �湮���� ���� ���� ���
            if (new_row >= 0 && new_row < rows && new_col >= 0 && new_col < cols &&
                matrix[new_row][new_col] != 1 && !visited[new_row][new_col]) {
                visited[new_row][new_col] = true; // �湮 ǥ��
                distance[new_row][new_col] = distance[row][col] + 1; // �̵� Ƚ�� ���
                q.push({ new_row, new_col }); // ť�� ����
            }
        }
    }

    // ��ǥ ������ �������� ���� ���, -1 ��ȯ
    return -1;
}

int MazeEscape::solution(vector<string> maps) {
    int answer = 0;
    int start_row = 0; // ���� ���� ��
    int start_col = 0; // ���� ���� ��
    int target_row = 0; // ��ǥ ���� ��
    int target_col = 0; // ��ǥ ���� ��
    int lever_row = 0; // ����
    int lever_col = 0;
    vector<vector<int>> matrix(maps.size(), vector<int>(maps[0].size(), 0)); // ���� �����ϴ� 2���� �迭
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
                // �� = 1, �� = 0
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