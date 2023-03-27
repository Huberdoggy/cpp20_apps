#include <common_includes.h>

using namespace std;

int main()
{
	const int boardSize{ 64 };
	unsigned long long rice{ 1 };  // For use with the REALLY large nums. Start at one since in the story, square 1 gets 1 grain

	vector<int> chessboard;
	// Since the first square will contain 2^0, we can find the amount of rice for any given square with formula 2^(n-1)

	for (int i = 0; i < boardSize; i++)
	{
		chessboard.push_back(rice);
		if (i >= 1)
		{
			rice *= 2;
		}
		cout << "\nNumber of rice grains at square " << i + 1 << ": " << rice; // i + 1 due to the fact I'm zero indexing the loop.
	}

	return 0;
}

