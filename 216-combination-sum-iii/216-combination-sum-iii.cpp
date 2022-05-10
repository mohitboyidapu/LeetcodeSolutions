class Solution {
private:
    
    vector<vector<int>> ans;
    
    void dfs(int i, int k, int n, vector<int> &set) {
        if(set.size() == k && n==0){
            ans.push_back(set);
            return;
        }
        
        if(i>9 || (n!=0 && i>n)) return;
        
        dfs(i+1, k, n, set);
        set.push_back(i);
        dfs(i+1, k, n-i, set);
        set.pop_back();
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> set;
        dfs(1, k, n, set);
        
        return ans;
    }
};