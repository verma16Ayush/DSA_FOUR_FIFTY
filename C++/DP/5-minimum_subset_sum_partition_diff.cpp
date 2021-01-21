/** 
 *
 * @author - Ayush
 * @title - 5-minimum_subset_sum_partition_diff.cpp
 * @createdOn - 2021-01-20 20:47 Hrs
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

int dp[101][101];

//dp[size][sum];

int SubsetSum(vector<int> a, int n, int sum)
{
    for(int i = 0; i <= sum; i++) dp[0][i] = 0;
    for(int i = 0; i <= n; i++) dp[i][0] = 1;

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
    vector<int> v;

    for(int i = 0; i <= sum / 2; i++)
    {
        if(dp[n][i]) v.push_back(i);
    }
    int m = INT32_MAX;
    for(int i : v)
    {
        m = min(m, sum - 2 * i);
    }

    return m;
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
        vector<int> a(n);
        int sum = 0;
        for(int& i : a)
        {
            cin >> i;
            sum += i;
        }
        memset(dp, -1, sizeof(dp));
        cout << SubsetSum(a, n, sum) << nl;
    }
    return 0;
}