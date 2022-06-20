#include<bits/stdc++.h>
string reverseString(string str)
{
    // Write your code here.
    vector<string>ans;
    stringstream check1(str);
    string intermediate;
    string tmp="";

    while(getline(check1,intermediate,' '))
    {
        if(intermediate.size()>0)
        {
           ans.push_back(intermediate);
        }
    }
   
    for(int i=ans.size()-1;i>=0;i--){
        tmp+=ans[i]+" ";
    }
    return tmp;
    
}
