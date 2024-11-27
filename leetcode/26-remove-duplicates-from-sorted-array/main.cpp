#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int> &nums)
{
    int slow = 0, fast = 1;
    while (fast < nums.size())
    {
        // fast 去寻找下一个出现的新元素
        // slow 指向当前非重复的最后一个元素
        if (nums[slow] != nums[fast])
        {
            // 当找到新的元素
            slow++;                  // 指向下一个可覆盖的位置
            nums[slow] = nums[fast]; // 覆盖
            fast++;                  // 寻找下一个和当前不重复的元素
        }
        else if (nums[slow] == nums[fast])
        {
            // 重复，继续往后找
            fast++;
        }
    }
    return slow + 1;
}
int main()
{
    int k = 0, num = 0;
    vector<int> nums;
    while (cin >> num)
    {
        nums.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    k = removeDuplicates(nums);
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    return 0;
}