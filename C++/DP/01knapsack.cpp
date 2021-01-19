/** 
 *
 * @author - Ayush
 * @title - coinchange.cpp
 * @createdOn - 2021-01-18 23:21 Hrs
 * 
 **/
#include <iostream>
#include <bits/stdc++.h>
#define nl '\n'
#define MOD (ll)(1e9 + 7)
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long double ld;
typedef long long ll;
using namespace std;

ll PowModulo(ll a, ll b)
{
    ll res = 1;
    a = a % MOD;
    if(b == 0) return 1;
    if(a == 0) return 0;
    while(b)
    {
        if(b & 1) res = (res * a) % MOD;
        b = b >> 1;
        a = (a * a) % MOD;
    }
    return res;
}

struct item
{
    int val;
    int weight;
};
int dp[1001][1001];

int GetProfit(vector<item>& a, int cap, int n)
{
    if(dp[cap][n] != -1) return dp[cap][n];
    if(n == 0 || cap == 0) return 0;
    else if(a[n - 1].weight <= cap)
    {
        return dp[cap][n] = max(a[n-1].val + GetProfit(a, cap - a[n - 1].weight, n - 1), GetProfit(a, cap, n - 1));
    }
    else
    {
        return dp[cap][n] = GetProfit(a, cap, n - 1);
    }
}

int GetProfitTab(vector<item>& a, int cap, int n)
{
    for(int i = 0; i <= n; i++)
    {
        dp[0][i] = 0;
    }
    for(int i = 0; i <= cap; i++)
    {
        dp[i][0] = 0;
    }
    
    // dp[cap][n];
    for(int i = 1; i <= cap; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(a[j - 1].weight <= i)
            {
                dp[i][j] = max(a[j - 1].val + dp[i - a[j - 1].weight][j - 1], dp[i][j - 1]);
            }
            else dp[i][j] = dp[i][j - 1];
        }
    }
    return dp[cap][n];
}


int knapSack(int W, int wt[], int val[], int n) 
{ 
    // memset(dp, -1, sizeof(dp));
    vector<item> it(n);
    for(int i = 0; i < n; i++)
    {
        it[i].val = val[i];
        it[i].weight = wt[i];
    }
    return GetProfitTab(it, W, n);
}




int main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    fastIO
    int w[] = {4, 5, 1};
    int val[] = {1, 2, 3};
    cout << knapSack(4, w, val, 3) << nl;
    return 0;
}