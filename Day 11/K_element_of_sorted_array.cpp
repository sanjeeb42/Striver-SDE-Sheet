#include<bits/stdc++.h>

// int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
//     // Write your code here.
//    priority_queue <int, vector<int>, greater<int> > pq;
//     for(auto it:row1){
//         pq.push(it);
//     }
    
//     for(auto it:row2)
//     {
//         pq.push(it);
//     }
    
//     for(int i=0;i<k-1;i++){
//         pq.pop();
//     }
    
//     return pq.top(); 
// }

// int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) 
// {
//     int cnt=0;
//     int start1=0, start2=0;
//     while(start1<m && start2<n)
//     {
//         if(row1[start1]<=row2[start2]){
//             cnt++;
//              if(cnt==k){
//                 return row1[start1];
//             } 
//             start1++;
//         }
//         else {
//             cnt++;
//             if(cnt==k){
//                 return row2[start2];
//             }      
//           start2++;
//         }      
//     }   
//     while(start1<m){
//         cnt++;
//         if(cnt==k) return row1[start1];
//         start1++;
//     }    
//     while(start2<n){
//         cnt++;
//         if(cnt==k) return row2[start2];
//         start2++;
//     }  
//     return -1;   
// }

int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) 
{
    if(m>n) return ninjaAndLadoos(row2,row1,n,m,k);
    
    // assume 6 element in arr1 and 12 element in arr2 and k=18
    // we can take maximum of 12 eleemnts from arr2 
    // That means minimum of 6 element from arr1
    // Hence low=max(0,k-arr2.size())
    
    // For High , we can take maximum = arr1.size()
    // Assume we need to find 4th element , Then maximum we can take 
    // 4 elemet from arr1 and 0 from arr2
    //Hence high=min(arr1.size(), k)
    int low=max(0,k-n),high=min(k,m);
    
    while(low<=high)
    {
        int cut1=low+(high-low)/2;
        int left1=INT_MIN, left2=INT_MIN;
        int right1=INT_MAX, right2=INT_MAX;
            
       if(cut1>0){ left1=row1[cut1-1];}
       if(cut1!=row1.size())right1=row1[cut1];
       int cut2=k-cut1;

        if(cut2>0){left2=row2[cut2-1];}
        if(cut2!=row2.size())right2=row2[cut2];
        if(left1<=right2 && left2<=right1){
            return max(left1,left2);
        }
        else if(left1>right2){
            high=cut1-1;
        }
        else low=cut1+1;   
    }
    return 1;
}
