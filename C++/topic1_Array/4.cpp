/** 
 *
 * @author - Ayush
 * @title - 4.cpp
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
        int temp = rand() % 3;
        a.push_back(temp);
    }
    return a;
}

void DutchNationalFlag(vector<int>& a)
{
    int lo, mid, high;
    lo = 0;
    mid = 0;
    high = a.size() - 1;

    for(mid; mid <= high; mid++)
    {
        switch (a[mid])
        {
            case 0:
                swap(a[mid], a[lo++]);
                break;
            case 1:
                break;
            case 2:
                swap(a[mid--], a[high--]);
                break;
        }
    }
}

void PrintArray(vector<int> a)
{
    for(int i = 0; i < a.size(); i++) cout << a[i] << " ";
    cout << endl;
}

int main()
{
    vector<int> a = {0,1,2,1,0,2};
    a[0] = 0;
    PrintArray(a);
    DutchNationalFlag(a);
    PrintArray(a);
    return 0;
}