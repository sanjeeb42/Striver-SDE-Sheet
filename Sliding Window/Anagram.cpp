	int search(string txt, string pat) {
	    // code here
	    vector<int>myFreq(26,0);
	    
	    for(int i=0;i<txt.length();i++){
	        myFreq[txt[i]-'a']++;
	    }
	    int k=txt.length();
	    int cnt=0;
	    vector<int>freq(26,0);
	    for(int i=0;i<pat.length();i++)
	    {
	        if(i>=k)
	       {
	          if(freq==myFreq)cnt++;
	          freq[pat[i-k]-'a']--;
	       }
	       freq[pat[i]-'a']++;
	       
	    }
	   
	   cnt+=(myFreq==freq);
	    
	    
	    return cnt;
	    
	    
	}
