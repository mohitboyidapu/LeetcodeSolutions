class Solution {
public:
    void permutations(int ind, int j, vector<int> nums, vector<vector<int>>& ans){
        if(ind==j-1){
            ans.push_back(nums);
            return;
        }
        
        for(int i=ind; i<j; i++){
            
            if(i!=ind && nums[i]==nums[ind]) continue;
            
            swap(nums[ind], nums[i]);
            permutations(ind+1,j, nums, ans);

        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        permutations(0, nums.size(), nums, ans);
        
        return ans;
    }
};