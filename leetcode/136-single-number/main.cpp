#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int singleNumber(vector<int> &nums)
{
    /* 利用哈希map记录每一个元素出现的次数 */
    /* 查找哈希map中出现了一次的元素 */
    unordered_map<int, int> dic;
    for (int i = 0; i < nums.size(); i++)
    {
        if (dic.count(nums[i]) == 0)
            dic[nums[i]] = 1;
        else
            dic[nums[i]]++;
    }
    for (auto it : dic)
    {
        if (it.second == 1)
            return it.first;
    }
    return 0;
}

int singleNumber(vector<int> &nums)
{
    /* 利用异或运算的性质 */
    /* a^0=a; a^a=0; a^a^b=b */
    int ans = 0;
    for (auto i : nums)
        ans = i ^ ans;
    return ans;
}

int main()
{
    int ans = 0;
    vector<int> nums;
    while (cin >> ans)
    {
        nums.push_back(ans);
        if (cin.peek() != '\n')
            break;
    }
    ans = singleNumber(nums);
    cout << ans;
    return 0;
}