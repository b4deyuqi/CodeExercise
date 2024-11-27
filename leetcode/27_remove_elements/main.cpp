#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int removeElement1(vector<int> &nums, int val)
{
    /* 遍历 Time: O(n) Space: O(n) */
    int k = 0;
    vector<int> ans;
    int len = nums.size();
    for (int i = 0; i < len; i++)
    {
        if (nums[i] != val)
        {
            ans.push_back(nums[i]);
            k++;
        }
    }
    for (int i = 0; i < k; i++)
        nums[i] = ans[i];
    return k;
}
int removeElement2(vector<int> &nums, int val)
{
    /* 双指针，慢指针指向需要被换掉的val，快指针遍历后面可以往前交换的元素 */
    /* Time: O(n) Space: O(1) */
    /* 缺点 如果val出现在第一个位置，需要把所有的元素全往前移*/
    int fast = 0, slow = 0;
    while (fast < nums.size())
    {
        if (nums[fast] != val)
        {
            nums[slow] = nums[fast];
            slow++;
        }
        fast++;
    }
    return slow;
}
int removeElement(vector<int> &nums, int val)
{
    /* 逆向双指针，一个在头一个在尾，将前面出现的val交换到后面 */
    /* Time: O(n) Space: O(1) */

    int slow = 0, fast = nums.size() - 1;
    while (slow < fast)
    {
        if (nums[slow] == val)
        {
            nums[slow] = nums[fast];
            fast--;
        }
        slow++;
    }
    return slow;
}
int main()
{
    vector<int> nums;
    int val;
    int num;
    while (cin >> num)
    {
        nums.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    cin >> val;
    int k = removeElement(nums, val);
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl
         << k;
    return 0;
}