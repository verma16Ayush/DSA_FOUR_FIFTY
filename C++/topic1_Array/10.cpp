/** 
 *
 * @author - Ayush
 * @title - 10.cpp
 * @createdOn - 2020-10-22 21:00 Hrs
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

int memo[20];
vector<int> GenArray()
{
    int n;
    cin >> n;
    vector<int> a;
    a.reserve(n);
    for (int i = 0; i < n; i++)
    {
        int temp = rand() % 10;
        a.push_back(temp);
    }
    return a;
}

void PrintArray(vector<int>& a)
{
    for(int i = 0; i < a.size(); i++) cout << a[i] << " ";
    cout << endl;
}

int CountJumps(vector<int>& a, int n)
{
    int* jump = new int[n + 1];
    jump[0] = 0;
    for (int i = 1; i < n; i++)
    {
        jump[i] = INT_MAX;
        for(int j = 0; j < i; j++)
        {
            if(j + a[j] >= i)
            {
                jump[i] = min(jump[j], jump[j] + 1);
            }
        }
    }
    return jump[n-1];
}

int main()
{
    // int t;
    // cin >> t;
    // while(t--)
    // {
    //     int n;
    //     cin >> n;
    //     vector<int> a;
    //     a.reserve(n)

    // for (int i = 0; i < 20; i++)
    // {
    //     memo[i] = -1;
    // }
    
    
    vector<int> a = { 1, 3, 6, 1, 0, 9 };
    PrintArray(a);
    cout << CountJumps(a, a.size());
    return 0;
}