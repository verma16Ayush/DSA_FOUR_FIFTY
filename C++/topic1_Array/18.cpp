/** 
 *
 * @author - Ayush
 * @title - 18.cpp
 * @createdOn - 2020-11-09 19:07 Hrs
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
    int n;
    cin >> n;
    int sum;
    cin >> sum;
    map<int, int> a;
    vector<int> array;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        array.push_back(temp);
    }

    for (int i = 0; i < n; i++)
    {
        int temp;
        temp = array[i];
        if(a[temp])
        {
            a[temp]++;
        }
        else
        {
            a[temp] = 1;
        }
    }

    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[sum - array[i]])
        {
            count += a[sum - array[i]];
        }

        if(array[i] == sum - array[i]) count--;
    }

    cout << count / 2 << "\n";
    return 0;
}