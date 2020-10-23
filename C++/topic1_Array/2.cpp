/** 
 *
 * @author - Ayush
 * @title - 2.cpp
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
        a.push_back(temp);
    }
    return a;
}
void PrintArray(vector<int> a)
{
    for(int i = 0; i < a.size(); i++) cout << a[i] << " ";
    cout << endl;
}

int main()
{
    vector<int> a = GenArray();
    PrintArray(a);
    sort(a.begin(), a.end());
    cout << "max: " << a[a.size()-1] << endl;
    cout << "min: " << a[0] << endl;
    return 0;
    
}