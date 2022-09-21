https://practice.geeksforgeeks.org/problems/license-key-formatting/1

string ReFormatString(string s, int K){
    	string ans="";
    	int n=s.length();
        int foundfirst=-1;
        
    	for(int j=0;j<n;j++)
    	{
    	    if(s[j]=='-'){
    	        if(foundfirst==-1){
    	            foundfirst=j;
    	        }
    	        continue;
    	    }
    	    if(s[j]>='a' && s[j]<='z'){
    	        ans.push_back('A'+(s[j]-'a'));
    	    }
    	    else ans.push_back(s[j]);
    	        
    	}
    	
    	//Done Traversing the first part
    	int cnt=0;
    	for(int j=ans.length()-1;j>=0;j--){
    	    if(cnt==K){
    	        ans.insert(ans.begin()+j+1,'-');
    	        cnt=0;
    	    }
    	    cnt++;
    	    
    	}
    	
    	return ans;
    }
