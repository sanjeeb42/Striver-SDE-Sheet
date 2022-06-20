class Solution {
public:
    bool blackbox(vector<int>&arr,int n,int threshold,int x){
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=(arr[i]/x);
            if(arr[i]%x!=0){
                sum++;
            }
            
        }
        bool ans= sum<=threshold?true:false;
        return ans;
    }
    
    int smallestDivisor(vector<int>& arr, int threshold) {
        int n=arr.size();
        int maxi=arr[0];
        for(int i=1;i<n;i++){
            maxi=max(maxi,arr[i]);
        }
        int ans=-1;
        int low=1, high=maxi;
        while(low<=high){
            
            int mid=low+(high-low)/2;
            if(blackbox(arr,n,threshold,mid)){
                //Yes this part gives me answer .
                //Now check for lower part 
                //ie, high=low-1
                //also update ans=mid;
                ans=mid;
                high=mid-1;
            }
            else {
                //This mid is giving me a sum larger than threshold
                // So we need to increase the denominator to get less sum
                // Indirectly increase low to mid+1
                low=mid+1;
            }
        }
        return ans;
    }
};
