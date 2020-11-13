/** 
 *
 * @author - Ayush
 * @title - 20.cpp
 * @createdOn - 2020-11-07 19:57 Hrs
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

void rightrotate(vector<int> arr, int n, int outofplace, int cur)  
{ 
    int tmp = arr[cur]; 
    for (int i = cur; i > outofplace; i--) 
        arr[i] = arr[i - 1]; 
    arr[outofplace] = tmp; 
}

void rearrange(vector<int> arr, int n)  
{ 
    int outofplace = -1; 

    for (int index = 0; index < n; index++)  
    { 
        if (outofplace >= 0)  
        { 
            // find the item which must be moved into the out-of-place 
            // entry if out-of-place entry is positive and current 
            // entry is negative OR if out-of-place entry is negative 
            // and current entry is negative then right rotate 
            // 
            // [...-3, -4, -5, 6...] -->   [...6, -3, -4, -5...] 
            //      ^                          ^ 
            //      |                          | 
            //     outofplace      -->      outofplace 
            // 
            if (((arr[index] >= 0) && (arr[outofplace] < 0)) || ((arr[index] < 0) && (arr[outofplace] >= 0)))  
            { 
                rightrotate(arr, n, outofplace, index); 

                // the new out-of-place entry is now 2 steps ahead 
                if (index - outofplace > 2)  
                    outofplace = outofplace + 2; 
                else
                    outofplace = -1; 
            } 
        } 

        // if no entry has been flagged out-of-place 
        if (outofplace == -1)  
        { 
            // check if current entry is out-of-place 
            if (((arr[index] >= 0) && ((index & 0x01)==0)) || ((arr[index] < 0) && (index & 0x01)==1)) 
                outofplace = index; 
        } 
    } 
} 

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

int main()
{
    vector<int> a = GenArray();
    PrintArray(a);
    rightrotate(a, a.size(), a[0], a[a.size() - 2]);
    PrintArray(a);
    return 0;
}