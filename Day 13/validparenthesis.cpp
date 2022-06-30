#include<bits/stdc++.h>

bool isValidParenthesis(string s)
{
    // Write your code here.
    stack<char>st;
    int n=s.length();
    for(int i=0;i<n;i++){
        if(s[i]=='(' or s[i]=='{' or s[i]=='['){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            if(st.empty() or st.top()!='(') return false;
            else st.pop();
        }
        
        else if(s[i]=='}'){
            if(st.empty() or st.top()!='{') return false;
            else st.pop();
        }
        else if(s[i]==']'){
            if(st.empty() or st.top()!='[') return false;
            else st.pop();
        }
        
    }
    return st.empty()==true?true: false;
}
