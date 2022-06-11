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


//BruteForce

// Outer And Inner Loop
// We are going to have two loops outer-loop and inner-loop 

// Maintain a count of the number of nodes visited in outer-loop.
// For every node of the outer-loop, start the inner loop from head.
// If the inner-loop visits the node next to the outer-loop node, then return true, else repeat the process for the next iteration of outer-loop.
// If outer-loop reaches the end of list or null, then return false.


bool detectCycle(Node *head)
{
    int numberOfNodesPassed = 0;
    Node *outerLoopNode = head;

    // Iterating over the linked-list.
    while (outerLoopNode != NULL)
    {
        numberOfNodesPassed++;
        outerLoopNode = outerLoopNode->next;
        Node *innerLoopNode = head;
        int counterForInnerLoop = numberOfNodesPassed;

        // Iterating again from the begining.
        while (counterForInnerLoop--)
        {
            //  We found a repetitive Node/ Cycle.
            if (innerLoopNode == outerLoopNode)
            {
                return true;
            }
            innerLoopNode = innerLoopNode->next;
        }
    }

    //  We didn't found any Cycle.
    return false;
}




// naive using hashset



bool detectCycle(Node *head)
{
    // Set to store the visited nodes.
    unordered_set<Node *> nodesSeen;
    
    while (head != NULL)
    {
        if (nodesSeen.find(head)!=nodesSeen.end())
        {
            //  We reached some earlier node again thus we found a cycle.
            return true;
        }
        else
        {
            //  Add the node to hastset of already seen nodes.
            nodesSeen.insert(head);
        }
        head = head->next;
    }

    //  We didn't found any Cycle.
    return false;
}
