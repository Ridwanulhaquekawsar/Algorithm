#include<bits/stdc++.h>
using namespace std;
int n,e,a,b,c,leader1,leader2; vector<int>par,grp_sz;

class Edge{
    public:
        int a,b,c;
    Edge(int a,int b,int c){
        this->a=a; this->b=b; this->c=c;
    }    
};

vector<Edge>edge_list;

bool cmp(Edge l,Edge r){
    return l.c<r.c;
}

int find(int node){
    if(par[node]==-1){return node;}
    return (par[node]=find(par[node]));
}

void Dsu_union(){
    if(grp_sz[leader1]>=grp_sz[leader2]){
        par[leader2]=leader1; 
        grp_sz[leader1]+=grp_sz[leader2];
    }else{
        par[leader1]=leader2; 
        grp_sz[leader2]+=grp_sz[leader1];
    }
}

void do_this(){
    cin>>n>>e; edge_list.reserve(e);
    
    while(e--){
        cin>>a>>b>>c; 
        edge_list.push_back(Edge(a,b,c));
    }sort(edge_list.begin(),edge_list.end(),cmp);
    
    par.assign(n,-1),grp_sz.assign(n,1);
    
    int min_cost=0; cout<<'\n'<<'\n';
    for(auto &[a,b,c] : edge_list){
        leader1=find(a),leader2=find(b); if(leader1!=leader2){
            Dsu_union(); min_cost+=c; cout<<a<<" "<<b<<" "<<c<<'\n';
        }
    }
    
    cout<<min_cost;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    do_this();
    return 0;
}
