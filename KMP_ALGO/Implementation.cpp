vector<int>compute_lps(string &pattern){
        int n=pattern.length();
        vector<int>lps(n,0);
        lps[0]=0; // We want proper prefix which is also a suffix , so length 1 isn't 

        int len=0,i=1;
        while(i<n){
            if(pattern[i]==pattern[len]){
                lps[i++]=++len;
            }
            else {
                if(len!=0){
                    len=lps[len-1]; //  abcabcx........abcabcy not matching at x & y 
                                    //  Par dekho abc abc repeat ho rha hai to maine islye 
                                    //  pucha c se bhai kitna match hua hai , usne bola abc =3 length to len=3 pe try kiya 
                                    //. a ko match karne ka try kiya with y 
                }
                else lps[i++]=0;
            }
        }
        return lps;
    }

    int kmp_algo(string &text,string &pattern,vector<int>&lps){
        int n=text.length(),m=pattern.length();
        int i=0,j=0;

        while(i<n && j<m){
            if(text[i]==pattern[j]){
                i++;
                j++;
            }
            else {
                if(j!=0)j=lps[j-1];
                else i++;
            }
        }
        cout<<i<<endl;
        if(j==m)return i-1;
        return -1;
    }
