// Description: 2_RicochetRobot.cpp
// 프로그래머스 문제: 리코쳇 로봇
// 난이도 2

#include "2_RicochetRobot.h"

int RicochetRobot::solution(vector<string> board) {
    int answer = -1;

    int rows = board.size();
    int cols = board[0].size();
    vector<vector<int8_t>> visited(rows + 2, vector<int8_t>(cols + 2, 0));
    queue<pos_state> q;
    pos_state start = { 0,0,0 };

    for (int i = 0; i < cols + 2; i++) {
        visited[0][i] = -1;
        visited[rows + 1][i] = -1;
    }
    for (int i = 0; i < rows + 2; i++)
    {
        visited[i][0] = -1;
        visited[i][cols + 1] = -1;
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (board[i][j] == 'D')
            {
                visited[i + 1][j + 1] = -1;
            }
            else if (board[i][j] == 'R')
            {
                start = { i + 1,j + 1,0 };
                visited[i + 1][j + 1] = 1;
            }
            else if (board[i][j] == 'G')
            {
                visited[i + 1][j + 1] = 3;
            }
        }
    }

    q.push(start);
    while (!q.empty())
    {
        pos_state current = q.front();
        q.pop();

        int x = current.x;
        int y = current.y;
        int count = current.count;
        if (visited[x][y] == 3)
        {
            answer = count;
            break;
        }
        //visited[x][y] = 1;
        for (int i = 0; i < 4; i++)
        {
            int new_x = x + (i == 0) - (i == 1);
            int new_y = y + (i == 2) - (i == 3);

            while (true)
            {
                if (visited[new_x][new_y] == -1)
                {
                    int moved_x = new_x + (i == 1) - (i == 0);
                    int moved_y = new_y + (i == 3) - (i == 2);
                    if (visited[moved_x][moved_y] == 0) {
                        q.push({ moved_x, moved_y, count + 1 });
                        visited[moved_x][moved_y] = 1;
                    }
                    else if (visited[moved_x][moved_y] == 3)
                    {
                        return count + 1;
                    }
                    break;
                }
                else
                {
                    new_x += (i == 0) - (i == 1);
                    new_y += (i == 2) - (i == 3);
                }
            }
        }

    }

    return answer;
}

void RicochetRobot::testCase()
{
	vector<string> board = { "...D..R", ".D.G...", "....D.D", "D....D.", "..D...." };
	cout << solution(board) << endl;
}