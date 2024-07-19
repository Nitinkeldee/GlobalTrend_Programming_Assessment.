#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxDifference(const vector<int> &nums)
{
    if (nums.empty())
        return 0;

    int minElement = nums[0];
    int maxDiff = 0;

    for (int i = 1; i < nums.size(); ++i)
    {
        maxDiff = max(maxDiff, nums[i] - minElement);
        minElement = min(minElement, nums[i]);
    }

    return maxDiff;
}

int main()
{
    vector<int> nums = {2, 5, 1, 7, 3, 8};

    cout << "Maximum difference: " << maxDifference(nums) << endl;

    return 0;
}
