int distinctSubstring(string &word) {
    //  Write your code here.
    unordered_set<string>st;
    int n=word.length();
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            string tmp=word.substr(i,j-i+1);
            st.insert(tmp);
        }
    }  
    return st.size(); 
}
