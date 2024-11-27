#include <iostream>
#include <bits/stdc++.h>
// #include<vector>
// #include<algorithm>
using namespace std;

void merge1(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    /* 使用sort函数 Time: O((m+n)log(m+n)) Space: O(log(m+n)) */
    for (int i = 0; i < n; i++)
    {
        // nums1.push_back(nums2[i]);
        // nums1的size没有改变，需要先resize
        // nums1.resize(m + n);
        nums1[m + i] = nums2[i];
    }
    sort(nums1.begin(), nums1.end());
}

void merge2(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    /* 双指针遍历 Time: O(m+n) Space: O(m+n) */
    int i = 0, j = 0;
    vector<int> sorted;
    for (; i < m || j < n;)
    {
        if (i == m)
        {
            sorted.push_back(nums2[j]);
            j++;
        }
        else if (j == n)
        {
            sorted.push_back(nums1[i]);
            i++;
        }
        else if (nums1[i] <= nums2[j])
        {
            sorted.push_back(nums1[i]);
            i++;
        }
        else if (nums1[i] > nums2[j])
        {
            sorted.push_back(nums2[j]);
            j++;
        }
    }
    for (int k = 0; k < m + n; k++)
    {
        nums1[k] = sorted[k];
    }
}
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    /* 双尾指针遍历 Time: O(m+n) Space: O(1) */
    int i = m - 1, j = n - 1;
    int tail = i + j + 1;
    vector<int> sorted;
    for (; i >= 0 || j >= 0;)
    {
        if (i == -1 && j != -1)
            nums1[j--] = nums2[j--];
        // nums2全填进去后，nums1剩余部分有序
        else if (j == -1)
            break;

        else if (nums1[i] > nums2[j])
        {
            // nums1[i + j + 1] = nums1[i--];
            // 不要用复合运算
            nums1[i + j + 1] = nums1[i];
            i--;
        }

        else if (nums1[i] <= nums2[j])
        {
            nums1[i + j + 1] = nums2[j];
            j--;
        }
    }
}

void merge4(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    /* 双尾指针遍历 Time: O(m+n) Space: O(1) */
    int i = m - 1, j = n - 1;
    int tail = i + j + 1;
    vector<int> sorted;
    for (; i >= 0 || j >= 0;)
    {

        if (i == -1)
            nums1[tail--] = nums2[j--];
        // nums2全填进去后，nums1剩余部分有序
        else if (j == -1)
            break;
        else if (nums1[i] > nums2[j])
            nums1[tail--] = nums1[i--];
        else if (nums1[i] <= nums2[j])
            nums1[tail--] = nums2[j--];
    }
}
int main()
{
    vector<int> nums1, nums2;
    int m, n;
    int num;
    while (cin >> num)
    {
        nums1.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    cin >> m;
    while (cin >> num)
    {
        nums2.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    cin >> n;
    merge(nums1, m, nums2, n);
    for (int i = 0; i < m + n; i++)
    {
        cout << nums1[i] << " ";
    }
    return 0;
}