class TrieNode{
    public:
    int val;
    TrieNode* child[10];

    TrieNode(int value){
        this->val=value;
        for(int i=0;i<10;i++){
            child[i]=0;
        }
    }
};

class Trie{
    public:
    TrieNode * root;

    Trie(int val){
        root=new TrieNode(val);
    }

    void insert(int val){
        string s=to_string(val);
        TrieNode* head=root;
        for(int i=0;i<s.length();i++){
            int digit=s[i]-'0';
            if(head->child[digit]==0){
                TrieNode * temp=new TrieNode(digit);
                head->child[digit]=temp;
                head=head->child[digit];
            }
            else head=head->child[digit];
        }
    }

    int search(int val){
        string s=to_string(val);
        int ans=0;
        TrieNode* head=root;
        for(int i=0;i<s.length();i++){
            int digit=s[i]-'0';
            if(head->child[digit]){
                ans++;
                head=head->child[digit];
            }
            else break;
        }
        return ans;
    }
    
};

TrieNode* t-new TrieNode(-1);
t->insert(val);
