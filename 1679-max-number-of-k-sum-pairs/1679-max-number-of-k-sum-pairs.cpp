class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        //without modifying the given array
        // application of 2 sum
        
        unordered_map<int,int> freq;
        int cnt = 0;
        
        for(auto it : nums){
            if(freq[k-it]){
                freq[it]--;
                freq[k-it]--;
                cnt++;
            }
            freq[it]++;
        }
        return cnt;
    }
};