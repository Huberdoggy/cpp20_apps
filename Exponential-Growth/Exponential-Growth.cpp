#include "..\quick_headers.h"
using namespace std;

int main()
{
	const int boardSize{ 64 };
	int rice = 1;
	double doubleRice{}; // For use with the REALLY large nums
	bool call_OneThousand = true, call_OneMillion = true, call_OneBillion = true; // Flags to filter output while I'm testing, to break on different points

	vector<int> chessboard;
	// Since the first square will contain 2^0, we can find the amount of rice for any given square with formula 2^(n-1)

	for (int i = 0; i < boardSize; i++)
	{
		chessboard.push_back(rice);
		rice *= 2; // Push 1 grain on square 1, and then multiply by 2 for each next square
		if (rice >= 1000 && call_OneThousand) {
			cout << "\nNumber of rice grains at square " << i + 2 << ": " << rice; // i + 2 due to the fact I'm breaking as soon as it hits condition and I'm zero indexing.
			call_OneThousand = false;
		}
		else if (i == boardSize - 1) {
			cout << "\nNumber of rice grains on the FINAL square: " << doubleRice; // Because there really are only 64 squares. Can't even properly store a num this big..
		}
		else if (rice >= 1000000 && call_OneMillion) {
			cout << "\nNumber of rice grains at square " << i + 2 << ": " << rice;
			doubleRice = double(rice);
			call_OneMillion = false;
		}
		else if (rice >= 1000000000 && call_OneBillion) {
			cout << "\nNumber of rice grains at square " << i + 2 << ": " << rice;
			call_OneBillion = false;
		}


	}


	return 0;
}

