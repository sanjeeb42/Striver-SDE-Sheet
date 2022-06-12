bool iscycle(Node *head)
{
    Node *first = head, *second = head;
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

Node *findStartofCycle(Node *head)
{
    Node *first = head, *second = head;
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


Node *firstNode(Node *head)
{
	//    Write your code here.
    Node* ans=NULL;
    if(iscycle(head)){
        ans=findStartofCycle(head);
    }
    return ans;
}


// A Slight Optimization can be merging both function into one 😁🤷‍♂️

Node *firstNode(Node *head)
{
	if (head == NULL)
	{
		// Empty linked list.
		return NULL;
	}

	// Slow Pointer - This will be incremented by 1 Nodes
	Node *slow = head;

	// Fast Pointer - This will be incremented by 2 Nodes
	Node *fast = head;

	do
	{
		if (fast && fast->next)
		{
			fast = fast->next->next;
		}
		else
		{
			// Fast pointer reached the end of the list.
			return NULL;
		}

		slow = slow->next;
	} while (fast != slow);

	slow = head;

	// To track the position of node.
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}
