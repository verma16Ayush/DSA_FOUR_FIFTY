/** 
 *
 * @author - Ayush
 * @title - 13.cpp
 * @createdOn - 2020-10-31 22:14 Hrs
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

void Merge(vector<int>& a, vector<int>& b)
{
    int n = a.size();
    int m = b.size();

    int i = 0;
    int j = 0;

    while(i < n && j < m)
    {
        
    }

    return;
}

int main()
{
    vector<int> a;
    vector<int> b;

    int n, m;

    cin >> n;
    cin >> m;

    a.reserve(n);
    b.reserve(m);
    int temp;

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        a.push_back(temp);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        b.push_back(temp);
    }
    Merge(a, b);
    
}