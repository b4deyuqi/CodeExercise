#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> findAnagrams_timeout(string s, string p)
{
    /* 暴力求解，超时*/
    vector<int> ans;
    string dic = p;
    int len = p.size();
    if (p.size() > s.size())
        return {};

    sort(dic.begin(), dic.end());
    string temp;
    for (int i = 0; i <= s.size() - len; i++)
    {
        temp = s.substr(i, len);
        sort(temp.begin(), temp.end());
        if (temp == dic)
            ans.push_back(i);
    }
    return ans;
}
vector<int> findAnagrams(string s, string p)
{
    /* 暴力求解，超时*/
    vector<int> ans;
    string dic = p;
    int len = p.size();
    if (p.size() > s.size())
        return {};

    sort(dic.begin(), dic.end());
    string temp;
    for (int i = 0; i <= s.size() - len; i++)
    {
        temp = s.substr(i, len);
        sort(temp.begin(), temp.end());
        if (temp == dic)
            ans.push_back(i);
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    string p;
    cin >> p;
    vector<int> ans = findAnagrams(s, p);
    for (auto it : ans)
        cout << it << " ";
}