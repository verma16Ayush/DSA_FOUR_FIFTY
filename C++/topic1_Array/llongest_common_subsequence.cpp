/** 
 *
 * @author - Ayush
 * @title - llongest_common_subsequence.cpp
 * @createdOn - 2020-10-24 17:49 Hrs
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

int i = 0;
int memo[10][10];

int lcs(string str1, string str2, int m, int n)
{
    if(memo[m][n] != -1) 
        return memo[m][n];
    if(m == 0 || n == 0)
        memo[m][n] = 0;
    else
    {
        if(str1[m-1] == str2[n-1]) 
            memo[m][n] =  1 + lcs(str1, str2, m-1, n-1);
        else 
            memo[m][n] = max(lcs(str1, str2, m-1, n), lcs(str1, str2, m, n-1));
    }
    return memo[m][n];
}

int main()
{
    string str1 = "abc";
    string str2 = "cab";
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            memo[i][j]=-1;
        }   
    }
    cout << lcs(str1, str2, str1.length(), str2.length());
    // cout << endl << i ;
    return 0;
}