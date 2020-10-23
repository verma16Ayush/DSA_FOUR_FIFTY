/** 
 *
 * @author - Ayush
 * @title - 8.cpp
 * @createdOn - 2020-10-22 12:50 Hrs
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
    vector<int> a = {-2, -3, 4, -1, -2, 1, 5, -3};
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
    int max_so_far = 0;
    int best_sum = 0;
    for (int i = 0; i < a.size(); i++)
    {
        max_so_far = max(0, max_so_far + a[i]);
        best_sum = max(max_so_far, best_sum);
    }

    cout << best_sum;
    return 0;
    
}