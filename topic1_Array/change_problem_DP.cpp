/** 
 *
 * @author - Ayush
 * @title - change_problem_DP.cpp
 * @createdOn - 2020-10-23 13:59 Hrs
 * 
 **/
#include <iostream>
#include <cmath>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef map<long long int, long long int> mii;
typedef pair<int, int> pii;
typedef vector<vector<int>> int_vec_2d;
typedef vector<int>:: iterator vi_it;
typedef map<int, int>::iterator mii_it;

ll dpchange(int money, vector<int>& coins)
{
    mii minCoins;
    minCoins[0] = 0;
    for(int m = 1; m <= money; m++)
    {
        minCoins[m] = INT64_MAX;
        for(int coin : coins)
        {
            if(m >= coin)
            {
                int numCoins = minCoins[m - coin] + 1;
                if(numCoins < minCoins[m]) minCoins[m] = numCoins;
            }
        }
    }

    return minCoins[money];
}

int main()
{
    int n;
    cin >> n;
    vector<int> coins;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        coins.push_back(temp);
    }

    int money;
    cin >> money;
    cout << dpchange(money, coins);
    return 0;
    
}