class Solution {
private:
    bool isValid(int r, int c, int n, int m, vector<vector<int>>& grid){
        if(r>=0 && c>=0 && r<=n && c<=m && grid[r][c]==0) return true;
        
        return false;
    }
    
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        if(grid[0][0] == 1) return -1;
        
        int ans = 0;
        int n = grid.size()-1;
        int m = grid[0].size()-1;
        grid[0][0] = 1;
        
        vector<vector<int>> dir = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0}, {1,1}};
        
        queue<pair<int,int>> q;
        q.push({0, 0});
        
        while(!q.empty()){
            int size = q.size();
            ans++;
            
            for(int i=0; i<size; i++){
                pair<int,int> temp = q.front();
                q.pop();
                
                if(temp.first==n && temp.second==m) return ans;
                
                for(int j=0; j<8; j++){
                    int r = temp.first + dir[j][0];
                    int c = temp.second + dir[j][1];
                    
                    if(isValid(r, c, n, m, grid)) {
                        q.push({r, c});
                        grid[r][c] = 1;
                    }

                }
            }
            
        }
        
        return -1;
    }
};