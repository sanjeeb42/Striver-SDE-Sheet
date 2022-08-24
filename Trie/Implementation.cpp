#include <bits/stdc++.h>
using namespace std;
#define ll long long

class TrieNode
{
public:
    char data;
    TrieNode *child[26];
    bool isEnd;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            child[i] = NULL;
        }
        isEnd = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0');
    }
    void Helperinsert(TrieNode *root, string word)
    {

        if (word.length() == 0)
        {
            root->isEnd = true;
            return;
        }

        int index = word[0] - 'A';
        TrieNode *next;

        if (root->child[index] != NULL)
        {
            next = root->child[index];
        }

        else
        {
            // Create a new Node
            next = new TrieNode(word[0]);
            root->child[index] = next;
        }

        Helperinsert(next, word.substr(1));
    }

    bool Helpersearch(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            if (root->isEnd == true)
            {
                return true;
            }
            else
                return false;
        }

        int index = word[0] - 'A';

        if (root->child[index] == NULL)
            return false;
        else
            return Helpersearch(root->child[index], word.substr(1));
    }

    void Helperremove(TrieNode *root, string word)
    {

        if (root == NULL)
            return;
        if (word.length() == 0)
        {
            root->isEnd = false;
            return;
        }

        int index = word[0] - 'A';

        Helperremove(root->child[index], word.substr(1));
    }

    void insert(string word)
    {
        Helperinsert(root, word);
    }

    bool search(string word)
    {
        return Helpersearch(root, word);
    }

    void remove(string word)
    {
        Helperremove(root, word);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Trie *t = new Trie;
    t->insert("SANJEEB");
    t->insert("TIME");
    cout << "Present or not: " << t->search("SANJEEB") << endl;

    t->remove("SANJEEB");
    cout << "Present or not: " << t->search("SANJEEB") << endl;

    cout << t->search("TIME") << endl;
    cout << t->search("TIM") << endl;

    return 0;
}
