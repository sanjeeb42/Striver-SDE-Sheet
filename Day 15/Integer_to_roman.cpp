class Solution {
public:
    string intToRoman(int num) {
        

        
        vector<pair<int,string>>mapping;
        mapping.push_back({1000,"M"});
        mapping.push_back({900,"CM"});
        mapping.push_back({500,"D"});
        mapping.push_back({400,"CD"});
        mapping.push_back({100,"C"});
        mapping.push_back({90,"XC"});
        mapping.push_back({50,"L"});
        mapping.push_back({40,"XL"});
        mapping.push_back({10,"X"});
        mapping.push_back({9,IX});
        mapping.push_back({5,"V"});
        mapping.push_back({4,"IV"});
        mapping.push_back({1,"I"});
        
        
        
       string ans="";
       for(int i=0;i<14;i++){
           
       }
    }
};
