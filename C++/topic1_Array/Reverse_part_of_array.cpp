/** 
 *
 * @author - Ayush
 * @title - Reverse_part_of_array.cpp
 * @createdOn - 2020-10-22 12:41 Hrs
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

void ReversePart(vector<int>& a, int st, int end)
{
    int half = st + (end - st) / 2;
    int endind = end - 1;
    for(int i = st; i <= half; i++)
    {
        swap(a[i], a[endind]);
        endind--;
    }
}

int main()
{
    vector<int> a = GenArray();
    a.shrink_to_fit();
    PrintArray(a);
    int k;
    cin >> k;
    ReversePart(a, a.size() - k, a.size());
    PrintArray(a);
    return 0;

}