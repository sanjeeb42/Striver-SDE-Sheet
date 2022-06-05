void sort012(int *arr, int n)
{
   //   Write your code here
    
    // Maintain 3 pointer - low= 0, high=n-1, mid=0
    int low=0,mid=0, high=n-1;    
    while(high>=mid)
    {   
        if(arr[mid]==0)
        {
            swap(arr[low++],arr[mid++]);
        }
        else if(arr[mid]==1)
        {
            mid++;
        }
        else {

            swap(arr[mid],arr[high--]);
        }
    }
}
