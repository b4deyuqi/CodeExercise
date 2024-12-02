#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void moveZeroes(vector<int> &nums)
{
    int slow = 0;
    int fast = 0;
    while (fast < nums.size())
    {
        if (nums[fast] != 0)
        {
            nums[slow] = nums[fast];
            slow++;
            fast++;
        }
        else
            fast++;
    }
    while (slow < nums.size())
        nums[slow++] = 0;
}

int main()
{
    vector<int> nums;
    int num;
    while (cin >> num)
    {
        nums.push_back(num);
        if (cin.peek() != '\n')
            break;
    }

    moveZeroes(nums);
    for (auto num : nums)
        cout << num << " ";
    return 0;
}