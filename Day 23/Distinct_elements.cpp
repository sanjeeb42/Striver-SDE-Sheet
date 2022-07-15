vector<int> Solution::dNums(vector<int> &A, int B)
{
    vector<int>ans;
    unordered_map<int,int> mp;
    
    for(int i=0;i<B;i++){
        mp[A[i]]++;
    }
    
    
    for(int i=B;i<A.size();i++){
        ans.push_back(mp.size());
        int tmp=mp[A[i-B]];
        if(tmp==1){
            mp.erase(A[i-B]);
        }
        else mp[A[i-B]]--;
        
        mp[A[i]]++;
       
    }
      
    ans.push_back(mp.size());   
    return ans;    
}
