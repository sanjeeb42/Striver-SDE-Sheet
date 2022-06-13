int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
    int left=0, right=0;
    for(int i=1;i<n;i++)
    {
        if(arr[i]!=arr[i-1]){
            arr[left++]=arr[right++];
        }
        else right++;
    }
    return (left+1);
    
}
