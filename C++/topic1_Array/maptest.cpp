/** 
 *
 * @author - Ayush
 * @title - maptest.cpp
 * @createdOn - 2020-11-09 19:13 Hrs
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
    map<int, int> a;
    a[2] = 1;
    a[1] = 0;
    if(a[6])
    {
        cout << a[3] << endl;
    }
    a[2]++;
    return 0;
}