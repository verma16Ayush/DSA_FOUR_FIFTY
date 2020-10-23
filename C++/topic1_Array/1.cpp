/** 
 *
 * @author - Ayush
 * @title - 1.cpp
 * @createdOn - 2020-10-21
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
    int temp;
    
    for(int i = 0; i < n; i++){cin>>temp; a.push_back(temp);}

    for(int i = 0; i < n / 2; i++) swap(a[i], a[n-1-i]);

    for(int i = 0; i < n; i++) cout << a[i] << " ";

    return 0;
}