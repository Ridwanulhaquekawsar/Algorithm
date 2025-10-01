class Solution {
public:
    vector<vector<int>>dp;
    
    int do_change(int idx,int mx_amount,vector<int>& coins){
        if(idx<0){
            return mx_amount==0 ? 1 : 0;
        }
        
        if(dp[idx][mx_amount]!=-1){return dp[idx][mx_amount];}
        
        return (dp[idx][mx_amount]=(coins[idx]<=mx_amount ? do_change(idx,mx_amount-coins[idx],coins)+do_change(idx-1,mx_amount,coins) : do_change(idx-1,mx_amount,coins)));
    }
    
    int change(int amount, vector<int>& coins) {
        int sz=coins.size(); dp.assign(sz,vector<int>(amount+1,-1));
        return do_change(sz-1,amount,coins);
    }
};
