#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int longestConsecutive(vector<int> &nums)
{
    // 利用集合去除重复元素
    unordered_set<int> num;
    for (auto i : nums)
        num.insert(i); // 注意是insert()不是push_back()
    // 记录最长的序列长度
    int maxlength = 0;
    // 记录当前序列长度
    int curlength = 0;
    for (auto i : num)
    {
        // 【如果当前元素i的前一个元素i-1存在，则放弃该元素】！！！
        // 如果前一个元素不存在，则从当前元素开始计数
        if (!num.count(i - 1))
        {
            int curnum = i; // 记录元素值
            curlength = 1;  // 初始化序列长度
            while (num.count(curnum + 1))
            {
                // 当前元素的下一元素存在
                curnum++;
                curlength++;
            }
            maxlength = max(maxlength, curlength);
        }
    }
    return maxlength;
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
    int ans = longestConsecutive(nums);
    cout << ans << " ";
    return 0;
}