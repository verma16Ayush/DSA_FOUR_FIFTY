/** 
 *
 * @author - Ayush
 * @title - 17.cpp
 * @createdOn - 2020-11-01 15:32 Hrs
 * 
 **/
#include <iostream>
#include <cmath>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef vector<vector<int>> int_vec_2d;
typedef vector<int>:: iterator vi_it;
typedef map<int, int>::iterator mii_it;

int main()
{
    int n;
    cin >> n;
    vector<int> a;
 
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }

    int maxProfit = 0;
    int minprice = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        minprice = min(minprice, a[i]);
        maxProfit = max(maxProfit, a[i] - minprice);
    }
    
    cout << minprice << " " << maxProfit;
    return 0;
}