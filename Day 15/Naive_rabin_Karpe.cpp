#include<bits/stdc++.h>

vector<int> stringMatch(string &txt, string &pat)
{
    // Write your code here
    int hash_pat = 0, hash_txt=0;
    for (int i = 0; i < pat.length(); i++)
    {
        hash_pat += (pat[i] - 'A');
        hash_txt += (txt[i] - 'A');
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
        hash_txt = hash_txt + (txt[i] - 'A') - (txt[i - pat.length()] - 'A');
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
