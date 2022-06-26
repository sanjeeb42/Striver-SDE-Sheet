
int search(int* arr, int n, int key) {
    // Write your code here.
    //Agar sorted and rotated hai to we can go for binary search
    int ans=-1;
    int low=0, high=n-1;
    while(low<=high){
        
        int mid=low+(high-low)/2;
        if(arr[mid]==key)return mid;

         else if(arr[mid]>=arr[low])
         {  
            if(key>=arr[low] && key<=arr[mid])
            {
                high=mid-1;
            }
             else low=mid+1;
         } 
         else 
         {
            if(arr[mid]<=key && arr[high]>=key) low=mid+1;
              
           else high=mid-1;
         }
    }
    
    return ans;
}
