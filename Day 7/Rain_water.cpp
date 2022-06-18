#include <bits/stdc++.h> 
long max(long a,long b){
return a>b?a:b;
}
long getTrappedWater(long *arr, int n){
    // Write your code here.
    vector<long>lmax(n), rmax(n);
    lmax[0]=arr[0], rmax[n-1]=arr[n-1];
    for(int i=1;i<n;i++){
        lmax[i]=max(lmax[i-1],arr[i]);
    }
    for(int j=n-2;j>=0;j--){
        rmax[j]=max(rmax[j+1],arr[j]);
    }
    
    long res=0;
    for(int i=1;i<n-1;i++){
        res+=(min(lmax[i],rmax[i])-arr[i]);
    }
    return res;   
}
