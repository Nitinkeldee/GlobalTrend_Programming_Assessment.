#include <iostream>
#include <string>
using namespace std;

bool isAlpha(const string &str)
{
    for (char ch : str)
    {
        if (!isalpha(ch))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    if (isAlpha(input))
    {
        cout << "The string contains only alphabetic characters." << endl;
    }
    else
    {
        cout << "The string contains non-alphabetic characters." << endl;
    }

    return 0;
}
