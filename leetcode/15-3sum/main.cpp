#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> threeSum(vector<int> &nums)
{
    // 首先进行排序
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    for (int i = 0; i < nums.size(); i++)
    {
        // 如果当前元素不是第一个，且与前一个元素重复，则跳过该元素
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int target = 0 - nums[i];
        // 左右指针查找符合条件的元素对
        for (int l = i + 1, r = nums.size() - 1; l < r;)
        {
            int sum = nums[l] + nums[r];
            if (sum == target)
            {
                // 找到符合条件的，保存结果
                ans.push_back({nums[i], nums[l], nums[r]});
                // 继续寻找
                l++;
                r--;
                // 如果与当前元素值相同，则跳过
                while (l < r && nums[l] == nums[l - 1])
                    l++;
                while (l < r && nums[r] == nums[r + 1])
                    r--;
            }
            // 如果当前元素之和大于目标值，则右指针左移
            else if (sum > target)
                r--;
            // 反之，左指针右移
            else
                l++;
        }
    }
    return ans;
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

    vector<vector<int>> ans = threeSum(nums);
    for (const auto &group : ans)
    {
        for (const auto &str : group)
        {
            cout << str << " "; // 输出每个字符串，空格分隔
        }
        cout << endl; // 每组数据输出完后换行
    }
    return 0;
}