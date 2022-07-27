#include<bits/stdc++.h>
class LRUCache
{
public:
    class Node{
        public:
        int key, value;
        Node *next, *prev;
        Node(int _key, int _value){
            key = _key;
            value = _value;
            next = prev = NULL;
        }
    };
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    int cap;
    unordered_map<int, Node*> m;
    
    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addNode(Node *newNode){
        Node *temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }
    void deleteNode(Node *delNode){
        Node *delprev = delNode->prev;
        Node *delnext = delNode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    int get(int key)
    {
       if(m.find(key) != m.end()){
           Node *resNode = m[key];
           int res = resNode->value;
           m.erase(key);
           deleteNode(resNode);
           addNode(resNode);
           m[key] = head->next;
           return res;
       }
        return -1;
    }

    void put(int key, int value)
    {
        if(m.find(key) != m.end()){
            Node *existingNode = m[key];
            m.erase(existingNode->key);
            deleteNode(existingNode);
        }
        if(m.size() == cap){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key, value));
        m[key] = head->next;
    }
};
