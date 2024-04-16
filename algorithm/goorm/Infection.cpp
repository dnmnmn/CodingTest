#include "Infection.h"

int Infection::solution(int n, int k, int* arr)
{
	int answer = 1;
	n -= k--;
	answer += ceil(n / k) + 1;
	return answer;
}

void Infection::testCase()
{
	int n = 4;
	int k = 3;
	int arr[4] = {2, 3, 1, 4};
	int result = solution(n, k, arr);
	cout << "result: " << result << endl;
}
