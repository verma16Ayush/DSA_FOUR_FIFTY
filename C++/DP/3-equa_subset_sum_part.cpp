/** 
 *
 * @author - Ayush
 * @title - equa_sum_part.cpp
 * @createdOn - 2021-01-20 12:58 Hrs
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
// dp[numelements][sum];
int dp[101][1001] = {0};

int SubsetSum(vector<int>& a, int sum, int n)
{
    if(dp[n][sum] != -1) return dp[n][sum];
    if(sum == 0) return dp[n][sum] = 1;
    if(sum && n == 0) return dp[n][sum] = 0;
    if(a[n - 1] <= sum)
    {
        return dp[n][sum] = (SubsetSum(a, sum - a[n - 1], n- 1) || SubsetSum(a, sum, n - 1));
    }
    else if(a[n - 1] > sum)
    {
        return dp[n][sum] = SubsetSum(a, sum, n - 1);
    }
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
        for(int& i : a){cin >> i; sum += i;}
        memset(dp, -1, sizeof(dp));
        if(sum % 2) cout << 0 << nl;
        else cout << SubsetSum(a, sum / 2, n) << nl;

    }
    return 0;
}