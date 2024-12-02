#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int> &height)
{
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