class Solution {
public:
    bool isPallindrome(string s,int start,int end,vector<string>&curr){
        int st=start,e=end;
        while(start<=end){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
   void solve(string s,int index,vector<string>curr,vector<vector<string>>&ans){
        
        int curr_index=index;
        if(index==s.length()){
            ans.push_back(curr);
            return;
        }
        
        for(int j=index;j<s.length();j++){
            if(isPallindrome(s,curr_index,j,curr))
            {
                curr.push_back(s.substr(curr_index,j-curr_index+1));
                solve(s,j+1,curr,ans); 
                curr.pop_back();
            }
        }
        
        return ;
    }
    vector<vector<string>> partition(string s) {
        int n=s.length();
        
        vector<string>curr;
        vector<vector<string>>ans;
        
        solve(s,0,curr,ans);
        return ans;
    }
};
