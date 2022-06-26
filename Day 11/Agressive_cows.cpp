bool isPossible(vector<int>&arr,int dist,int cows,int n){
    int cnt=1, last_cow=0;
    for(int i=1;i<n;i++){
        if(arr[i]-arr[last_cow]>=dist){
            cnt++;
            last_cow=i;
        }
        if(cnt==cows) return true;
    }
    return false;
}


int chessTournament(vector<int> arr , int n ,  int c){
    // Write your code here
    sort(arr.begin(),arr.end());
    int low=1, high=arr[n-1]-arr[0];
    int res=1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(isPossible(arr,mid,c,n)){
            res=mid;
            low=mid+1;
        }
        else high=mid-1;
    }
    return res;
}
