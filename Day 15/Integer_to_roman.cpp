class Solution {
public:
    string intToRoman(int num) {
        
        unordered_map<string,int> conv{
        {"M", 1000},
        {"D", 500},
        {"C", 100},
        {"L", 50},
        {"X", 10},
        {"V", 5},
        {"I", 1},
        {"IV", 4},
        {"IX", 9},
        {"XL", 40},
        {"XC", 90},
        {"CD", 400},
        {"CM", 900},
        {"", 0}};
        
        vector<pair<int,string>>mapping;
        mapping.push_back({1000,"M"});
        mapping.push_back({});
        mapping.push_back({});
        mapping.push_back({});
        mapping.push_back({});
        mapping.push_back({});
        mapping.push_back({});
        mapping.push_back({});
        mapping.push_back({});
        mapping.push_back({});
        mapping.push_back({});
        mapping.push_back({});
        mapping.push_back({});
        mapping.push_back({});
        mapping.push_back({});
        mapping.push_back({});
        
        
        
       string ans="";
       for(int i=0;i<14;i++){
           
       }
    }
};
