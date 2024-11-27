[toc]

## 88 合并有序数组

[88. 合并两个有序数组](https://leetcode.cn/problems/merge-sorted-array/)

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

4）`nums1[i + j + 1] = nums1[i--]` 左边的i是自减后的，需要另设一个变量；不要等号左右同属出现 `i++`，`i--`。

### 4. 题解

```cpp
void merge1(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    /* 使用sort函数 Time: O((m+n)log(m+n)) Space: O(log(m+n)) */
    for (int i = 0; i < n; i++)
    {
        nums1[m + i] = nums2[i];
    }
    sort(nums1.begin(), nums1.end());
}
```



```cpp
void merge2(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    /* 双指针遍历 Time: O(m+n) Space: O(m+n) */
    int i = 0, j = 0;
    vector<int> sorted;
    for (; i < m || j < n;) {
        if (i == m) {
            sorted.push_back(nums2[j]);
            j++;
        }
        else if (j == n) {
            sorted.push_back(nums1[i]);
            i++;
        }
        else if (nums1[i] <= nums2[j]) {
            sorted.push_back(nums1[i]);
            i++;
        }
        else if (nums1[i] > nums2[j]) {
            sorted.push_back(nums2[j]);
            j++;
        }
    }
    for (int k = 0; k < m + n; k++)
        nums1[k] = sorted[k];
}
```


```cpp
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    /* 双尾指针遍历 Time: O(m+n) Space: O(1) */
    int i = m - 1, j = n - 1;
    int tail = i + j + 1;
    vector<int> sorted;
    for (; i >= 0 || j >= 0;) {
        if (i == -1 && j != -1)
            nums1[j--] = nums2[j--];
        // nums2全填进去后，nums1剩余部分有序
        else if (j == -1)
            break;
        else if (nums1[i] > nums2[j]) {
            // nums1[i + j + 1] = nums1[i--];
            // 不要用复合运算
            nums1[i + j + 1] = nums1[i];
            i--;
        }
        else if (nums1[i] <= nums2[j]) {
            nums1[i + j + 1] = nums2[j];
            j--;
        }
    }
}
```


## 27 移除元素

[27. 移除元素](https://leetcode.cn/problems/remove-element/)


### 0. 类型

数组。

### 1. 题目描述

给你一个数组 `nums` 和一个值 `val`，你需要 **[原地](https://baike.baidu.com/item/%E5%8E%9F%E5%9C%B0%E7%AE%97%E6%B3%95)** 移除所有数值等于 `val` 的元素。元素的顺序可能发生改变。然后返回 `nums` 中与 `val` 不同的元素的数量。

假设 `nums` 中不等于 `val` 的元素数量为 `k`，要通过此题，您需要执行以下操作：

* 更改 `nums` 数组，使 `nums` 的前 `k` 个元素包含不等于 `val` 的元素。`nums` 的其余元素和 `nums` 的大小并不重要。
* 返回 `k`。

**用户评测：**

评测机将使用以下代码测试您的解决方案：

```cpp
int[] nums = [...]; // 输入数组
int val = ...; // 要移除的值
int[] expectedNums = [...]; // 长度正确的预期答案。
                            // 它以不等于 val 的值排序。

int k = removeElement(nums, val); // 调用你的实现

assert k == expectedNums.length;
sort(nums, 0, k); // 排序 nums 的前 k 个元素
for (int i = 0; i < actualLength; i++) {
    assert nums[i] == expectedNums[i];
}
```

如果所有的断言都通过，你的解决方案将会  **通过** 。

**示例 1：**

<pre><strong>输入：</strong>nums = [3,2,2,3], val = 3
<strong>输出：</strong>2, nums = [2,2,_,_]
<strong>解释：</strong>你的函数函数应该返回 k = 2, 并且 nums<em></em>中的前两个元素均为 2。
你在返回的 k 个元素之外留下了什么并不重要（因此它们并不计入评测）。</pre>

**示例 2：**

<pre><strong>输入：</strong>nums = [0,1,2,2,3,0,4,2], val = 2
<strong>输出：</strong>5, nums = [0,1,4,0,3,_,_,_]
<strong>解释：</strong>你的函数应该返回 k = 5，并且 nums 中的前五个元素为 0,0,1,3,4。
注意这五个元素可以任意顺序返回。
你在返回的 k 个元素之外留下了什么并不重要（因此它们并不计入评测）。
</pre>

**提示：**

* `0 <= nums.length <= 100`
* `0 <= nums[i] <= 50`
* `0 <= val <= 100`

### 2. 思路

1）另开存储空间，单独存储  `!=val` 的元素。

2）双指针，将前面为val的元素与后面非val的元素进行位置交换。

3）双指针优化，一个头一个尾。

### 3. 易错点

暂无。

### 4. 题解

```cpp
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
```


```cpp
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
```


```cpp
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
```


## 26 删除有序数组的重复项

[26. 删除有序数组中的重复项](https://leetcode.cn/problems/remove-duplicates-from-sorted-array/)

### 0. 类型

数组。

### 1. 题目描述



### 2. 思路

双指针。由于给定的数组 `nums` 是有序的，因此对于任意 `i<j`，如果 `nums[i]=nums[j]`，则对任意 ` i≤k≤j`，必有 ` nums[i]=nums[k]=nums[j]`，即相等的元素在数组中的下标一定是连续的。利用数组有序的特点，可以通过双指针的方法删除重复元素。

slow指向上一个非重复元素，fast指向下一个非重复元素。

当fast与slow的元素不一样，说明找到了新出现的非重复元素。

则将slow++，指向下一个可覆盖位置。

赋值。

slow++，记录新的元素，fast++继续寻找下一个不重复的。


### 3. 易错点

暂无。

### 4. 题解

```cpp
int removeDuplicates(vector<int> &nums)
{
    int slow = 0, fast = 1;
    while (fast < nums.size())
    {
        // fast 去寻找下一个出现的新元素
        // slow 指向当前非重复的最后一个元素
        if (nums[slow] != nums[fast])
        {
            // 当找到新的元素
            slow++;                  // 指向下一个可覆盖的位置
            nums[slow] = nums[fast]; // 覆盖
            fast++;                  // 寻找下一个和当前不重复的元素
        }
        else if (nums[slow] == nums[fast])
        {
            // 重复，继续往后找
            fast++;
        }
    }
    return slow + 1;
}
```
