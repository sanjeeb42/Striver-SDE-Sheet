//naive - O(N+M/ 2) time amd o(1) space


double median(vector<int> nums1, vector<int> nums2)
{
    // Write your code here.
    
    int n=nums1.size(), m=nums2.size();
        int first=0, second=0;
        int index=0;
        int firstindex=(n+m)/2, secondindex=((n+m)/2) -1;
        int firstmid=0, secondmid=0;
        while(first<n && second< m)
        {
            if(nums1[first]<=nums2[second])
            {
                if(index==firstindex)
                {
                   firstmid=nums1[first];
                    break;
                }
                if(index==secondindex)
                {
                    secondmid=nums1[first];
                }
                index++;
                first++;
                
            }
            else 
            {
                if(index==firstindex)
                {
                    firstmid=nums2[second];
                    break;
                }
                if(index==secondindex)
                {
                    secondmid=nums2[second];
                }
                second++;
                index++;
            }
            
        }
        
        while(first<n & firstmid==0 ){
            if(index==firstindex){
                    firstmid=nums1[first];
                    break;
                }
                if(index==secondindex){
                    secondmid=nums1[first];
                    break;
                }
            first++;
            index++;
        }
         while(second<m & firstmid==0){
              if(index==firstindex){
                 
                    firstmid=nums2[second];
                  break;
                }
                if(index==secondindex){
                    secondmid=nums2[second];
                }
             second++;
             index++;
        }
  
        
        bool iseven=(n+m)%2;
        
        double ans=0;
        if(iseven){
            ans=firstmid;
        }
        else{
            ans=firstmid+secondmid;
            ans=ans/2;
        }
        
        return ans;
}



// Better is binary search

