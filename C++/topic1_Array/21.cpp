/** 
 *
 * @author - Ayush
 * @title - 21.cpp
 * @createdOn - 2020-11-09 21:24 Hrs
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
    a.reserve(n);

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }

    map<int, int> hm;

    hm[0] = 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if(hm[sum])
        {
            cout << "YES" << endl;
            return 0;
        }
        else
        {
            hm[sum] = 1;
        }
    }
    
    cout << "NO" << endl;


    return 0;
     
}