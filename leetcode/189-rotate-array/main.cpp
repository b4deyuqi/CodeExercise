#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void rotate1(vector<int> &nums, int k)
{
    /* 借助于额外空间暂存需要移动到前面的元素 */
    /* Time: O(N) Space: O(1)*/
    int len = nums.size();
    int movement;
    movement = k % len;
    vector<int> temp(movement, 0);
    for (int i = 0; i < movement; i++)
        temp[i] = nums[len - movement + i];
    for (int i = len - 1; i >= movement; i--)
        nums[i] = nums[i - movement];
    for (int i = 0; i < movement; i++)
        nums[i] = temp[i];
}

void reverse2(vector<int> &nums, int h, int t)
{
    while (h < t)
    {
        swap(nums[h], nums[t]);
        h++, t--;
    }
}
void rotate2(vector<int> &nums, int k)
{
    k = k % nums.size();
    reverse2(nums, 0, nums.size() - 1);
    reverse2(nums, 0, k - 1);
    reverse2(nums, k, nums.size() - 1);
}

void rotate(vector<int> &nums, int k)
{
    k = k % nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k - 1);
    reverse(nums.begin() + k, nums.end());
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
    int k;
    cin >> k;
    rotate(nums, k);
    for (auto num : nums)
        cout << num << " ";
    return 0;
}
