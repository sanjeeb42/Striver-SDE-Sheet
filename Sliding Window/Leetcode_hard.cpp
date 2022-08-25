class Solution
{
    public:
        string minWindow(string s, string t)
        {
            unordered_map<char, int> mp1;
            for (auto it: t)
            {
                mp1[it]++;
            }

            int matchcount = t.length();
            unordered_map<char, int> mp2;
            int mycount = 0;
            int i = 0, j = 0;
            int len = INT_MAX;
            string ans = "";
            int n = s.length();
            while (j < n)
            {

                if (mycount < matchcount)
                {
                   	//Time to accquire
                    if (mp1.find(s[j]) != mp1.end())
                    {
                        if (mp1[s[j]] > mp2[s[j]])
                        {
                            mycount++;
                        }
                        mp2[s[j]]++;
                    }
                }

                if (mycount == matchcount)
                {
                   	//Time to release
                  //  cout<<"Entered for i: "<<i<<" and j: "<<j<<endl;
                    while (mycount >= matchcount)
                    {
                      //  cout<<"Running for i: "<<i<<" and j: "<<j<<" and len: "<<len<<endl;
                        if (j - i + 1 < len)
                        {
                           // cout<<"Entry Here"<<endl;
                          //  cout<<s.substr(i,j-i+1)<<endl;
                            ans = s.substr(i, j-i + 1);
                            len = j - i + 1;
                        }

                       	//Not Presrent in t

                        if (mp1.find(s[i]) == mp1.end()) {}
                       	//Presnt and deleted and its freq is much greater
                        else if (mp2[s[i]] > mp1[s[i]])
                        {
                            mp2[s[i]]--;
                        }
                       	//Present and mycount affected 
                        else
                        {
                            mp2[s[i]]--;
                            mycount--;
                        }

                        i++;
                    }
                }
                
                j++;
            }

            return ans;
        }
};
