 // 72/80 -TLE


class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    int childcount;
    bool isEnd;
    
    TrieNode(char ch){
        data=ch;
        childcount=0;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isEnd=false;
    }
};

class Trie {

public:

    /** Initialize your data structure here. */
    TrieNode *root;
    Trie()
    {
        root=new TrieNode('#');
    }  
    void Helperinsert(TrieNode* root,string word)
    {       
        //base Case
        if(word.length()==0){
            root->isEnd=true;
            return;
        }
        
        //Else do the necesaary requirements
        int index=word[0]-'a';
        
        TrieNode* next;
        if(root->children[index]!=NULL){
            next=root->children[index];
        }
        else {
            next=new TrieNode(word[0]);
            root->childcount++;
            root->children[index]=next;
        }
        Helperinsert(next,word.substr(1));
    }
      
    /** Inserts a word into the trie. */
    void insert(string word) {
        Helperinsert(root,word);
    }
    
    
    void lcp(string &ans,string word){
        
        //Base case
        int n=word.length();
        
        for(int i=0;i<n;i++)
        {
            char ch=word[i];
            if(root->childcount==1){
                ans.push_back(ch);
                int index=ch-'a';
                root=root->children[index];
            }
            else break;
            
            if(root->isEnd==true){
                break;
            }
        }
        
        
    }
    
};


string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    Trie *head=new Trie();
    for(int i=0;i<n;i++){
        head->insert(arr[i]);
    }
    
    string ans="";
    head->lcp(ans,arr[0]);
    
    return ans;
 
}
