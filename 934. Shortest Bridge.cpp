class Solution {
public:
    int n,pi,pj,ci,cj,dis,si,sj; bool vis[105][105],flag; vector<pair<int,int>>mov={{0,1},{0,-1},{-1,0},{1,0}}; void init(){for(int i=0; i<n; i++){for(int j=0; j<n; j++){vis[i][j]=false;}}} 
    
    bool isvalid(int i,int j){return i>=0 && i<n && j>=0 && j<n;}

    void dfs(int si,int sj,vector<vector<int>>& grid){
        vis[si][sj]=true; grid[si][sj]=2; for(auto mv : mov){
            ci=si+mv.first; cj=sj+mv.second; if(isvalid(ci,cj) && !vis[ci][cj] && grid[ci][cj]==1){dfs(ci,cj,grid);}
        }
    }

    int shortest_dis(vector<vector<int>>& grid){
        queue<pair<pair<int,int>,int>>q; for(int i=0; i<n; i++){for(int j=0; j<n; j++){if(grid[i][j]==1){q.push({{i,j},0});}}} while(!q.empty()){
            pi=q.front().first.first; pj=q.front().first.second; dis=q.front().second; q.pop(); for(auto mv : mov){
                ci=pi+mv.first; cj=pj+mv.second; if(isvalid(ci,cj) && grid[ci][cj]==2){return dis;} else if(isvalid(ci,cj) && !vis[ci][cj] && grid[ci][cj]!=1){q.push({{ci,cj},dis+1}); vis[ci][cj]=true;}
            }
        }return 1;
    }

    int shortestBridge(vector<vector<int>>& grid) {
        n=grid.size(); init(); flag=false; for(int i=0; i<n; i++){for(int j=0; j<n; j++){if(grid[i][j]==1){dfs(i,j,grid); flag=true; break;}}if(flag){break;}} return shortest_dis(grid);
    }
};
