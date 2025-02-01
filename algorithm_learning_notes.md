[toc]





# 二分查找

算法思路


算法模板

```cpp
class Solution
{
    int lower_bond(vector<int> nums, target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left;
    }
}
```



相关题目

[35. 搜索插入位置](https://leetcode.cn/problems/search-insert-position/)

[34. 在排序数组中查找元素的第一个和最后一个位置](https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/)
