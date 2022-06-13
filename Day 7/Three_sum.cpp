vector<vector<int>>twoSum(vector<int>arr,int index,int n,int target)
{
    vector<vector<int>>ans;  
    int low=index, high=n-1;
    while(low<high)
    {
        int curr=arr[low]+arr[high];
        if(curr==target)
        {   
            vector<int>temp;
            temp.push_back(arr[low]);
            temp.push_back(arr[high]);    
             ans.push_back(temp);
            while(arr[low]==arr[low+1]){
                low++;
            }
            while(arr[high]==arr[high-1]){
                high--;
            }
             low++, high--;
           
        }
        else if(curr>target)
        {
            high--;
        }
        else low++;
    }
     return ans;
}

vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
    sort(arr.begin(),arr.end());
    vector<vector<int>>res;
    for(int i=0;i<n;i++)
    {
        int target=K-arr[i];
        vector<vector<int>>ans=twoSum(arr,i+1,n,target);
        int cnt=ans.size();
        for(int k=0;k<cnt;k++)
            {
                 res.push_back({arr[i],ans[k][0],ans[k][1]});  
            }
      
        while(arr[i]==arr[i+1]){
            i++;
        }
    }

    return res;
}
