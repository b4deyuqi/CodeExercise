#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int majorityElement1(vector<int> &nums)
{
    /* 先排序，然后中位数即为众数 */
    /* Time: O(NlogN) Space: O(logN)*/
    sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
}

int majorityElement(vector<int> &nums)
{
    /* 哈希映射 */
    /* Time: O(n) Space: O(n)*/
    unordered_map<int, int> nums_cnt;
    int maxcnt = 0, maxval = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        nums_cnt[nums[i]]++;
        if (nums_cnt[nums[i]] > maxcnt)
        {
            maxval = nums[i];
            maxcnt = nums_cnt[nums[i]];
        }
    }
    return maxval;
}

int majorityElement(vector<int> &nums)
{
    /* 摩尔多数投票法 */
    /* Time: O(n) Space: O(1)*/
    /*
    第一个到来的士兵，直接插上自己阵营的旗帜占领这块高地。
    此时领主 winner 就是这个阵营的人，现存兵力 count = 1。
    如果新来的士兵和前一个士兵是同一阵营，则集合起来占领高地，
    领主不变，winner 依然是当前这个士兵所属阵营，现存兵力 count++；
    如果新来到的士兵不是同一阵营，则前方阵营派一个士兵和它同归于尽。
    此时前方阵营兵力count --。（
    即使双方都死光，这块高地的旗帜 winner 依然不变，因为已经没有活着的士兵可以去换上自己的新旗帜）
    当下一个士兵到来，发现前方阵营已经没有兵力，
    新士兵就成了领主，winner 变成这个士兵所属阵营的旗帜，现存兵力 count ++。
    */
    int winner = nums[0];
    int count = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (winner == nums[i])
        {
            count++;
        }
        else if (count == 0)
        {
            winner = nums[i];
            count++;
        }
        else
        {
            count--;
        }
    }
    return winner;
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
    int ans = majorityElement(nums);
    cout << ans << endl;
    return 0;
}