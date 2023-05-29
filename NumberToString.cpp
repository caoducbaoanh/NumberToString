#include <iostream>
#include <map>
using namespace std;

std::map <int, string> NUMBER_MAP =
{
	{0,""},
	{1, "một"},
	{2, "hai"},
	{3, "ba"},
	{4, "bốn"},
	{5, "năm"},
	{6, "sáu"},
	{7, "bảy"},
	{8, "tám"},
	{9, "chín"}, 
};

string Position(int position) {
	switch (position)
	{
	case 2:
		return "mươi";
	case 3:
		return "trăm";
	}
	return "";
}
bool ValidateInputNumber(int number, bool isNotNumber) {
	if (isNotNumber||number >= 1000 || number < 0) {
		return false;
	}
	return true;

}
int main() {
	

	long inputNumber, remainder;
	string string = "";
	int position = 1, n = 1000;

	for (int i = 0; i < n; i++) {
		bool isValidInput = false;
		//loop until user input invalid number
		while (!isValidInput) {
			cout << "\nPlease input number: ";
			cin >> inputNumber;
			isValidInput = ValidateInputNumber(inputNumber, !cin);
			if (!isValidInput) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
				cout << "Invalid number, please try again";
			}
			
		}

		//case number == 0
		if (inputNumber == 0) {
			cout << "không";
		}

		if (inputNumber >= 10 && inputNumber < 20) {
			inputNumber = inputNumber % 10;
			string = "mười " + NUMBER_MAP.at(inputNumber);
			cout << string;
		}
		else {
			while (inputNumber != 0)
			{
				remainder = inputNumber % 10;
				if (remainder == 0) {
					string = NUMBER_MAP.at(remainder) + "linh " + string;
				}
				else {
					string = NUMBER_MAP.at(remainder) + " " + Position(position) + " " + string;
				}
				inputNumber = inputNumber / 10;
				position += 1;
			}

			cout << string;
		}
		string = "";
		position = 1;
	}
}