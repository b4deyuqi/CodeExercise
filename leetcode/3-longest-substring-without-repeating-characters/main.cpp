#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring1(string s)
{
    // 官解
    /* 滑动窗口 Time: O(N) Space: O(s.size())*/
    // 利用哈希集合记录出现过的字符
    unordered_set<char> dic;
    int maxlen = 0;
    // 初始化左右指针，左指针指向当前滑动窗口的一个元素，右指针进行探索
    for (int left = 0, right = -1; left < s.size(); left++)
    {
        // 如果不是第一个元素，则将左指针指向的元素移除
        if (left != 0)
        {
            dic.erase(s[left - 1]);
        }
        // 右指针指向上一次结束的位置
        // 如果下一个元素不是重复的，则移动右指针
        // 【注意边界判断！！！】
        while (right + 1 < s.size() && dic.count(s[right + 1]) == 0)
        {
            dic.insert(s[right + 1]);
            right++;
        }
        // 记录当前滑动窗口的大小
        maxlen = max(maxlen, (right - left + 1));
    }
    return maxlen;
}

int lengthOfLongestSubstring(string s)
{
    /* 滑动窗口 Time: O(N) Space: O(s.size())*/
    // 利用哈希集合记录出现过的字符
    unordered_set<char> dic;
    int maxlen = 0;
    // 初始化左右指针，左指针指向当前滑动窗口的一个元素，右指针进行探索
    for (int left = 0, right = -1; left < s.size(); left++)
    {
        // 右指针指向上一次结束的位置
        // 如果下一个元素不是重复的，则移动右指针
        // 【注意边界判断！！！】
        while (right + 1 < s.size() && dic.count(s[right + 1]) == 0)
        {
            dic.insert(s[right + 1]);
            right++;
        }
        // 记录当前滑动窗口的大小
        maxlen = max(maxlen, (right - left + 1));
        // 将左指针指向的元素移除
        dic.erase(s[left]);
    }
    return maxlen;
}

int lengthOfLongestSubstring(string s)
{
    /* 滑动窗口 Time: O(N) Space: O(s.size())*/
    // 利用哈希集合记录出现过的字符
    unordered_set<char> dic;
    int maxlen = 0;
    // 初始化左右指针，右指针指向要新加入的元素，左指针滑动
    for (int right = 0, left = 0; right < s.size(); right++)
    {
        // while (dic.contains(s[right])) // Cpp20
        while (dic.count(s[right]) != 0)
        {
            // 当前窗口包含与右指针相同的元素，则一直将左指针右移
            // 直到不存在重复的元素
            dic.erase(s[left]); // 不是right
            left++;
        }
        dic.insert(s[right]);
        maxlen = max(maxlen, right - left + 1);
    }
    return maxlen;
}

int main()
{
    int ans = 0;
    string s;
    cin >> s;
    ans = lengthOfLongestSubstring(s);
    cout << ans;
    return 0;
}