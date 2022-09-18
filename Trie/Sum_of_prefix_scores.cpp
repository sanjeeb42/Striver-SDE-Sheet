//https://leetcode.com/problems/sum-of-prefix-scores-of-strings/


class TrieNode
{
  public:
  char data;
  TrieNode *child[26];
 // bool isEnd;
  int val = 0;

  TrieNode(char ch)
  {
    data = ch;
    for (int i = 0; i < 26; i++)
    {
      child[i] = NULL;
    }
    val = 1;
  }
};



class Trie
{
public:
  TrieNode *root;

  Trie()
  {
    root = new TrieNode('\A');
  }
  void Helperinsert(TrieNode *root, string &word,int in)
  {

    if (word.length() == in)
    {
      root->val++;
      return;
    }
    root->val++;
    int index = word[in] - 'a';
    TrieNode *next;

    if (root->child[index] != NULL)
    {      
      next = root->child[index];
        
    }

    else
    {
      // Create a new Node
      next = new TrieNode(word[in]);
      root->child[index] = next;
        
    }

    Helperinsert(next, word,in+1);
  }

  void Helpersearch(TrieNode *root, string \word,int &ans,int in)
  {
   // cout<<root->data<<" and "<<root->val<<endl;
    if(root->data!='\A'){
        ans+=(root->val)-1;
    }
    if (word.length() == in)
    {
      // if (root->isEnd == true)
      // {
      //   return true;
      // }
      // else
      //   return false;
        return ;
    }
    
    int index = word[in] - 'a';

    if (root->child[index] == NULL)
      return ;
    else Helpersearch(root->child[index], word,ans,in+1);
  }
 
  void insert(string word)
  {
    Helperinsert(root, word,0);
  }

  int search(string word)
  {
     int ans=0;
     Helpersearch(root, word,ans,0);
     return ans;
  }

};

class Solution {
public:
    Trie *t = new Trie;
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int>ans;
        int n=words.size();
        for(int i=0;i<n;i++){
            t->insert(words[i]);
        }
        
        for(int i=0;i<n;i++)
        {
            int fans=t->search(words[i]);
            ans.push_back(fans);
        }
        
        return ans;
    }
};
