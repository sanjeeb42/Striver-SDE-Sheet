long long ans=0;

void merge(long long arr[],long long low,long long high,long long mid){

    long long start1=low,start2=mid+1;
    long long temp[high+1];
    long long k=low;
    while(start1<=mid && start2<=high)
    {
        
        if(arr[start1]<=arr[start2]){
            temp[k++]=arr[start1++];
            
        }
        else 
        {
            ans+=(mid-start1+1);
            temp[k++]=arr[start2++];
        }
    }
    
    while(start1<=mid){
        temp[k++]=arr[start1++];
    }
    while(start2<=high)
    {
        temp[k++]=arr[start2++];
    }
    
    for(int i=low;i<=high;i++){
        arr[i]=temp[i];
    }
    
}

void mergesort(long long arr[],long long start,long long high){
    if(start>=high){
        return;
    }
    long long mid=(start+high)/2;
    mergesort(arr,start,mid);
    mergesort(arr,mid+1,high);
    merge(arr,start,high,mid);
}


long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
 
   mergesort(arr,0,N-1);
   return ans;
    
    
}
