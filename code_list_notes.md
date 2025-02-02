[toc]

## 模板

[XX](XX)

### 1. 题目描述

### 2. 思路

### 3. 易错点

### 4. 题解

1）

```cpp

```

2）



hot100



# 一、哈希

## 1. 两数之和

[1. 两数之和](https://leetcode.cn/problems/two-sum/)

### 1. 题目描述

给定一个整数数组 `nums` 和一个整数目标值 `target`，请你在该数组中找出 **和为目标值** *`target`* 的那 **两个** 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。你可以按任意顺序返回答案。

**示例 1：**

```
输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
```

**示例 2：**

```
输入：nums = [3,2,4], target = 6
输出：[1,2]
```

**示例 3：**

```
输入：nums = [3,3], target = 6
输出：[0,1]
```

**提示：**

- `2 <= nums.length <= 10^4`
- `-10^9 <= nums[i] <= 10^9`
- `-10^9 <= target <= 10^9`
- **只会存在一个有效答案**



**进阶：**你可以想出一个时间复杂度小于 $O(n^2)$ 的算法吗？



### 2. 思路

1）暴力求解

双重for循环，判断两层循环对应的元素之和是否为target。

Time: O(N^2), Space: O(1)

2）哈希表

建立哈希表，存储元素值与其索引值。先查找是否有target-num，再将不在哈希表中的元素加入到哈希表。

Time: O(N), Space:O(N)

### 3. 易错点

1）注意审题，返回的是索引下标。

2）要先查找，后插入。

### 4. 题解

1）暴力求解

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         for (int i = 0; i < nums.size()-1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                    return {i,j};
            }
        }
        return {0};
    }
};
```

2）哈希表

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*
        思路：哈希表
        Time: O(N), Space:O(N)
        */
        unordered_map<int, int> dic;
        for (int i = 0; i < nums.size(); i++) {
            auto it = dic.find(target - nums[i]);
            if (it == dic.end()) {
                dic[nums[i]] = i;
            } else {
                return {i, it->second};
            }
        }
        return {};
    }
};
```



## 49. 字母异位词分组

[49. 字母异位词分组](https://leetcode.cn/problems/group-anagrams/)

### 1. 题目描述

给你一个字符串数组，请你将 **字母异位词** 组合在一起。可以按任意顺序返回结果列表。

**字母异位词** 是由重新排列源单词的所有字母得到的一个新单词。

**示例 1:**

```
输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
```

**示例 2:**

```
输入: strs = [""]
输出: [[""]]
```

**示例 3:**

```
输入: strs = ["a"]
输出: [["a"]]
```

**提示：**

- `1 <= strs.length <= 10^4`
- `0 <= strs[i].length <= 100`
- `strs[i]` 仅包含小写字母

### 2. 思路

1）字符串排序+哈希表：将所有的异位词按字母大小排序后可以得到相同的单词。因此，key存放排序后的单词字符串，value存放异位词。

2）计数：统计每个单词中26个字母出现的次数，作为哈希表的键。



### 3. 易错点

ans.push_back(item.second);

注意是value，不是ans.push_back(item);



### 4. 题解

1）哈希表

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /*
        思路：哈希表
        Time: O(n klogk), Space: O(nk), n=strs.size(), k=max(str.length)
        */
        unordered_map<string, vector<string>> dic;
        for (auto str : strs) {
            // 先对所有的字符串进行排序
            string sort_str = str;
            sort(sort_str.begin(), sort_str.end());
            // 并将其存储到对应的哈希表键值对中
            dic[sort_str].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto item : dic) {
            ans.push_back(item.second);
            // 注意是value，不是ans.push_back(item);
        }
        return ans;
    }
};
```

2）

```cpp
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        for(string str:strs) {
            int counts[26] = {0};
            for(char c:str) {
                counts[c-'a']++;
            }
            string key = "";
            for(int i = 0;i<26;++i) {
                if(counts[i]!=0) {
                    key.push_back(i+'a');
                    key.push_back(counts[i]);
                }
            }
            map[key].push_back(str);
        }
        vector<vector<string>> res;
        for(auto& p:map) {
            res.push_back(p.second);
        }
        return res;
    }
};
```



## 128. 最长连续序列

[128. 最长连续序列](https://leetcode.cn/problems/longest-consecutive-sequence/)

### 1. 题目描述

给定一个未排序的整数数组 `nums` ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。请你设计并实现时间复杂度为 `O(n)` 的算法解决此问题。

**示例 1：**

```
输入：nums = [100,4,200,1,3,2]
输出：4
解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
```

**示例 2：**

```
输入：nums = [0,3,7,2,5,8,4,6,0,1]
输出：9
```

**提示：**

- `0 <= nums.length <= 10^5`
- `-10^9 <= nums[i] <= 10^9`

### 2. 思路

1）哈希集合

核心思路：对于 `nums` 中的元素 `x`，以 `x` 为起点，不断查找下一个数 `x+1`,`x+2`,⋯ 是否在 `nums` 中，并统计序列的长度。

把 `nums`中的数都放入一个哈希集合中，这样可以 O(1) 判断数字是否在 `nums`中。
如果 `x−1` 在哈希集合中，则不以 `x` 为起点。为什么？因为以 `x−1` 为起点计算出的序列长度，一定比以 `x` 为起点计算出的序列长度要长！这样可以避免大量重复计算。比如 `nums=[3,2,4,5]`，从 3 开始，我们可以找到 3,4,5 这个连续序列；而从 2 开始，我们可以找到 2,3,4,5 这个连续序列，一定比从 3 开始的序列更长。



### 3. 易错点

哈希集合，解题思路。

遍历哈希集合，不是遍历原nums。

### 4. 题解

1）哈希集合

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // 利用集合去除重复元素
        unordered_set<int> num;
        for(auto i:nums)
            num.insert(i); //注意是insert()不是push_back()
        
        // 优化写法：把 nums 转成哈希集合
        unordered_set<int> st(nums.begin(), nums.end());
        
        // 记录最长的序列长度
        int maxlength=0;
        // 记录当前序列长度
        int curlength=0;
        for(auto i:num){
            // 如果当前元素i的前一个元素i-1存在，则放弃该元素
            // 如果前一个元素不存在，则从当前元素开始计数
            if(!num.count(i-1)){
                int curnum=i; // 记录元素值
                curlength=1; // 初始化序列长度
                while(num.count(curnum+1)){ 
                    //当前元素的下一元素存在
                    curnum++;
                    curlength++;
                }
                maxlength=max(maxlength,curlength);
            }
            
        }
        return maxlength;
    }
};
```



```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        // 把 nums 转成哈希集合
        unordered_set<int> st(nums.begin(), nums.end()); 
        for (int x : st) { // 遍历哈希集合
            if (st.contains(x - 1)) {
                continue;
            }
            // x 是序列的起点
            int y = x + 1;
            while (st.contains(y)) { // 不断查找下一个数是否在哈希集合中
                y++;
            }
            // 循环结束后，y-1 是最后一个在哈希集合中的数
            ans = max(ans, y - x); // 从 x 到 y-1 一共 y-x 个数
        }
        return ans;
    }
};
```



# 十七、技巧

## * 资料汇总

常用的位运算
x & (-x)：保留 x 的二进制表达式中最低位的 1，其余位置 0（即 x 最大的 2 次方因子）
x & (x-1)：消除 x 的二进制表达式中最低位的 1，其余保持不变
(x>>i) & 1 或者 x & (1<<i)：获取 x 的二进制表达式中的第 i 位数字，最常用的是取二进制下的最末位，即x & 1，用于判断奇偶
x = x|(1<<i)：设置第 i 位为 1
x = x & (~(1<<i))：设置第 i 位为 0
x = x ^ (1<<i)：将第 i 位取反



灵茶山艾府总结：[从集合论到位运算，常见位运算技巧分类总结！](https://leetcode.cn/circle/discuss/CaOJ45/)

灵茶山艾府题单：[分享丨【题单】位运算（基础/性质/拆位/试填/恒等式/思维](https://leetcode.cn/circle/discuss/dHn9Vk/)



## 136. 只出现一次的数字

[136.只出现一次的数字](https://leetcode.cn/problems/single-number/)

### 0. 类型

位运算。

### 1. 题目描述

给你一个 **非空** 整数数组 `nums` ，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。

**示例 1 ：**

```
输入：nums = [2,2,1]
输出：1
```

**示例 2 ：**

```
输入：nums = [4,1,2,1,2]
输出：4
```

**示例 3 ：**

```
输入：nums = [1]
输出：1
```

**提示：**

- `1 <= nums.length <= 3 * 10^4`
- `-3 * 10^4 <= nums[i] <= 3 * 10^4`
- 除了某个元素只出现一次以外，其余每个元素均出现两次。

### 2. 思路

你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。

题目要求时间复杂度O(N)，空间复杂度O(1)。

不考虑==空间复杂度==的限制，这道题有很多种解法，可能的解法有如下几种。

- 使用集合存储数字。遍历数组中的每个数字，如果集合中没有该数字，则将该数字加入集合，如果集合中已经有该数字，则将该数字从集合中删除，最后剩下的数字就是只出现一次的数字。

- 使用哈希表存储每个数字和该数字出现的次数。遍历数组即可得到每个数字出现的次数，并更新哈希表，最后遍历哈希表，得到只出现一次的数字。

- 使用集合存储数组中出现的所有数字，并计算数组中的元素之和。由于集合保证元素无重复，因此计算集合中的所有元素之和的两倍，即为每个元素出现两次的情况下的元素之和。由于数组中只有一个元素出现一次，其余元素都出现两次，因此用集合中的元素之和的两倍减去数组中的元素之和，剩下的数就是数组中只出现一次的数字。


常数空间复杂度限制，选取位运算，本题目利用异或运算 $⊕$ 。

**异或运算的性质**：

- 任何数和 0 做异或运算，结果仍然是原来的数，即 $a⊕0=a$。
- 任何数和其自身做异或运算，结果是 0，即 $a⊕a=0$。
- 异或运算满足交换律和结合律，即 $a⊕b⊕a=b⊕a⊕a=b⊕(a⊕a)=b⊕0=b$。

**思路证明：**

假设数组中有 $2m+1$ 个数，其中有 $m$ 个数各出现两次，一个数出现一次。令 $ a_1、a_2、...、a_m$为出现一次的数。根据性质 3，数组中的全部元素的异或运算结果总是可以写成如下形式：

$(a_1⊕a_1)⊕(a_2⊕a_2)⊕...⊕(a_m⊕a_m)⊕a_{m+1}$


根据性质 2 和性质 1，上式可化简和计算得到如下结果：

$0⊕0⊕⋯⊕0⊕a_{m+1}=a_{m+1}$


因此，数组中的全部元素的异或运算结果即为数组中只出现一次的数字。



### 3. 易错点



### 4. 题解

1）异或运算，时间复杂度：O(N)，空间复杂度：O(1)

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /*
        思路：将所有元素进行异或运算
        Time:O(N), Space:O(1)
        */
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
            ans = ans ^ nums[i];
        return ans;
    }
};
```



2）哈希表计数，时间复杂度：O(N)，空间复杂度：O(N)

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /*
        思路：利用哈希表，记录每个元素出现的次数，最后查找出现次数为1的元素。
        Time:O(N), Space:O(N)
        */
        unordered_map<int, int> dic;
        for (int i = 0; i < nums.size(); i++) {
            // 元素第一次出现，计数器为 1
            if (dic.count(nums[i]) == 0)
                dic[nums[i]] = 1;
            // 元素已经出现过，计数器++
            else
                dic[nums[i]]++;
        }
        for (auto it : dic) {
            // 查找计数器次数(value)为1的元素(key)
            if (it.second == 1)
                return it.first;
        }
        return 0;
    }
};
```

### 5. 延申







#### 268. 丢失的数字 [easy]

 https://leetcode.cn/problems/missing-number/description/

**题目描述：**给定一个包含 `[0, n]` 中 `n` 个数的数组 `nums` ，找出 `[0, n]` 这个范围内没有出现在数组中的那个数。

**思路：**

1）排序：排序后遍历找到缺少的元素

2）哈希表：统计出现次数，找缺少的元素

3）位运算：补上0-n的元素，将2n+1个元素进行异或运算

4）数学运算：0-n利用等差数列求和，减去现有元素之和



#### 137. 只出现一次的数字 II [medium]

https://leetcode.cn/problems/single-number-ii/description/

**题目描述：**给你一个整数数组 `nums` ，除某个元素仅出现 **一次** 外，其余每个元素都恰出现 **三次 。**请你找出并返回那个只出现了一次的元素。你必须设计并实现线性时间复杂度的算法且使用常数级空间来解决此问题。

**示例 1：**

```
输入：nums = [2,2,3,2]
输出：3
```

**示例 2：**

```
输入：nums = [0,1,0,1,0,1,99]
输出：99
```

**提示：**

- `1 <= nums.length <= 3 * 104`
- `-231 <= nums[i] <= 231 - 1`
- `nums` 中，除某个元素仅出现 **一次** 外，其余每个元素都恰出现 **三次**



**思路：**

1）哈希表：统计出现次数，最后遍历，查找只出现了一次的元素

2）位运算：答案的第 i 个二进制位（i 从 0 开始编号），它可能为 0 或 1。对于数组中非答案的元素，每一个元素都出现了 3 次，对应着第 i 个二进制位的 3 个 0 或 3 个 1，无论是哪一种情况，它们的和都是 3 的倍数（即和为 0 或 3）。因此：答案的第 i 个二进制位就是数组中所有元素的第 i 个二进制位之和除以 3 的余数。这样一来，对于数组中的每一个元素 x，我们使用位运算 (x >> i) & 1 得到 x 的第 i 个二进制位，并将它们相加再对 3 取余，得到的结果一定为 0 或 1，即为答案的第 i 个二进制位。

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            // 计算每一个二进制位的和
            int xor_all = 0;
            for (auto num : nums) {
                // 得到 num 的第 i 个二进制位
                xor_all += ((num >> i) & 1);
            }
            // 将二进制位的和模3，答案是ans的第i个二进制位的值
            if (xor_all % 3 != 0)
                ans += 1 << i;
        }
        return ans;
    }
};
```

3）==数电逻辑转换，画真值表，写逻辑表达式。==

同时计算a和b

```cpp
class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int a = 0, b = 0;
        for (int x: nums) {
            int tmp_a = a;
            a = (a ^ x) & (a | b);
            b = (b ^ x) & ~tmp_a;
        }
        return b;
    }
};
```

先计算b，用新的b计算a

```cpp
class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int a = 0, b = 0;
        for (int x: nums) {
            b = (b ^ x) & ~a;
            a = (a ^ x) & ~b;
        }
        return b;
    }
};
```



#### 260. 只出现一次的数字 III [medium]

https://leetcode.cn/problems/single-number-iii/

**题目描述：**给你一个整数数组 `nums`，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。你可以按 **任意顺序** 返回答案。你必须设计并实现线性时间复杂度的算法且仅使用常量额外空间来解决此问题。

**示例 1：**

```
输入：nums = [1,2,1,3,2,5]
输出：[3,5]
解释：[5, 3] 也是有效的答案。
```

**思路：**

1）哈希表：统计出现次数，最后遍历，查找只出现了一次的元素

2）位运算+==分组==：将所有元素进行异或，得到$x=x_1⊕x_2$，利用位运算 $x$&$(-x)$  得到最低位 $l$ 的 1，则$x_1$与$x_2$一个最低位 $l$ 为 0，一个为 1。这样一来，我们就可以把 nums 中的所有元素分成两类，其中一类包含所有二进制表示的第 $l$ 位为 0 的数，另一类包含所有二进制表示的第 $l$ 位为 1 的数。可以发现：

- 对于任意一个在数组 nums 中出现两次的元素，该元素的两次出现会被包含在同一类中；

- 对于任意一个在数组 nums 中只出现了一次的元素，即 $x_1$与$x_2$ ，它们会被包含在不同类中。

因此，如果我们将每一类的元素全部异或起来，那么其中一类会得到 $x_1$ ，另一类会得到 $x_2$。这样我们就找出了这两个只出现一次的元素。

```cpp
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // vector<int> ans; 会报错
        // 初始化！！！
        vector<int> ans(2);
        unsigned int xor_all = 0;
        // 1. 计算所有数字的异或和
        for (int num : nums) {
            xor_all ^= num;
        }
        // 2. 计算异或和中最低位的1，即x1与x2最低不同的位
        // tips: 负数在计算机中以补码的形式存储
        int lowbit = xor_all & -xor_all;
        // 3. 分组异或得到x1和x2
        for (int num : nums) {
            ans[(num & lowbit) != 0] ^= num;
        }
        return ans;
    }
};
```

易错点：初始化vector

## 169. 多数元素

[169.多数元素](https://leetcode.cn/problems/majority-element/)

### 1. 题目描述

给定一个大小为 `n` 的数组 `nums` ，返回其中的多数元素。多数元素是指在数组中出现次数 **大于** `⌊ n/2 ⌋` 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

 **示例 1：**

```
输入：nums = [3,2,3]
输出：3
```

**示例 2：**

```
输入：nums = [2,2,1,1,1,2,2]
输出：2
```

 **提示：**

- `n == nums.length`
- `1 <= n <= 5 * 104`
- `-109 <= nums[i] <= 109`

 

**进阶：**尝试设计时间复杂度为 O(n)、空间复杂度为 O(1) 的算法解决此问题。

### 2. 思路

1）库函数排序，返回中位数

​	>> 不符合进阶时间复杂度要求

2）哈希表记录出现的次数

​	>> 不符合进阶空间复杂度要求

3）Boyer-Moore 投票算法

如果我们把众数记为 +1，把其他数记为 −1，将它们全部加起来，显然和大于 `0`，从结果本身我们可以看出众数比其他数多。

Boyer-Moore 算法的详细步骤：

- 我们维护一个候选众数 `candidate` 和它出现的次数 `count`。初始时 `candidate` 可以为任意值，`count` 为 0；

- 我们遍历数组 `nums` 中的所有元素，对于每个元素 `x`，在判断 `x` 之前，如果` count` 的值为 0，我们先将 `x`的值赋予 `candidate`，随后我们判断 `x`：

- 如果 `x` 与 `candidate` 相等，那么计数器 `count` 的值增加 1；

- 如果 `x` 与 `candidate` 不等，那么计数器 `count` 的值减少 1。

- 在遍历完成后，`candidate` 即为整个数组的众数。




### 3. 易错点

num!=candidate的操作，要判断cnt是否为0

### 4. 题解

1）排序

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /* 排序 */
        /* Time: O(nlogn) Space: O(logn)*/
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};
```

2）哈希表 

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /* 哈希映射 */
        /* Time: O(n) Space: O(n)*/
        unordered_map<int, int> nums_cnt;
        int maxcnt = 0, maxval = 0;
        for (int i = 0; i < nums.size(); i++) {
            nums_cnt[nums[i]]++;
            if (nums_cnt[nums[i]] > maxcnt) {
                maxval = nums[i];
                maxcnt = nums_cnt[nums[i]];
            }
        }
        return maxval;
    }
};
```

3）Boyer-Moore 投票算法

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*
        思路：Boyer-Moore 投票算法
        Time:O(N), Space:O(1)
        */
        int candidate = -1;
        int count = 0;
        for (int num : nums) {
            // 如果当前元素与候选元素一致，则计数器++
            if (num == candidate)
                count++;
            // 当前元素与候选元素不一致
            else {
                // 如果候选元素数量为0，则当前元素变为候选元素
                if (count == 0)
                    candidate = num;
                else
                    // 否则“同归于尽”
                    count--;
            }
        }
        return candidate;
    }
};
```

### 5. 延申

#### 229. 多数元素II [medium]

https://leetcode.cn/problems/majority-element-ii/

题目描述：给定一个大小为 *n* 的整数数组，找出其中所有出现超过 `⌊ n/3 ⌋` 次的元素。

 **示例 1：**

```
输入：nums = [3,2,3]
输出：[3]
```

**示例 2：**

```
输入：nums = [1]
输出：[1]
```

**示例 3：**

```
输入：nums = [1,2]
输出：[1,2]
```

**提示：**

- `1 <= nums.length <= 5 * 10^4`
- `-10^9 <= nums[i] <= 10^9`



思路：

1）哈希表：遍历统计所有元素出现的次数，最后遍历寻找次数超过n/3的元素

2）摩尔投票法：最多有两个元素数量>n/3，因此设定两个候选和两个计数器。



```cpp
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        /*
        思路：摩尔投票法，数量超过n/3的元素最多有2个
        Time:O(N), Space:O(1)
        */
        vector<int> ans;
        // 数量超过n/3的元素最多有2个！！
        int winner1 = 0, winner2 = 0;
        int cnt1 = 0, cnt2 = 0;
        for (auto num : nums) {
            // 1. 判断新元素是否属于现有的两个阵营，是则加入
            if (cnt1 > 0 && num == winner1) {
                cnt1++;
            } else if (cnt2 > 0 && num == winner2) {
                cnt2++;
            }
            // 2. 判断是否有可以捡漏的阵营
            else if (cnt1 == 0) {
                winner1 = num;
                cnt1++;
            } else if (cnt2 == 0) {
                winner2 = num;
                cnt2++;
            }
            // 3. 否则三方厮杀，两个阵营各减少一个士兵
            else {
                cnt1--;
                cnt2--;
            }
        }
        // 5. 对最终剩下的两个阵营进行士兵的数量统计
        int sum1 = 0, sum2 = 0;
        for (auto num : nums) {
            if (cnt1 > 0 && num == winner1)
                sum1++;
            else if (cnt2 > 0 && num == winner2)
                sum2++;
        }
        // 6. 最终阵营有士兵，且总数大于n/3，则加入到答案中
        if (cnt1 > 0 && sum1 > nums.size() / 3)
            ans.push_back(winner1);
        if (cnt2 > 0 && sum2 > nums.size() / 3)
            ans.push_back(winner2);
        return ans;
    }
};
```



## 31. 下一个排列

### 1. 题目描述

### 2. 思路

### 3. 易错点

### 4. 题解

1）

```cpp

```

2）











// 150题

## 数组字符串

### 88 合并有序数组

[88. 合并两个有序数组](https://leetcode.cn/problems/merge-sorted-array/)

0. 类型

数组，双指针。

#### 1. 题目描述

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

#### 2. 思路

1）暴力求解：先合并，再用sort()

2）双指针从头遍历，依次取最小的

3）双指针从尾遍历，依次取最大的

#### 3. 易错点

1）注意 `nums1.size() != m`，不能 `nums1.push_back(nums2[i])`。

2）假设 `nums1.size() == m `，即末尾不补0，需要先 `nums1.resize(m + n)`，再 `nums1[m+i] = nums2[i]`。

3）`i < m && j < n`，不是 `i < m ,j < n`，`j < n` 的结果决定循环是否继续，`i < m` 只是被求值，不影响循环条件。

4）`nums1[i + j + 1] = nums1[i--]` 左边的i是自减后的，需要另设一个变量；不要等号左右同属出现 `i++`，`i--`。

#### 4. 题解

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

### 27 移除元素

[27. 移除元素](https://leetcode.cn/problems/remove-element/)

#### 0. 类型

数组。

#### 1. 题目描述

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

#### 2. 思路

1）另开存储空间，单独存储  `!=val` 的元素。

2）双指针，将前面为val的元素与后面非val的元素进行位置交换。

3）双指针优化，一个头一个尾。

#### 3. 易错点

暂无。

#### 4. 题解

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

### 26 删除有序数组的重复项

[26. 删除有序数组中的重复项](https://leetcode.cn/problems/remove-duplicates-from-sorted-array/)

#### 0. 类型

数组。

#### 1. 题目描述

给你一个 **非严格递增排列** 的数组 `nums` ，请你 **原地** 删除重复出现的元素，使每个元素 **只出现一次** ，返回删除后数组的新长度。元素的 **相对顺序** 应该保持 **一致** 。然后返回 `nums` 中唯一元素的个数。

考虑 `nums` 的唯一元素的数量为 `k` ，你需要做以下事情确保你的题解可以被通过：

* 更改数组 `nums` ，使 `nums` 的前 `k` 个元素包含唯一元素，并按照它们最初在 `nums` 中出现的顺序排列。`nums` 的其余元素与 `nums` 的大小不重要。
* 返回 `k` 。

**判题标准:**

系统会用下面的代码来测试你的题解:

```
int[] nums = [...]; // 输入数组
int[] expectedNums = [...]; // 长度正确的期望答案

int k = removeDuplicates(nums); // 调用

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
```

如果所有断言都通过，那么您的题解将被  **通过** 。

#### 2. 思路

双指针。由于给定的数组 `nums` 是有序的，因此对于任意 `i<j`，如果 `nums[i]=nums[j]`，则对任意 ` i≤k≤j`，必有 ` nums[i]=nums[k]=nums[j]`，即相等的元素在数组中的下标一定是连续的。利用数组有序的特点，可以通过双指针的方法删除重复元素。

slow指向上一个非重复元素，fast指向下一个非重复元素。

当fast与slow的元素不一样，说明找到了新出现的非重复元素。

则将slow++，指向下一个可覆盖位置。

赋值。

slow++，记录新的元素，fast++继续寻找下一个不重复的。

#### 3. 易错点

暂无。

#### 4. 题解

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
