bool areAnagram(string &str1, string &str2){
    // Write your code here.
    vector<int>freq(300,0);
    
    if(str1.length()!=str2.length())return false;
    for(int i=0;i<str1.length();i++){
        freq[str1[i]-'\0']++;
        
    }
    
    for(int i=0;i<str2.length();i++){
        freq[str2[i]-'\0']--;
        }
    
    bool ans=true;
    for(int i=0;i<300;i++){
        if(freq[i]!=0){
            ans=false;
            break;
        }
    }
    
    return ans;   
}
