#include "2_HotelRental.h"

int HotelRental::solution(vector<vector<string>> book_time) {
    int answer = 0;
    short hotel[24 * 60] = { 0, };
    for (int i = 0; i < book_time.size(); i++)
    {
        int hour = stoi(book_time[i][0].substr(0, 2));
        int minute = stoi(book_time[i][0].substr(3, 2));
        int start = hour * 60 + minute;
        hour = stoi(book_time[i][1].substr(0, 2));
        minute = stoi(book_time[i][1].substr(3, 2));
        int end = hour * 60 + minute + 10;
        for (int j = start; j < end; j++)
        {
            hotel[j] += 1;
        }
    }
    answer = *max_element(begin(hotel), end(hotel));
    return answer;
}

void HotelRental::testCase()
{
    vector<vector<string>> book_time = { {"10:20", "12:30"},{"10:20", "12:30"},{"10:20", "12:30"} };
	int result = solution(book_time);
	cout << "result: " << result << endl;
}