#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int> &nums)
{
    int slow = 0, fast = 1, flag = 0;
    if (nums.size() <= 2)
        return nums.size();
    while (fast < nums.size())
    {
        if (nums[slow] != nums[fast])
        {
            flag = 0;
            slow++;
            nums[slow] = nums[fast];
            fast++;
        }
        else if (nums[slow] == nums[fast])
        {

            if (flag == 0)
            {
                flag = 1;
                slow++;
                nums[slow] = nums[fast];
            }
            fast++;
        }
    }
    return slow + 1;
}

// int work(vector<int> &nums, int k)
// {
//     int len = 0;
//     for (int i = 0; i < nums.size(); i++)
//         if (len < k || nums[len - k] != nums[i])
//             nums[len++] = nums[i];
//     return len;
// }
// int removeDuplicates(vector<int> &nums)
// {
//     return work(nums, 2);
// }

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
    cout << k << endl;
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    return 0;
}