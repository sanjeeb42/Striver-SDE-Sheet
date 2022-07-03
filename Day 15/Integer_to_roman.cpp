#include<bits/stdc++.h>
class Solution {
public:
    string intToRoman(int num) {
        

        
    vector<string>mapping={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};      
    vector<int>val={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        
       string ans="";
       for(int i=0;i<val.size();i++){
           int tmp=num/val[i];
           
           for(int j=0;j<tmp;j++){
               ans+=mapping[i];
           }
           
           num=num-tmp*val[i];
       }
        
        return ans;
    }
};
