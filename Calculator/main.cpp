#include <iostream>

using namespace std;

int main()
{
	int num1, num2;
	int choice;
	cout << "Enter number 1: ";
	cin >> num1;

	cout << "Enter number 2: ";
	cin >> num2;

	cout << "Enter what you want to do:\n1. Addition\n2. Subtraction\n3. Multiply\n4. Division\n\nChoice: ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		cout << "Sum: " << num1 + num2;
		break;
	case 2:
		cout << "Subtract: " << num1 - num2;
		break;
	case 3:
		cout << "Product: " << num1 * num2;
		break;
	case 4:
		cout << "Div: " << float(num1) / float(num2);
		break;
	}

	return 0;
}