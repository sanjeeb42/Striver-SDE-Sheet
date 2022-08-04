class Solution{
  public:
    vector <int> countDistinct (int arr[], int n, int k)
    {
        //code here.
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<k-1;i++){
            mp[arr[i]]++;
        }
        
        int j=-1;
        
        for(int i=k-1;i<n;i++)
        {
            mp[arr[i]]++;
            ans.push_back(mp.size());
            j++;
            mp[arr[j]]--;
            if(mp[arr[j]]==0){
                mp.erase(arr[j]);
            }
        }
       // ans.push_back(mp.size());
        
        return ans;
    }
};
