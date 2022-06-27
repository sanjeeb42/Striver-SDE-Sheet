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


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s = "Hey, How are you doing?";
    stack<string> ans;
    for (int i = 0; i<s.length(); i++)
    {
        string tmp = "";
        int j = i;
        while (j < s.length() && s[j] != ' ')
        {
            tmp += s[j++];
        }
        i = j;

        //cout << tmp << endl;
         ans.push(tmp);
    }
    while (!ans.empty())
    {
        cout << ans.top() << " ";
        ans.pop();
    }
    return 0;
}
