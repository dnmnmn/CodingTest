#include "../CodingTest.h"

class HotelRental : public CodingTest
{
public:
	HotelRental() {};
	~HotelRental() {};
	void testCase() override;
public:
	int solution(vector<vector<string>> book_time);
};