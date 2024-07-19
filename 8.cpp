#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main()
{
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    if (num1 < 0 || num2 < 0)
    {
        cout << "GCD is not defined for negative numbers." << endl;
    }
    else
    {
        cout << "GCD of " << num1 << " and " << num2 << " is " << gcd(num1, num2) << endl;
    }

    return 0;
}
