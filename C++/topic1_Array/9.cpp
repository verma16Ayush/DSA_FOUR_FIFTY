/** 
 *
 * @author - Ayush
 * @title - 9.cpp
 * @createdOn - 2020-10-22 13:57 Hrs
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
using namespace std;

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

void Solve(vector<int>& a, int k)
{
    sort(a.begin(), a.end());
    int n = a.size();
    int ans = a[n-1] - a[0];

    for (int i = 1; i < n; i++)
    {
        int max = std::max(a[n-1] - k, a[i - 1] + k);
        int min = std::min(a[0] + k, a[i] - k);
        ans = std::min(ans, max - min);

    }
    cout << ans;
}

int main()
{
    vector<int> a = {2, 3, 5, 6, 7};
    a.shrink_to_fit();
    PrintArray(a);

    // sort(a.begin(), a.end());

    int k;
    cin >> k;
    Solve(a, k);
    return 0;
}