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



# 定长滑动窗口

https://leetcode.cn/problems/maximum-number-of-vowels-in-a-substring-of-given-length/solutions/2809359/tao-lu-jiao-ni-jie-jue-ding-chang-hua-ch-fzfo/



思路

三部曲：

1. **入**：下标为 *i* 的元素进入窗口，更新相关统计量。如果 *i*<*k*−1 则重复第一步。
2. **更新**：更新答案。一般是更新最大值/最小值。
3. **出**：下标为 *i*−*k*+1 的元素离开窗口，更新相关统计量。



[1456. 定长子串中元音的最大数目](https://leetcode.cn/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/)

```cpp
class Solution {
public:
    int maxVowels(string s, int k) {
        int ans = 0;
        int cnt = 0;
        for (int right = 0; right < s.size(); right++) {
            // 1. 下标为 right 的元素进入窗口，更新统计变量
            if (s[right] == 'a' || s[right] == 'e' || s[right] == 'i' ||
                s[right] == 'o' || s[right] == 'u')
                cnt++;
            if (right < k - 1)
                continue;
            // 2. 更新答案
            ans = max(ans, cnt);
            // 3. 下标为 right - k + 1的元素离开窗口，更新统计变量
            int left = right - k + 1;
            if (s[left] == 'a' || s[left] == 'e' || s[left] == 'i' ||
                s[left] == 'o' || s[left] == 'u')
                cnt--;
        }
        return ans;
    }
};
```



# 前缀和

模板题：

[303. 区域和检索 - 数组不可变](https://leetcode.cn/problems/range-sum-query-immutable/)

s[0]=0特殊处理；

s[i+1]=s[i]+nums[i]；

nums[left]到nums[right]的元素和为s[right+1]-s[left]；



问次数，哈希表存次数

问长度，哈希表存下标



两次遍历

```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> s(n + 1);
        for (int i = 0; i < n; i++) {
            s[i + 1] = s[i] + nums[i];
        }

        int ans = 0;
        unordered_map<int, int> cnt;
        for (int sj : s) {
            // 注意不要直接 += cnt[sj-k]，如果 sj-k 不存在，会插入 sj-k
            ans += cnt.contains(sj - k) ? cnt[sj - k] : 0;
            cnt[sj]++;
        }
        return ans;
    }
};
```



一次遍历

```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, s = 0;
        unordered_map<int, int> cnt{{0, 1}}; // s[0]=0 单独统计
        for (int x : nums) {
            s += x;
            // 注意不要直接 += cnt[s-k]，如果 s-k 不存在，会插入 s-k
            ans += cnt.contains(s - k) ? cnt[s - k] : 0;
            cnt[s]++;
        }
        return ans;
    }
};
```

