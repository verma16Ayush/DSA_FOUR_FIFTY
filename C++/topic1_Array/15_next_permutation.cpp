/** 
 *
 * @author - Ayush
 * @title - 15_next_permutation.cpp
 * @createdOn - 2020-11-01 13:53 Hrs
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

void Reverse(vector<int>& a, int st, int en)
{
    /**
     * @param - a = array, st = start index, en = end index, reverses the array in place from [st, en]
     **/
    
    int half = st + ((en+1) - st) / 2;
    int endCount = en;
    for (int startCount = st; startCount < half; startCount++) 
    {
        int store = a[startCount];
        a[startCount] = a[endCount];
        a[endCount] = store;
        endCount--;
    }
}

void NextPerm(vector<int>& a)
{
    int k = 0;

    for (int i = 0; i < a.size() - 1; i++)
    {
        if(a[i+1] > a[i]) k = i;
    }
    
    int t = a.size() - 1;
    for(t; t > k; t--)
    {
        if(a[t] > a[k])
        {
            swap(a[t], a[k]);
            break;
        }
    }

    // swap(a[k], a[t]);

    Reverse(a, k+1, a.size()-1);
    
    return;
}

int main()
{
    int n;
    vector<int> a;
    cin >> n;
    a.reserve(n);

    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        a.push_back(t);
    }

    NextPerm(a);
    
}