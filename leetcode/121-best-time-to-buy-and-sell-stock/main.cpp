#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int maxProfit_99(vector<int> &prices)
{
    /* 暴力求解 超时*/
    /* Time: O(N2) Space: O(1)*/
    int maxp = 0;
    int curp = 0;
    int minp = 11111;
    for (int i = 0; i < prices.size() - 1; i++)
    {
        if (prices[i] < minp)
            minp = prices[i];
        else if (prices[i] >= minp)
            i++;
        for (int j = i + 1; j < prices.size(); j++)
        {
            if ((prices[j] - prices[i]) > curp)
            {
                curp = prices[j] - prices[i];
                if (curp > maxp)
                    maxp = curp;
            }
        }
    }
    return maxp;
}
int maxProfit(vector<int> &prices)
{
    /* 将当天股价票价格与之前所有天中的最小值相减求出当天的最大利润*/
    /* 维护最大利润 */
    /* 维护最小购入价格 */
    /* Time: O(N) Space: O(1)*/
    int maxp = 0;
    int minprice = prices[0];
    for (int i = 0; i < prices.size(); i++)
    {
        maxp = max(maxp, prices[i] - minprice);
        minprice = min(minprice, prices[i]);
    }
    return maxp;
}

int main()
{
    vector<int> prices;
    int num;
    while (cin >> num)
    {
        prices.push_back(num);
        if (cin.peek() != '\n')
            break;
    }
    cout << maxProfit_99(prices);
    return 0;
}
