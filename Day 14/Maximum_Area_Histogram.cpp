1. Find Nearest smaller index on right
2. Find Nearest smaller index on Left
3. Find width: right[i]-left[i]-1
4. Ans = max(ans,wideth[i]*heights[i])


#include<bits/stdc++.h>

vector<int> NSR(vector<int>&arr){
    vector<int>right;
    int n=arr.size();
    int psuedo_index=n;
    
    stack<pair<int,int>>st;
    for(int i=n-1;i>=0;i--){
        if(st.empty())
        {
            right.push_back(psuedo_index);
           
        }
        else if(st.top().first<arr[i]){
            right.push_back(st.top().second);
        }
        
        else
        {
            while(st.size()>0 && st.top().first>=arr[i]){
                st.pop();
            }
            if(st.size()==0){
                right.push_back(psuedo_index);
            }
            else {
                right.push_back(st.top().second);
            }
            
        }
        
        st.push({arr[i],i}); 
        
    }
    reverse(right.begin(),right.end());
    
    return right;
    
} 

vector<int> NSL(vector<int>&arr){
    vector<int>left;
    int n=arr.size();
    int psuedo_index=-1;
    
    stack<pair<int,int>>st;
    for(int i=0;i<n;i++){
        if(st.empty())
        {
            left.push_back(psuedo_index);
           
        }
        else if(st.top().first<arr[i]){
            left.push_back(st.top().second);
        }
        
        else
        {
            while(st.size()>0 && st.top().first>=arr[i]){
                st.pop();
            }
            if(st.size()==0){
                left.push_back(psuedo_index);
            }
            else {
                left.push_back(st.top().second);
            }
            
        }
        
        st.push({arr[i],i}); 
        
    }
    
    return left;
    
} 


int largestRectangle(vector < int > & heights) {
   // Write your code here.
    vector<int>right=NSR(heights);
    vector<int>left=NSL(heights);
    
//     for(auto it: left){
//         cout<<it<<" ";
//     }
//     cout<<endl;
//      for(auto it: right){
//         cout<<it<<" ";
//     }
//     cout<<endl;
    int n= heights.size();
    vector<int>width(n);
    for(int i=0;i<n;i++){
        width[i]=right[i]-left[i]-1;
    }
    
//     for(auto it: width){
//         cout<<it<<" ";
//     }
//     cout<<endl;
    
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,width[i]*heights[i]);
    }
    
    return ans;
 }
