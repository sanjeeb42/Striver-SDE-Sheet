class Solution{
  public:
    int longestKSubstr(string s, int k) 
    {
    // your code here
    int ans=0;
    int i=0, j=0;
    int n=s.size();
    unordered_map<char,int>mp;
    while(j<n)
    {
        if(mp.size()<k)
        {
            mp[s[j]]++;
            j++;
        }
        else if(mp.size()==k)
        {
            ans=max(ans,j-i);
            mp[s[j]]++;
            j++;
        }
        else if(mp.size()>k)
        {
            while(mp.size()>k){
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
            }
            
            ans=max(ans,j-i);
           
        }
    }
    
    if(mp.size()==k)ans=max(ans,j-i);
    
    return ans==0?-1:ans;
    
    }
