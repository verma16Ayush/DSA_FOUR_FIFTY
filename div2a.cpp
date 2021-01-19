/** 
 *
 * @author - Ayush
 * @title - div2a.cpp
 * @createdOn - 2021-01-19 20:12 Hrs
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

char Add(char a, char b)
{
    if(a == '1' && b == '1') return '2';
    if(a == '0' && b == '0') return '0';
    else return '1';
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
        string str;
        cin >> str;
        string ans = "1";
        char prev;
        if (str[0] == 1) prev = '2';
        else prev = '1';
        for(int i = 1; i < n; i++)
        {
            
        }
    }
    return 0;
}