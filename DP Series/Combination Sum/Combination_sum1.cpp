class Solution {
public:
    
    void solve(set<vector<int>>&ans,vector<int>&arr,int target,vector<int>&curr,int index){
        
        int n=arr.size();
        if(target==0)
        {
            
            ans.insert(curr);
            return;
        }
        if(index>=n or target<0){
            return;
        }
        
        //Take or notTake
        //Not take
        solve(ans,arr,target,curr,index+1);
        
        //Take
        curr.push_back(arr[index]);
        solve(ans,arr,target-arr[index],curr,index);
        solve(ans,arr,target-arr[index],curr,index+1);
        curr.pop_back();
        
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>>ans;
        set<vector<int>>cans;
        vector<int>curr;
        
        solve(cans,candidates,target,curr,0);
        
        for(auto it: cans){
            ans.push_back(it);
        }
        
        return ans; 
    }
};
