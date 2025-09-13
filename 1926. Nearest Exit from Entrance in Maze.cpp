class Solution {
public:
    int row,col,pi,pj,ci,cj,dis,ans; bool vis[105][105]; vector<pair<int,int>>mov={{0,1},{0,-1},{-1,0},{1,0}}; void init(){for(int i=0; i<row; i++){for(int j=0; j<col; j++){vis[i][j]=false;}}}

    bool isvalid(int i,int j){return i>=0 && i<row && j>=0 && j<col;} int bfs(int si,int sj,vector<vector<char>>& maze){
        queue<pair<pair<int,int>,int>>q({{{si,sj},0}}); vis[si][sj]=true; while(!q.empty()){
            pi=q.front().first.first; pj=q.front().first.second; dis=q.front().second; q.pop(); if((pi==0 || pi==row-1 || pj==0 || pj==col-1) && (pi!=si || pj!=sj)){return dis;} for(auto mv : mov){
                ci=pi+mv.first; cj=pj+mv.second; if(isvalid(ci,cj) && !vis[ci][cj] && maze[ci][cj]=='.'){vis[ci][cj]=true; q.push({{ci,cj},dis+1});}
            }
        }return -1;
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        row=maze.size(); col=maze[0].size(); init(); return bfs(entrance[0],entrance[1],maze);
    }
};  /* Second Approach is more easy like i just have to deal with if child cross boundary and parent idx not similar with source idx; */
