#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int> &height)
{
    /* 双指针 Time: O(N) Space: O(1)*/
    /* 核心思路：相向双指针从两头向中间移动，直到两个指针相遇 */
    /* 【关键点】移动哪个，怎么移动：移动左右指针中短的那个，总容量由量指针的距离和最短板子的高度决定。*/

    int l = 0, r = height.size() - 1;
    int maxv = 0, curv = 0;
    ;
    while (l < r)
    {
        curv = (r - l) * min(height[l], height[r]);
        if (curv > maxv)
            maxv = curv;
        if (height[l] <= height[r])
            l++;
        else
            r--;
    }
    return maxv;
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

    int ans = maxArea(nums);
    cout << ans << endl;
    for (auto num : nums)
        cout << num << " ";
    return 0;
}