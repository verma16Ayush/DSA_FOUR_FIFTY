/** 
 *
 * @author - Ayush
 * @title - 11.cpp
 * @createdOn - 2020-10-31 18:25 Hrs
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
    vector<int> a(n);
    vector<int> check(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(check[a[i]] == 0)
        {
            check[a[i]] = 1;
        }
        else
        {
            cout << a[i] << " ";
        }
        
    }

    return 0;
    
}