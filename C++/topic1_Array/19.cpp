/** 
 *
 * @author - Ayush
 * @title - 19.cpp
 * @createdOn - 2020-11-01 22:31 Hrs
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

int main()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    vector<int> a;
    vector<int> b;
    vector<int> c;

    a.reserve(n1);
    b.reserve(n2);
    c.reserve(n3);

    for (int i = 0; i < n1; i++)
    {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }

    for (int i = 0; i < n2; i++)
    {
        int temp;
        cin >> temp;
        b.push_back(temp);
    }

    for (int i = 0; i < n3; i++)
    {
        int temp;
        cin >> temp;
        c.push_back(temp);
    }

    int i = 0;
    int j = 0;
    int k = 0;
    int var = min({a[0], b[0], c[0]});
    int count = 0;
    int nvar = var;
    vector<int> cmn;
    cmn.reserve(100);
    while(i < a.size() && j < b.size() && k < c.size())
    {
        // vector<int> mins = {a[i], b[j], c[k]};
        var = min({a[i], b[j], c[k]});
        if(a[i] == var && b[j] == var && c[k] == var)
        {
            cmn.push_back(a[i]);
            i++;
            j++;
            k++;
        }
        else
        {
            if(a[i] == var) i++;
            else if(b[j] == var) j++;
            else if(c[k] == var) k++;
        } 
    }

    for (int i = 0; i < cmn.size(); i++)
    {
        cout << cmn[i] <<" ";
    }
    return 0;
}