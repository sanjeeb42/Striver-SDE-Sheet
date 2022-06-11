bool detectCycle(Node *head)
{
	//	Write your code here
    
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
