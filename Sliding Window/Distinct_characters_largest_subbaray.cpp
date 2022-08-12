class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int i=0,j=0;
        int ans=0;
        
        unordered_map<char,int>mp;
        
        while(j<n)
        {
            
            //Case 1: If it is not present in Map
            if(mp.find(s[j])==mp.end()){
                mp[s[j]]=j;
                ans=max(ans,j-i+1);
            }
            
            //Case 2: It is already Present in Map
            else if(mp.find(s[j])!=mp.end()){
                ans=max(ans,j-i);
                i=max(i,mp[s[j]]+1);
                mp[s[j]]=j;
            }  
            j++;
        }
        
        ans=max(ans,j-i);
        return ans;
    }
};
