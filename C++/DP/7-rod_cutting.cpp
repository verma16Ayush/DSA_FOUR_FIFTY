/** 
 *
 * @author - Ayush
 * @title - 7-rod_cutting.cpp
 * @createdOn - 2021-01-21 15:42 Hrs
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

struct seg
{
    int sl;
    int val;
};

// int dp[size][]

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
        int l;
        cin >> l;
        vector<seg> s(l);
        for(seg& i : s) cin >> i.sl;
        for(seg& i : s) cin >> i.val;

    }
    return 0;
}