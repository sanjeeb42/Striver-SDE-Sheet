#include<bits/stdc++.h>

vector<int> stringMatch(string &txt, string &pat)
{
    // Write your code here
    
    //Lets optimise it- Only change the hash function
    // Lets make it quadratic instead of linear
    // hash = a[0]*pow(patternlen-1) + a[1]* pow(patternlen-2)+....
    int d=5;// Any thing ur choice 
    int q=1e9+7;// a prime number to overcome modulo
    int power=pow(d,pat.length()+1);
    power=power%q;
    int hash_pat = 0, hash_txt=0;
    for (int i = 0; i < pat.length(); i++)
    {
        hash_pat =((hash_pat +  (pat[i] - 'A'))*d)%q;
        hash_txt =((hash_txt + (txt[i] - 'A'))*d)%q;
    }
    
    

    vector<int> ans;
    if (hash_pat == hash_txt)
    {
        int i = 0;
        while (i < pat.length())
        {
            if (txt[i] != pat[i])
            {
                break;
            }
            i++;
        }
        if (i == pat.length())
        {
            ans.push_back(0);
        }
    }

    for (int i = pat.length(); i < txt.length(); i++)
    {

        // Recompute the new hash value of txt
      //  hash_txt = hash_txt + (txt[i] - 'A') - (txt[i - pat.length()] - 'A');
        
        hash_txt= ((hash_txt*d)-(txt[i-pat.length()]-'A')*power 
            +(txt[i]-'A')*d)%q;
        if (hash_txt == hash_pat)
        {

            int j = 0;
            while (j < pat.length())
            {
                if (txt[j + i - pat.length() + 1] != pat[j])
                {
                    break;
                }
                j++;
            }
            if (j == pat.length())
            {
                ans.push_back(i - pat.length() + 1);
            }
        }
    }

    return ans;
}
