#include<bits/stdc++.h>
using namespace std;
string s1,s2; vector<vector<int>>dp;

int lcs(int idx1,int idx2){
    if(idx1<0 || idx2<0){return 0;}
    else if(dp[idx1][idx2]!=-1){return dp[idx1][idx2];}
    
    return s1[idx1]==s2[idx2] ? (dp[idx1][idx2]=lcs(idx1-1,idx2-1)+1) : (dp[idx1][idx2]=max(lcs(idx1-1,idx2),lcs(idx1,idx2-1)));
}

void do_this(){
    cin>>s1>>s2; int sz1=s1.size(),sz2=s2.size();
    
    dp.assign(sz1,vector<int>(sz2,-1)); cout<<lcs(sz1-1,sz2-1);
}

int main(){
    do_this();
}
