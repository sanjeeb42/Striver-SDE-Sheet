class Solution
{

    public:
        vector<vector < string>> findLadders(string start, string end, vector<string> &wordList)
        {

           	//A Set to store if that string has been already reached before 
            unordered_set<string> st(wordList.begin(), wordList.end());
            vector<string> toerase;
            vector<vector < string>> fans;
            queue<vector < string>> q;

           	//Now Time to do bfs
            q.push({start});
            toerase.push_back(start);

           	//Try changing every index from a to z and if the new string
           	//exist in step means transformation allowed
           	// So remove this new string from set and push this new string into queue
            bool flag=false;
            while (q.size() > 0)
            {

                int size = q.size();
                
                for(auto it: toerase){
                    st.erase(it);
                }
                
                toerase.clear();

               	//List of element to be erase after this level

                for (int i = 0; i < size; i++)
                {
                    auto front = q.front();
                    q.pop();

                   	//Finding the last String
                    string curr = front.back();
                    if (curr == end)
                    {
                        flag=true;
                        fans.push_back(front);
                        continue;
                    }
                    for (int i = 0; i < curr.length(); i++)
                    {
                        char tmp = curr[i];
                        for (char j = 'a'; j <= 'z'; j++)
                        {
                            curr[i] = j;
                            if (st.find(curr) != st.end())
                            {
                               	//Found valid transfomation
                                front.push_back(curr);
                                q.push(front);
                                front.pop_back();
                                toerase.push_back(curr);
                            }
                        }
                        curr[i] = tmp;
                    }
                }

                if (flag) return fans;
               
            }
            return fans;
        }
};
