/** 
 *
 * @author - Ayush
 * @title - 6.cpp
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
        int temp = rand() % 10;
        a.push_back(temp);
    }
    return a;
}

void PrintArray(vector<int> a)
{
    for(int i = 0; i < a.size(); i++) cout << a[i] << " ";
    cout << endl;
}

int BinSearch(vector<int>& a, int b)
{
    int mid;
    int st = 0;
    int end = a.size() - 1;
    while (st <= end)
    {
        mid = (st + end) / 2;
        if(a[mid] == b)
            return mid;
        else if(b > a[mid])
            st = mid + 1;
        else
        {
            end = mid - 1;
        }
    }
    return -1;
    
}

// int main()
// {
//     vector<int> a = GenArray();
//     vector<int> b = GenArray();

//     PrintArray(a);
//     PrintArray(b);

//     sort(a.begin(), a.end());

//     set<int> u;
//     u.reserve(a.size() + b.size());

//     for (int i = 0; i < a.size(); i++)
//     {
//         u.push_back(a[i]);
//     }

//     for (int i = 0; i < b.size(); i++)
//     {
//         // if(BinSearch(a, b[i]) == -1) u.push_back(b[i]);
//         if(find(a.begin(), a.end(), b[i]) == a.end()) u.push_back(b[i]);
//     }
    
//     PrintArray(u);
    
//     return 0;
// }


int main()
{
    vector<int> a;
    vector<int> b;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        b.push_back(temp);
    }
    
    sort(a.begin(), a.end());
    vector<int> u;
    u.reserve(a.size() + b.size());
    vector<int> intersect;
    intersect.reserve(a.size());

    for (int i = 0; i < a.size(); i++)
    {
        u.push_back(a[i]);
    }

    for (int i = 0; i < b.size(); i++)
    {
        if(find(a.begin(), a.end(), b[i]) == a.end()) u.push_back(b[i]);
    }
    cout << "union: ";
    PrintArray(u);

    for (int i = 0; i < b.size(); i++)
    {
        if(find(a.begin(), a.end(), b[i]) != a.end()) intersect.push_back(b[i]);
    }
    
    cout << "intersection: ";
    PrintArray(intersect);
    return 0;
}