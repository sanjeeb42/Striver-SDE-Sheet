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


// Optimised Approach


/*
    Time complexity: O( N * log( N ) )
    Space complexity: O( N )

    Where N is the size of heap array.
*/

// Left child of the node.
int left(int k) {
    return 2 * k + 1;
}

// Right child of the node.
int right(int k) {
    return 2 * k + 2;
}

// Returns the parent node.
int parent(int k) {
    return (k - 1) / 2;
}

// Heapify the heap
int heapify(vector < int > & heap, int k, int & size) {

    // Find the left child of the node.
    int l = left(k);

    // Find the right child of the node.
    int r = right(k);

    // Find the smallest element between the current node and its children.
    // Check if the left child is smallest.
    int smallest = k;

    if (l < size && heap[l] < heap[k]) {
        smallest = l;
    }

    // Check if the right node is smallest then the previous smallest.
    if (r < size && heap[r] < heap[smallest]) {
        smallest = r;
    }

    // If the smallest element is not in the current node.
    // We have to heapify the Heap to take that element to the top.
    if (smallest != k) {

        // Swap the values of current node and the smallest node value.
        int tempp = heap[k];
        heap[k] = heap[smallest];
        heap[smallest] = tempp;

        // Call the heapify function on smallest value node which now contains the value of parent node.
        heapify(heap, smallest, size);
    }
}

// Insert a val in the heap.
// Function contains heap array, val to inserted and the current size of the heap.
void insert(vector < int > & heap, int val, int & size) {

    // Insert the val at the end of the heap.
    heap[size] = val;

    // If There is nore than 1 node in the Heap.
    // MinHeapify the heap by checking the val at its parent node.
    // Also do it until the heap property is not satisfied.
    int i = size;

    size += 1;

    while (i != 0 && heap[parent(i)] > heap[i]) {

        // Swap the value of current node with its parent.
        swap(heap[i], heap[parent(i)]);

        // Check that if the parent element of current element is satisfying the heap property.
        i = parent(i);
    }
}

int extractMin(vector < int > & heap, int & size) {

    // Check if the current node is the only node in the heap.
    if (size == 1) {
        size -= 1;
        return heap[0];
    }

    // Takeout the min value and remove it from the heap.
    int val = heap[0];

    // Put last node on the top of heap.
    heap[0] = heap[size - 1];

    // Decrease the size of heap as the minimum element is removed.
    size -= 1;

    // Heapify the heap to satisfy the heap property.
    heapify(heap, 0, size);

    return val;
}

// minHeap function which take size of Queries and Queries as Input.
// Returns an array out outputs depending on the query.
vector < int > minHeap(int n, vector < vector < int >> & q) {

    int size = 0;

    vector < int > heap(n);

    // Define an array which stores the min elements.
    vector < int > ans;

    // For each query in the array Q.
    for (int i = 0; i < n; i++) {

        // If query is of type 1 then insert the value in the heap.
        // Else take min element from the heap and append it in the ans.
        if (q[i][0] == 0) {
            insert(heap, q[i][1], size);
        } else {
            ans.push_back(extractMin(heap, size));
        }
    }

    // Return the ans array.
    return ans;
}

