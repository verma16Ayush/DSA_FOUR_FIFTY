/** 
 *
 * @author - Ayush
 * @title - subset_sum.cpp
 * @createdOn - 2021-01-20 00:15 Hrs
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

int dp[1001][101];
//  dp[nume][sum];
bool SubsetSumTab(vector<int>& a, int n, int sum)
{
    for(int i = 0; i <= 1000; i++) dp[i][0] = 1;
    for(int i = 1; i <= 100; i++) dp[0][i] = 0;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= sum; j++)
        {
            if(a[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - a[i - 1]] || dp[i - 1][j];
            }
            else dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}

bool SubsetSum(vector<int>& a, int n, int sum)
{
    if(dp[sum][n] != -1) return dp[sum][n];
    if(sum == 0) return dp[sum][n] = 1;
    if(sum && n == 0) return dp[sum][n] = 0;
    if(a[n - 1] <= sum) return dp[sum][n] = (SubsetSum(a, n - 1, sum - a[n - 1]) || SubsetSum(a, n - 1, sum));
    return dp[sum][n] = SubsetSum(a, n - 1, sum);
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
        int sum;
        cin >> n;
        cin >> sum;
        vector<int> a(n);
        for(int& i : a) cin >> i;
        memset(dp, -1, sizeof(dp));
        cout << SubsetSum(a, n, sum) << nl;
        // cout << i << nl;
    }
    return 0;
}