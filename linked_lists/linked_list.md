## Linked lists

### What is a linked list?

    It's a secuential structure of nodes that hold a value and a reference(s) to the others nodes who also contain data and a reference


    Node -> Node -> Node -> Node

### Terminology

    Head: The rist Node in a linked list
    Tail: The las node in a linked lists
    Pointer: Reference to antother nodes
    Node: An object containing data and pointes(s)


### Benefits

    The size of the arrays is fixed: So we must know the upper limit on the number of elements in advance. Also, generally, the allocated memory is equal to the upper limit irrespective of the usage. 
    Insertion of a new element / Deletion of a existing element in an array of elements is expensive: The room has to be created for the new elements and to create room existing elements have to be shifted but in Linked list if we have the head node then we can traverse to any node through it and insert new node at the required position.

Since we aren't allocating values together, we can add as many new elements as we need whitout resizing

--Lookup traversing
https://www.geeksforgeeks.org/what-is-linked-list/
