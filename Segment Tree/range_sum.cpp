class NumArray {
public:
 
    vector<int>segTree;
    int n;
    
    void build(vector<int>&nums,int index,int low,int high){
      
        
        //base case
        if(low==high){
            segTree[index]=nums[low];
            return;
        }
        
        int mid=(high+low)/2;
        
        build(nums,2*index+1,low,mid);
        build(nums,2*index+2,mid+1,high);
        
        segTree[index]=segTree[2*index+1]+segTree[2*index+2];
        
    }
      
    
    void updateTree(int locn,int val,int index,int low,int high)
    {
        if(low>locn or high<locn)return ;
        if(low==high )
        {
           if(low==locn)
             segTree[index]=val;

            return;
        }
        
        int mid=(high+low)/2;
            
        updateTree(locn,val,2*index+1,low,mid);
        updateTree(locn,val,2*index+2,mid+1,high);
        
        segTree[index]=segTree[2*index+1]+segTree[2*index+2];
        
    }
        
    int sum(int qs,int qe,int ss,int se,int index){
        
        //if no overlap return 0
        
        if(se<qs or qe<ss)
        {
            return 0;
        }
        
        //If complete Overlap
        
        if(qs<=ss && qe>=se)return segTree[index];
        
        //Else partial overlap
        int mid=ss+(se-ss)/2;
        int left=sum(qs,qe,ss,mid,2*index+1);
        int right=sum(qs,qe,mid+1,se,2*index+2);
        
        return left+right;
        
        
    }
    NumArray(vector<int>& nums) 
    {
        
        if(nums.size()>0){
        n=nums.size();
        segTree.resize(4*n,0);  
        build(nums,0,0,n-1);
        }
        
    }
    
    
    
    void update(int index, int val) {
        if(n==0)return;
        updateTree(index,val,0,0,n-1);
        
    }
    
    int sumRange(int left, int right) {
        //Calculate Sum Now
        if(n==0)return 0;
        return sum(left,right,0,n-1,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
