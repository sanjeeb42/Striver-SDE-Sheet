map<pair<int,int>,int>mp;
    
    int lis(int prev,int index,int n,int *arr)
    {
        //base case
        if(index>=n)return 0;
        if(mp.find({prev,index})!=mp.end()){
            return mp[{prev,index}];
        }
        
        int take=0, nottake=0;
        //Two cases - Take or notTake
        if(prev==-1 or arr[index]>prev)
        {
            take=1+lis(arr[index],index+1,n,arr);
        }
        nottake=lis(prev,index+1,n,arr);
        
        return mp[{prev,index}]=max(take,nottake);
    }
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int arr[])
    {
       // your code here
       int prev=-1;
       int ans=lis(prev,0,n,arr);
       return ans;
    }
