/** 
 *
 * @author - Ayush
 * @title - countSubsetSum.cpp
 * @createdOn - 2021-01-20 19:45 Hrs
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
// int dp[numele][sum];
int dp[101][101];

int SubsetSumCount(vector<int>& a, int sum, int n)
{
    if(sum == 0) return dp[n][sum] = 1;
    if(sum && n == 0) return dp[n][sum] = 0;
    if(a[n - 1] <= sum) return dp[n][sum] = SubsetSumCount(a, sum - a[n - 1], n - 1) + SubsetSumCount(a, sum, n - 1);
    else return dp[n][sum] = SubsetSumCount(a, sum, n - 1);
}

int SubsetSumCountTab(vector<int>& a, int sum, int n)
{
    for(int i = 0; i < 101; i++) dp[0][i] = 0;
    for(int i = 0; i < 101; i++) dp[i][0] = 1;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= sum; j++)
        {
            if(a[i - 1] <= j) dp[i][j] = dp[i - 1][j - a[i - 1]] + dp[i - 1][j];
            else dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
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
        int n;
        cin >> n;
        int sum;
        cin >> sum;
        vector<int> a(n);
        for(int& i : a) cin >> i;

        memset(dp, -1, sizeof(dp));
        cout << SubsetSumCountTab(a, sum, n) << nl;
        cout << SubsetSumCount(a, sum, n) << nl;
    }
    return 0;
}