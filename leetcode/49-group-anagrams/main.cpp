#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> dic;
    for (int i = 0; i < strs.size(); i++)
    {
        string s = strs[i];
        sort(s.begin(), s.end());
        dic[s].push_back(strs[i]);
    }
    vector<vector<string>> ans;
    for (auto it : dic)
        ans.push_back(it.second);
    for (auto it = dic.begin(); it != dic.end(); it++)
        ans.push_back(it->second); // 访问 value
    return ans;
}

int main()
{
    vector<string> strs;
    string str;
    while (cin >> str)
    {
        strs.push_back(str);
        if (cin.peek() != '\n')
            break;
    }
    vector<vector<string>> ans = groupAnagrams(strs);
    for (const auto &group : ans)
    {
        for (const auto &str : group)
        {
            cout << str << " "; // 输出每个字符串，空格分隔
        }
        cout << endl; // 每组数据输出完后换行
    }
    return 0;
}