#include<bits/stdc++.h>
using namespace std;
int n,sm; vector<int>val_arr; vector<vector<int>>dp;

int subset_sum(int idx,int sum){
    if(idx<0){
        return sum==0 ? 1 : 0;
    }else if(dp[idx][sum]!=-1){
        return dp[idx][sum];
    }
    
    return (dp[idx][sum]=val_arr[idx]<=sum ? (subset_sum(idx-1,sum-val_arr[idx]) + subset_sum(idx-1,sum)) : subset_sum(idx-1,sum));
}

void do_this(){
    cin>>n; val_arr.resize(n);
    
    int i=0;  while(i<n){
        cin>>val_arr[i]; i++;
    }cin>>sm; dp.assign(n,vector<int>(sm+1,-1));
    
    cout<<subset_sum(n-1,sm);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    do_this();
    return 0;
}
