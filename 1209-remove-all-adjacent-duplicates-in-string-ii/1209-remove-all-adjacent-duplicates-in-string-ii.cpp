class Solution {
public:
    string removeDuplicates(string s, int k) {
        //Stack based Solution
        stack<pair<char, int>> st;
        
        int n = s.length();
        for(int i=0; i<n; i++){
            if(st.empty()|| st.top().first != s[i]) st.push({s[i], 1});
            else{
                auto node = st.top();
                st.pop();
                st.push({node.first, node.second+1});
            }
            if(st.top().second == k) st.pop();
        }
        string ans = "";
        
        while(!st.empty()){
            auto temp = st.top();
            st.pop();
            
            while(temp.second--){
                ans += temp.first;
            }
        }
        
        //As this is a stack we get the answer in reverse manner, 
        //so just reverse the string before returning
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};