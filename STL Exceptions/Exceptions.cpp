//Matthew Mondi
// CIS 1202
// 5/3/22

#include<iostream>

using namespace std;

// function
char character(char start, int offset);


// usee start is not (A-z,a-z)
class invalidCharacterExcpeption
{

};

// used if if the target is not a letter
class invalidRangeException
{

};


class caseConversionException
{

};


char character(char start, int offset) {


	int StartingValue = int(start);
	int I = StartingValue + offset;

	try {

		if (StartingValue < 65 || (StartingValue > 90 && StartingValue < 97) || StartingValue > 122)
		{
			throw invalidCharacterExcpeption();
		}
		else if (I < 65 || (I > 90 && I < 97) || I>122) {
			throw invalidCharacterExcpeption();
		}
		else if ((I >= 65 && I <= 90 && StartingValue >= 95 && StartingValue <= 122) || (I >= 95 && StartingValue <= 122 && StartingValue >= 65 && StartingValue <= 90)) {

			throw caseConversionException();
		}
	}

	catch (invalidCharacterExcpeption Exception1) {
		cout << "Invalid Character Exception" << endl;
		return ' ';
	}

	catch (caseConversionException Exception2) {
		cout << "Invalid Range Exception" << endl;
		return ' ';
	}

	catch (caseConversionException Exception3) {
		cout << "Invalid Letter Casing" << endl;
		return ' ';
	}

	return char(I);

}

int main() {

	cout << character('a', 1) << endl;
	cout << character('a', -1) << endl;
	cout << character('Z', -1) << endl;
	cout << character('?', 5) << endl;
	cout << character('A', 32) << endl;
}