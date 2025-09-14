#include<bits/stdc++.h>
using namespace std;
int t; int dp[100005]; void init(int n){for(int i=1; i<=n; i++){dp[i]=-1;}}

bool can_reach(int n){
    if(n==1){return true;}else if(n<1){return false;}else if(dp[n]!=-1){return dp[n];}else if(n%2!=0){return (dp[n]=can_reach(n-3));}
    else{return (dp[n]=can_reach(n-3) || can_reach(n/2));}
}

void do_this(){
    int n; cin>>t; while(t--){cin>>n; init(n); cout<<(can_reach(n) ? "YES" : "NO")<<endl;}
}

int main(){
    do_this();
    return 0;
}
