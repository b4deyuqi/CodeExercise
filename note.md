[toc]



## 88 merge sorted arrays

https://leetcode.cn/problems/merge-sorted-array/?envType=study-plan-v2&envId=top-interview-150


### 0. 类型

数组，双指针。

### 1. 题目描述

给你两个按 **非递减顺序** 排列的整数数组 `nums1` 和 `nums2`，另有两个整数 `m` 和 `n` ，分别表示 `nums1` 和 `nums2` 中的元素数目。

请你 **合并** `nums2` 到 `nums1` 中，使合并后的数组同样按 **非递减顺序** 排列。

 **注意：** 最终，合并后数组不应由函数返回，而是存储在数组 `nums1` 中。为了应对这种情况，`nums1` 的初始长度为 `m + n`，其中前 `m` 个元素表示应合并的元素，后 `n` 个元素为 `0` ，应忽略。`nums2` 的长度为 `n` 。

**示例 1：**

<pre><strong>输入：</strong>nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
<strong>输出：</strong>[1,2,2,3,5,6]
<strong>解释：</strong>需要合并 [1,2,3] 和 [2,5,6] 。
合并结果是 [<em><strong>1</strong></em>,<em><strong>2</strong></em>,2,<em><strong>3</strong></em>,5,6] ，其中斜体加粗标注的为 nums1 中的元素。
</pre>

**示例 2：**

<pre><strong>输入：</strong>nums1 = [1], m = 1, nums2 = [], n = 0
<strong>输出：</strong>[1]
<strong>解释：</strong>需要合并 [1] 和 [] 。
合并结果是 [1] 。
</pre>

**示例 3：**

<pre><strong>输入：</strong>nums1 = [0], m = 0, nums2 = [1], n = 1
<strong>输出：</strong>[1]
<strong>解释：</strong>需要合并的数组是 [] 和 [1] 。
合并结果是 [1] 。
注意，因为 m = 0 ，所以 nums1 中没有元素。nums1 中仅存的 0 仅仅是为了确保合并结果可以顺利存放到 nums1 中。
</pre>

**提示：**

* `nums1.length == m + n`
* `nums2.length == n`
* `0 <= m, n <= 200`
* `1 <= m + n <= 200`
* `-10<sup>9</sup> <= nums1[i], nums2[j] <= 10<sup>9</sup>`

### 2. 思路

1）暴力求解：先合并，再用sort()

2）双指针从头遍历，依次取最小的

3）双指针从尾遍历，依次取最大的

### 3. 易错点

1）注意 `nums1.size() != m`，不能 `nums1.push_back(nums2[i])`。

2）假设 `nums1.size() == m `，即末尾不补0，需要先 `nums1.resize(m + n)`，再 `nums1[m+i] = nums2[i]`。

3）`i < m && j < n`，不是 `i < m ,j < n`，`j < n` 的结果决定循环是否继续，`i < m` 只是被求值，不影响循环条件。

4）`nums1[i + j + 1] = nums1[i--]` 左边的i是自减后的，需要另设一个变量；

### 4. 题解(ACM)

```cpp

```
