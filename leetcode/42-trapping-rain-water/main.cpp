#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int trap(vector<int> &height)
{
    /* 动态规划DP Time: O(N) Space: O(N)*/
    /*
        核心：每一个位置的雨水量怎么求。注意每一次遍历的区间取值范围。
        思路：三次遍历，
            1. 第一次找每一个位置左侧最大的高度
            2. 第二次找每一个位置右侧最大的高度
            3. 第三次根据当前高度、左侧高度、右侧高度计算出该位置能存放的最大雨水量
    */

    // 左侧最大高度记录，注意特殊位置处理
    vector<int> leftmax(height.size());
    leftmax[0] = height[0];
    // 右侧最大高度记录，注意特殊位置处理
    vector<int> rightmax(height.size());
    rightmax[height.size() - 1] = height[height.size() - 1];

    int sumrain = 0; // 记录雨水总量
    // 1 遍历，记录左侧最大高度
    for (int i = 1; i < height.size(); i++)
        leftmax[i] = max(leftmax[i - 1], height[i]);
    // 2 遍历，记录右侧最大高度
    for (int i = height.size() - 2; i >= 0; i--)
        rightmax[i] = max(rightmax[i + 1], height[i]);
    // 3 遍历，求每个位置的最大雨水量
    for (int i = 0; i < height.size(); i++)
    {
        int currain = min(leftmax[i], rightmax[i]) - height[i];
        sumrain += currain;
    }
    return sumrain;
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

    int ans = trap(nums);
    cout << ans;
    return 0;
}