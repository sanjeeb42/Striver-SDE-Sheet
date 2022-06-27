#include<bits/stdc++.h>

int left_child(int i){
    return 2*i+1;
}
int right_child(int i){
    return 2*i+2;
}
int parent_node(int i){
    return (i-1)/2;
}
void insert_key(vector<int>&heap,int key)
{
    int index=heap.size();
    heap.push_back(key);
    
    int parent=parent_node(index);
    while(index>0 && heap[parent]>heap[index])
    {
        swap(heap[parent], heap[index]);
        index=parent;
        parent=parent_node(index);
    }
}

int delete_key(vector<int>&heap){
    int ans=heap[0];
    int index=heap.size();
    swap(heap[0],heap[index-1]);
    heap.erase(heap.end()-1);
    index--;
    int parent=0;
    while(parent<index){
        int left=left_child(parent);
        int right=right_child(parent);
        int to_swap=0;
        int curr_val=heap[parent];
        int idx=parent;
        if(left<index && curr_val>heap[left]){
            to_swap=1;
            idx=left;
            curr_val=heap[left];
        }
        
        if(right<index && curr_val>heap[right]){
            to_swap=2;
            idx=right;
            curr_val=heap[right];
        }
        swap(heap[parent],heap[idx]);
        
        if(to_swap==1){
            parent=left;
        }
        else if(to_swap==2){parent=right;}
        else break;
    }
    
    return ans;
    
    
}
vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    int queries=q.size();
    vector<int>ans;
    vector<int>heap;
    
    for(int i=0;i<queries;i++){
        int type=q[i][0];
        if(type==0){
            insert_key(heap,q[i][1]); 
        }
        else{
            int res=delete_key(heap);
          ans.push_back(res);
        }
        
//         for(auto it: heap){
//                     cout<<it<<" ";
//                 }
//                 cout<<endl;
        }
    return ans;
}

