/** 
 *
 * @author - Ayush
 * @title - 7.cpp
 * @createdOn - 2020-10-22 00:37 Hrs
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
        a.push_back(temp);
    }
    return a;
}

void PrintArray(vector<int> a)
{
    for(int i = 0; i < a.size(); i++) cout << a[i] << " ";
    cout << endl;
}

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

void CyclicRotate(vector<int>& a, int k)
{
    Reverse(a, 0, 4);
    Reverse(a, 5, 7);
    Reverse(a, 0, 7);
}

int main()
{
    vector<int> a = GenArray();
    PrintArray(a);
    int k;
    cin >> k;
    cout << "rotated: ";
    CyclicRotate(a, k);
    PrintArray(a);
    return 0;
}