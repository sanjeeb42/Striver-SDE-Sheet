 vector<int> leftSmaller(int n, int a[]){
        // code here
        stack<int>st;
        vector<int>ans;
        ans.push_back(-1);
        st.push(a[0]);
        
        for(int i=1;i<n;i++){
            int curr=a[i];
            if(st.top()<curr){
                ans.push_back(st.top());
            }
            else {
                    while(st.size()>0 && st.top()>=curr){
                    st.pop();
                }
            
                if(st.size()==0){
                    ans.push_back(-1);
                }
                else ans.push_back(st.top());
                
            }
            st.push(curr);
        }
        
        return ans;
    }
