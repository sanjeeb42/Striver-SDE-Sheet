#include<bits/stdc++.h>
int romanToInt(string s) {
    // Write your code here
    int ans=0;
    unordered_map<char,int>mp;
    mp.insert({'I',1});
    mp.insert({'V',5});
    mp.insert({'X',10});
    mp.insert({'L',50});
    mp.insert({'C',100});
    mp.insert({'D',500});
    mp.insert({'M',1000});
    char lastchar=s[0];
    for(int i=0;i<s.length()-1;i++){
        char curr=s[i], next=s[i+1];
        if(mp[curr]<mp[next]){
            ans-=mp[curr];
        }
        else ans+=mp[curr];
   }
    ans+=mp[s[s.length()-1]];
    return ans;
}
