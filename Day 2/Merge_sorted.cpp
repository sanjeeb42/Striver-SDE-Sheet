 void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int i=0, j=0;
        while(i<m && j<n)
        {
            if(nums1[i]<=nums2[j])
            {
                i++;
            }
            else 
            {
                // We need to insert it in correct place
                // here we go
                swap(nums1[i],nums2[j]);
                i++;
                int k=j+1;
                while(k<n and nums2[k]<nums2[k-1])
                {
                   swap(nums2[k],nums2[k-1]);
                    k++;
                }
            }
        }
        i=0;
        for(int k=m;k<(m+n);k++)
        {
            nums1[k]=nums2[i];
            i++;
        }
        
    }



// Efficinet Approach or We can also use Gap method
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        int i = n-- + m-- - 1;
        while(m >= 0){
            if(n == -1 || nums2[m] >= nums1[n]) nums1[i--] = nums2[m--];
            else nums1[i--] = nums1[n--];
        }
    }
