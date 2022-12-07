class Solution
{
    public:
        int ladderLength(string start, string end, vector<string> &wordList)
        {

           	//A Set to store if that string has been already reached before 
            unordered_set<string> st;
            for (auto it: wordList)
            {
                st.insert(it);
            }

           	//Now Time to do bfs
            queue<pair<string, int>> q;
            q.push({ start,
                1 });

            int ans = 0;
            
            //Try changing every index from a to z and if the new string
            //exist in step means transformation allowed
            // So remove this new string from set and push this new string into queue
            while (q.size() > 0)
            {

                auto front = q.front();
                q.pop();

                string curr = front.first;
                int distance = front.second;
                if (curr == end) return distance;
                for (int i = 0; i < curr.length(); i++)
                {
                    char tmp = curr[i];
                    for (int j = 'a'; j <= 'z'; j++)
                    {

                        curr[i] = j;
                        if (st.find(curr) != st.end())
                        {
                           	//Found valid transfomation
                            q.push({ curr,
                                distance + 1 });
                            st.erase(curr);
                        }
                    }
                    curr[i] = tmp;
                }
            }

            return ans;
        }
};
