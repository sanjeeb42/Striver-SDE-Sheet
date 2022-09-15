class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int>ans,fans;
        
        int n=changed.size();
        if(n%2!=0)return fans;
        
        
       multiset<int>st;
        for(auto it: changed){
            st.insert(it);
        }
       while(st.size()>0)
       {
           
           int first=*st.begin();
           st.erase(st.begin());
           auto it=st.find(first*2);
           if(it==st.end())
           {
               return fans;
           }
           
           else 
           {
               
               ans.push_back(first);
               st.erase(it);
           }
          
       }
        return ans;
    }
};
