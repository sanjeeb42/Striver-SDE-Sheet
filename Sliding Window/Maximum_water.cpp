class Solution {
public:
    
    int solve(vector<int>&arr){
        int n=arr.size();
        int i=0, j=n-1;
        
        
        int ans=0;
        
        while(i<j)
        {
            ans=max(ans,min(arr[i],arr[j])*(j-i));
            if(arr[i]<=arr[j])i++;
            else j--;
           
        }
        return ans;
    }
    int maxArea(vector<int>& height) {
        return solve(height);
  
