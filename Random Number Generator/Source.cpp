#include <iostream>

using namespace std;

int main()
{
	//Selecting a random number
	int random = 1 + rand() % 100, ans = 0; 

	cout << "\n" << random;
	while (ans != random)
	{
		cout << "\nEnter a number from 1 to 100: ";
		cin >> ans;

		if (ans == random)
		{
			cout << "\nCorrect!!";
		}
		else
		{
			cout << "\nTry Again!";
		}
	}

	return 0;
}