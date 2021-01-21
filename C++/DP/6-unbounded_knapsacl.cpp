/** 
 *
 * @author - Ayush
 * @title - 6-unbounded_knapsacl.cpp
 * @createdOn - 2021-01-21 14:04 Hrs
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
    int wt;
};
int dp[101][101];
// dp[size][cap];

int GetProfit(vector<item>& a, int n, int cap)
{
    if(dp[n][cap] != -1) return dp[n][cap];
    if(cap == 0 || n == 0) return dp[n][cap] = 0;
    else if(a[n - 1].wt <= cap) return dp[n][cap] = max(a[n - 1].val + GetProfit(a, n, cap - a[n - 1].wt), GetProfit(a, n - 1, cap));
    else return dp[n][cap] = GetProfit(a, n - 1, cap);
}

int GetProfitTab(vector<item>& a, int n, int cap)
{
    for(int i = 0; i <= n; i++) dp[i][0] == 0;
    for(int i = 0; i <= cap; i++) dp[0][i] == 0;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= cap; j++)
        {
            if(a[i - 1].wt <= j) dp[i][j] = max(a[i - 1].val + dp[i][j - a[i - 1].wt], dp[i - 1][j]);
            else dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][cap];
}


int main()
{
    #ifdef LOCAL_PROJECT
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    fastIO
    int tc;
    cin >> tc;
    cin.ignore();
    while(tc--)
    {
        int n, cap;
        cin >> n >> cap;
        vector<item> it(n);

        for(item& i : it)
        {
            cin >> i.val >> i.wt;
        }
        memset(dp, -1, sizeof(dp));
        cout << GetProfit(it, n, cap) << nl;
        cout << GetProfitTab(it, n, cap) << nl;

    }
    return 0;
}