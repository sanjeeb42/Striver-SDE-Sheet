#include<bits/stdc++.h>

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    // code here
    
        // Your code here
        // code here
        vector<int>ans;
        stack<int>st;
        
        for(int i=n-1;i>=0;i--){
            
            if(st.size()==0) ans.push_back(-1);
            else if(st.top()<arr[i]) ans.push_back(st.top());
            else if(st.top()>=arr[i])
            {
                // 2 cases - Pop until u find a smller element or else stack is empty
                
                while(st.size()>0 && st.top()>=arr[i]){
                    st.pop();
                }
                
                // Check which was responmsoble for end of loop
                if(st.size()==0) ans.push_back(-1);
                else ans.push_back(st.top());
            }
            st.push(arr[i]);
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
        
    
    }
