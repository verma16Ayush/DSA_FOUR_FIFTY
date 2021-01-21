#include <bits/stdc++.h>
using namespace std;
class Solution{
private:
    int dp[101][10001];
    int SubsetSum(vector<int>& a, int sum, int n)
    {
        if(dp[n][sum] != -1) return dp[n][sum];
        if(sum == 0) return dp[n][sum] = 1;
        if(sum && n == 0) return dp[n][sum] = 0;
        if(a[n - 1] <= sum) return dp[n][sum] = (SubsetSum(a, sum - a[n - 1], n- 1) || SubsetSum(a, sum, n - 1));
        return dp[n][sum] = SubsetSum(a, sum, n - 1);
    }

public:    
    int equalPartition(int N, int arr[])
    {
        vector<int> a(N);
        int sum = 0;
        for(int i = 0; i <N; i++)
        {
            a[i] = arr[i];
            sum += a[i];
        }
        memset(dp, -1, sizeof(dp));
        if(sum % 2) return 0;
        else return SubsetSum(a, sum / 2, N);
    }
};

int main(){
    #ifdef LOCAL_PROJECT
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}