#include <iostream>
using namespace std;

int sumOfDigits(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (num < 0)
    {
        cout << "Sum of digits is not defined for negative numbers." << endl;
    }
    else
    {
        cout << "Sum of the digits of " << num << " is " << sumOfDigits(num) << endl;
    }

    return 0;
}
