class Solution {
public:
    bool istrue(int i,int j,int k,string s1,string s2,string s3,vector<vector<int>>&dp)
    {
        // Base case
        if(i==s1.length() && j==s2.length() && k==s3.length()) return true;
        
        else if(k==s3.length())
        {
            return false;
        }
        
        //recursive call
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s3[k] && istrue(i+1,j,k+1,s1,s2,s3,dp)){
            return dp[i][j]=true;
        }
        
        if(s2[j]==s3[k] && istrue(i,j+1,k+1,s1,s2,s3,dp))
        {
            return dp[i][j]=true;
        }
        
        return dp[i][j]=false;
        
    }
    
    bool isInterleave(string s1, string s2, string s3)
    {
        if(s1.length()+s2.length()!=s3.length())
            return false;
            
        vector<vector<int>>dp(s1.length()+1,vector<int>(s2.length()+1,-1));
        return istrue(0,0,0,s1,s2,s3,dp);
    }
};
