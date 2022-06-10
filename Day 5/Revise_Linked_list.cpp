#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct node
{
    int data;
    node *next;
    node(int key)
    {
        this->data = key;
        this->next = NULL;
    }
};

void displayll(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

void rdisplay(node *head)
{
    if (head == NULL)
    {
        return;
    }
    rdisplay(head->next);
    cout << head->data << " ";
}

void reversell(node *curr, node *prev, node **head)
{
    if (curr == NULL)
    {
        *head = prev;
        return;
    }
    reversell(curr->next, curr, head);
    curr->next = prev;
}

node *reversell(node *head)
{
    node *prev = NULL, *curr = head;
    while (curr != NULL)
    {
        node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

void insert(int val, int index, node *head)
{
    node *temp = new node(val);

    if (index == 1)
    {
        temp->next = head;
        head = temp;
        return;
    }
    else
    {
        node *front = head;
        for (int i = 1; i < index - 1 & front != NULL; i++)
        {
            front = front->next;
        }
        temp->next = front->next;
        front->next = temp;
        return;
    }
}

void delete_key(int index, node *head)
{
    node *temp = head;
    if (index == 1)
    {
        head = head->next;
        free(temp);
    }
    else
    {

        for (int i = 1; i < index - 1; i++)
        {
            temp = temp->next;
        }
        node *front = temp->next;
        temp->next = front->next;
        free(front);
    }
}

bool iscycle(node *head)
{
    node *first = head, *second = head;
    while (second != NULL and second->next != NULL)
    {
        first = first->next;
        second = second->next->next;
        if (first == second)
        {
            return true;
        }
    }
    return false;
}

node *findStartofCycle(node *head)
{
    node *first = head, *second = head;
    while (second != NULL and second->next != NULL)
    {
        first = first->next;
        second = second->next;
        second = second->next;
        if (first == second)
        {
            first = head;
            break;
        }
    }
    while (first != second)
    {
        first = first->next;
        second = second->next;
    }
    return first;
}

void makecycle(node *head)
{
    node *front = head;
    while (front != NULL && front->next != NULL)
    {
        front = front->next;
    }
    front->next = head->next->next;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> arr = {8, 5, 4, 7, 3, 9};

    node *head = new node(arr[0]);
    int i = 1, n = arr.size();
    node *front = head;
    while (i < n)
    {
        node *temp = new node(arr[i++]);
        front->next = temp;
        front = temp;
    }
    // cout<<"Successfull";
    displayll(head);
    cout << endl;
    rdisplay(head);
    cout << endl;
    reversell(head, NULL, &head);
    displayll(head);
    cout << endl;
    head = reversell(head);
    displayll(head);
    cout << endl;
    insert(6, 6, head);
    displayll(head);
    cout << endl;
    delete_key(6, head);
    displayll(head);
    cout << endl;

    makecycle(head);
    cout << iscycle(head) << endl;

    // node *fn = head;
    // int cnt = 0;
    // while (cnt < 12)
    // {
    //     cout << fn->data << " ";
    //     fn = fn->next;
    //     cnt++;
    // }
    // displayll(head);
    // cout << endl;

    node *first_cycle = findStartofCycle(head);
    cout << first_cycle->data << endl;

    return 0;
}
