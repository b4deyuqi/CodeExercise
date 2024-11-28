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
    /* 双指针从头遍历数组，重新给数组赋值 */
    /* 快指针寻找所有符合条件的元素，慢指针起到索引作用，指向当前赋值的位置 */
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

int removeElement2plus(vector<int> &nums, int val)
{
    int k = 0;
    for (int x : nums)
    {
        if (x != val)
        {
            nums[k++] = x;
        }
    }
    return k;
}

int removeElement(vector<int> &nums, int val)
{
    /* 逆向双指针，一个在头一个在尾，将前面出现的val交换到后面 */
    /* 需要注意交换后需要重新对交换过来的元素进行判断 */
    /* Time: O(n) Space: O(1) */

    int slow = 0, fast = nums.size() - 1;
    while (slow <= fast) // 注意是小于等于
    {
        if (nums[slow] == val)
        {
            nums[slow] = nums[fast];
            fast--;
            // slow没变化，因为可能换过来的仍然是==val的
        }
        else
            slow++;
    }
    return slow;
}

int removeElement(vector<int> &nums, int val)
{
    // 使用 std::remove 移动所有不等于 val 的元素到前面
    // 返回一个指向最后一个不等于 val 元素的迭代器
    auto it = remove(nums.begin(), nums.end(), val);
    // erase 从该迭代器到末尾的所有元素
    nums.erase(it, nums.end());
    return nums.size();
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