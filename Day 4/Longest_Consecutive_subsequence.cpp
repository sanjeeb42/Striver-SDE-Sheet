int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    sort(arr.begin(),arr.end());
    int count=1;
    int ans=1;
    for(int i=0;i<n-1;i++){
        if(arr[i]+1==arr[i+1])
        {
            count++;
        }
        else if(arr[i]==arr[i+1])
        {
           count+=0; 
        }
        else count=1;
        ans=max(ans,count);
    }
    return ans;
}
