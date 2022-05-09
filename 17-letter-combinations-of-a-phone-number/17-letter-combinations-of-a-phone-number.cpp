class Solution {
private:
    unordered_map<int, string> mpp;
    vector<int> nums;
    vector<string> ans;
    
    void helper(int pos, string curr){
        string pre = mpp[nums[pos]];
        
        for(int i=0; i<pre.length(); i++){
            if(pos == nums.size()-1) ans.push_back(curr+pre[i]);
            else helper(pos+1, curr+pre[i]);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        
        int n = digits.size();
        
        if(n==0) return {};
        
        //initializing
        mpp[2] = "abc";
        mpp[3] = "def";
        mpp[4] = "ghi";
        mpp[5] = "jkl";
        mpp[6] = "mno";
        mpp[7] = "pqrs";
        mpp[8] = "tuv";
        mpp[9] = "wxyz";

        for(auto it: digits){
            nums.push_back(it-'0');
        }
        
        helper(0, "");
        return ans;
    }
};