/** 
 *
 * @author - Ayush
 * @title - 5.cpp
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

vector<int> GenArray()
{
    int n;
    cin >> n;
    vector<int> a;
    a.reserve(n);
    for (int i = 0; i < n; i++)
    {
        int temp = rand() % 100000;
        if(temp % 2) temp *= -3;
        a.push_back(temp);
    }
    return a;
}

void PrintArray(vector<int> a)
{
    for(int i = 0; i < a.size(); i++) cout << a[i] << " ";
    cout << endl;
}

void Rearrange(vector<int>& a)
{
    int lo = 0;
    int hi = 0;
    for (int hi = 0; hi < a.size(); hi++)
    {
        if(a[hi] < 0) swap(a[hi], a[lo++]);
    }
    
}


int main()
{
    vector<int> a = GenArray();
    PrintArray(a);
    Rearrange(a);
    PrintArray(a);
    return 0;
}