/** 
 *
 * @author - Ayush
 * @title - 14.cpp
 * @createdOn - 2020-11-01 10:50 Hrs
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

struct Segment
{
    int st;
    int en;

    Segment(int a, int b)
    {
        st = a;
        en = b;
    }
};

bool Compare(Segment a, Segment b)
{
    if(a.st < b.st) return true;

    return false; 
}

int main()
{
    vector<Segment> seg;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        Segment temp(a, b);

        seg.push_back(temp);
    }
    
    sort(seg.begin(), seg.end(), Compare);

    vector<Segment> segstck;
    segstck.reserve(n);
    for (int i = 0; i < n; i++)
    {
        segstck.push_back(seg[i]);
        if(segstck.size() >= 2)
        {
            if(segstck[segstck.size() - 1].st <= segstck[segstck.size() - 2].en)
            {
                int end = segstck[segstck.size() - 1].en;
                segstck.pop_back();
                segstck[segstck.size() - 1].en = end;
            }
        }
    }
    
    return 0;
}