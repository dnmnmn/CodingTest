// Description: 2_BilliardsPractice.cpp
// ���α׷��ӽ� ����: �籸 ����
// ���̵� 2

#include "2_BilliardsPractice.h"

int BilliardsPractice::distance(int x1, int y1, int x2, int y2)
{
    return pow(x1 - x2, 2) + pow(y1 - y2, 2);
}

vector<int> BilliardsPractice::solution(int m, int n, int startX, int startY, vector<vector<int>> balls)
{
    vector<int> answer;
    // ���ʺ� �ݻ�
    int left_x = startX * -1;
    int left_y = startY;
    // ������ �� �ݻ�
    int right_x = m + m - startX;
    int right_y = startY;

    // �Ʒ��� �� �ݻ�
    int bottom_x = startX;
    int bottom_y = startY * -1;
    // ���� �� �ݻ�
    int top_x = startX;
    int top_y = n + n - startY;


    for (auto ball : balls)
    {
        int min = INT_MAX;
        int temp = INT_MAX;
        if (startY != ball[1])
        {
            // ���ʺ�  �ݻ�  
            temp = distance(left_x, left_y, ball[0], ball[1]);
            min = min > temp ? temp : min;
            // �����ʺ� �ݻ�
            temp = distance(right_x, right_y, ball[0], ball[1]);
            min = min > temp ? temp : min;
        }
        else
        {
            if (startX < ball[0])
            {
                temp = distance(left_x, left_y, ball[0], ball[1]);
                min = min > temp ? temp : min;
            }
            else
            {
                temp = distance(right_x, right_y, ball[0], ball[1]);
                min = min > temp ? temp : min;
            }
        }
        if (startX != ball[0])
        {
            // �Ʒ��� �� �ݻ�
            temp = distance(bottom_x, bottom_y, ball[0], ball[1]);
            min = min > temp ? temp : min;
            // ���� �� �ݻ�
            temp = distance(top_x, top_y, ball[0], ball[1]);
            min = min > temp ? temp : min;
        }
        else
        {
            if (startY < ball[1])
            {
                temp = distance(bottom_x, bottom_y, ball[0], ball[1]);
                min = min > temp ? temp : min;
            }
            else
            {
                temp = distance(top_x, top_y, ball[0], ball[1]);
                min = min > temp ? temp : min;
            }
        }
        answer.push_back(min);
    }
    return answer;
}

void BilliardsPractice::testCase()
{
    vector<vector<int>> balls = { {7, 7},{2, 7},{7, 3} };
    vector<int> correct = { 52, 37, 116 };
	auto result = solution(10, 10, 3, 7, balls);
    if (correct == result) 
        cout << "Correct" << endl;
    else
        cout << "Wrong" << endl;
}