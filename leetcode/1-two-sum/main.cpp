#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int> &nums, int target)
{
    /* 暴力求解 */
    /* Time: O(N2) Space: O(1)*/

    for (int i = 0; i < nums.size() - 1; i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if ((nums[i] + nums[j]) == target)
                return {i, j};
        }
    }
    return {-1, -1};
}
vector<int> twoSum(vector<int> &nums, int target)
{
    /* 利用哈希表，寻找当前元素【之前】有没有target-nums[i]*/
    /* Time: O(N) Space: O(N)*/
    unordered_map<int, int> dic;
    for (int i = 0; i < nums.size(); i++)
    {
        // 注意要先查找后插入！！！
        auto it = dic.find(target - nums[i]);
        if (it != dic.end())
        {
            return {i, it->second};
        }
        dic[nums[i]] = i;
    }
    return {-1, -1};
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
    int target;
    cin >> target;
    vector<int> ans = twoSum(nums, target);
    for (auto num : ans)
        cout << num << " ";
    return 0;
}