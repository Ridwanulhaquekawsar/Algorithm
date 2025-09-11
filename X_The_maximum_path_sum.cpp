#include<bits/stdc++.h>
using namespace std;
int row,col; int mat[15][15]; int dp[15][15]; void init(){for(int i=1; i<=row; i++){for(int j=1; j<=col; j++){dp[i][j]=-1;}}}
#define pinf INT_MAX

int path_max_sum(int i,int j){
    if(i>row || j>col){return -pinf;} else if(i==row && j==col){return mat[i][j];} if(dp[i][j]!=-1){return dp[i][j];}
    return dp[i][j]=max(path_max_sum(i+1,j),path_max_sum(i,j+1))+mat[i][j];
}

void do_this(){
    cin>>row>>col; init(); for(int i=1; i<=row; i++){for(int j=1; j<=col; j++){cin>>mat[i][j];}} cout<<path_max_sum(1,1);
}

int main(){
    do_this();
    return 0;
}
