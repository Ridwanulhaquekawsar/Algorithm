#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int n,e,k,a,b,c,par_nde,chld_nde,chld_dis; vector<ll>dis[100005]; vector<pair<int,int>>adj_lst[100005];
ll par_dis;

void Dijkstra(int src){
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
    pq.push({0,src}); dis[src][0]=0; 
    
    while(!pq.empty()){
        par_nde=pq.top().second; par_dis=pq.top().first; pq.pop();
        
        if(par_dis>dis[par_nde][k-1]){continue;}
        
        for(auto chld : adj_lst[par_nde]){
            chld_nde=chld.first; chld_dis=chld.second;
            
            if(par_dis+chld_dis<dis[chld_nde][k-1]){
                dis[chld_nde][k-1]=par_dis+chld_dis; pq.push({dis[chld_nde][k-1],chld_nde});
                sort(dis[chld_nde].begin(),dis[chld_nde].end());
            }
        }
    }
}

void do_this(){
    cin>>n>>e>>k; while(e--){
        cin>>a>>b>>c; adj_lst[a].push_back({b,c});
    }int i=1; while(i<=n){
        dis[i].resize(k); int j=0; while(j<k){
            dis[i][j]=1e18; j++;
        }i++;
    }Dijkstra(1); for(auto distance : dis[n]){
        cout<<distance<<" ";
    }
}

int main(){
    do_this();
    return 0;
}
