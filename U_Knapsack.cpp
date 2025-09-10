#include<bits/stdc++.h>
using namespace std;
int n,val[1005],weight[55]; int dp[25][105]; void init(int max_weight){
    for(int i=0; i<=n; i++){for(int j=0; j<=max_weight; j++){dp[i][j]=-1;}}
}

int Knapsack(int i,int max_weight){
    if(i<0 || max_weight==0){return 0;} if(dp[i][max_weight]!=-1){return dp[i][max_weight];}
    if(weight[i]<=max_weight){
        return dp[i][max_weight]=max(Knapsack(i-1,max_weight-weight[i])+val[i],Knapsack(i-1,max_weight));
    }else{return dp[i][max_weight]=Knapsack(i-1,max_weight);}
}

void do_this(){
    int mx_weight; cin>>n>>mx_weight; init(mx_weight); for(int i=0; i<n; i++){cin>>weight[i]>>val[i];} cout<<Knapsack(n-1,mx_weight);
}

int main(){
    do_this();
    return 0;
}
