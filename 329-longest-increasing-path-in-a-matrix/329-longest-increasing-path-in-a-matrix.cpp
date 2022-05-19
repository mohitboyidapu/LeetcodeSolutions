class Solution {
private:
    int r;
    int c;
    vector<vector<int>> dp;
    
    int dfs(int i, int j, vector<vector<int>>& matrix){
        
        if(dp[i][j] > 0) return dp[i][j];
        
        int res = 1;
        
        if( i+1<r  && matrix[i+1][j] > matrix[i][j]) res = max(res, 1+dfs(i+1, j, matrix)); 
        if( i-1>=0 && matrix[i-1][j] > matrix[i][j]) res = max(res, 1+dfs(i-1, j, matrix));
        if( j+1<c  && matrix[i][j+1] > matrix[i][j]) res = max(res, 1+dfs(i, j+1, matrix));
        if( j-1>=0 && matrix[i][j-1] > matrix[i][j]) res = max(res, 1+dfs(i, j-1, matrix));
        
        dp[i][j] = res;
        return res;

    }
    
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        r = matrix.size();
        c = matrix[0].size();
        
        dp = vector<vector<int>>(r, vector<int>(c, 0));
        int res = 0;
        
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                res = max(res, dfs(i, j, matrix));
            }
        }
        
        return res;
    }
};