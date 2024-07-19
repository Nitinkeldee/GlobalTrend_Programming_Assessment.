#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int lengthOfLongestSubstring(const string &s)
{
    unordered_map<char, int> charMap;
    int maxLength = 0;
    int start = 0;

    for (int end = 0; end < s.length(); ++end)
    {
        if (charMap.find(s[end]) != charMap.end())
        {
            start = max(start, charMap[s[end]] + 1);
        }
        charMap[s[end]] = end;
        maxLength = max(maxLength, end - start + 1);
    }

    return maxLength;
}

int main()
{
    string input;
    cout << "Enter a string: ";
    cin >> input;
    cout << "Length of longest substring without repeating characters: " << lengthOfLongestSubstring(input) << endl;
    return 0;
}
