

#include <iostream>
#include<string>

using namespace std;

bool palindrome(string wort) {

	for (int i = 0; i < wort.length(); i++) {
		if ((wort.at(i)) != (wort.at(wort.length() - 1 - i)))
		{
			return false;
		}


	}
	return true;
}
int main()
{
	cout << palindrome("ABBA") << endl;
	cout << palindrome("REITTIER") << endl;
	cout << palindrome("KEINPALINDROME") << endl;

}

