/** 
 *
 * @author - Ayush
 * @title - 23.cpp
 * @createdOn - 2020-11-09 23:34 Hrs
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

    int max_prod = a[0];
    int max_so_far = a[0];

    for (int i = 1; i < n; i++)
    {
        max_so_far = max(a[i], a[i] * max_prod);
        max_prod = (a[i], max_so_far);
    }


    return 0;
    
}