#include <iostream>
using namespace std;

class node
{

public:
    int data;
    node *next;

    node(int val) // creation a constructor
    {
        data = val;
        next = NULL;
    }
};

void insert(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        n->next = head;
        head = n;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void deleteAtHead(node *&head)
{
    node *todelete = head;
    head = head->next;
    delete todelete;
}

void Delete(node *&head, int val)
{
    if (head == NULL)
        return;
    if (head->next == NULL)
    {
        deleteAtHead(head);
        return;
    }

    node *temp = head;
    while (temp->next->data != val)
    {
        temp = temp->next;
    }
    node *todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

void update(node *head, int oldval, int newval)
{
    node *temp = head;
    while (temp->next->data != oldval)
    {
        temp = temp->next;
    }
    node *toupdate = temp->next;
    temp->next->data = newval;
}

node *reverse(node *head)
{
    node *preptr = NULL;
    node *currptr = head;
    node *nextptr;

    while (currptr != NULL)
    {
        nextptr = currptr->next;
        currptr->next = preptr;
        preptr = currptr;
        currptr = nextptr;
    }
    return preptr;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "-> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main()
{
    node *head = NULL; //Declaring a pointer  variable of node class type
    insert(head, 5);
    insert(head, 6);
    insert(head, 7);
    insert(head, 8);
    insert(head, 9);
    cout << "Printing whole linked list......." << endl;
    display(head);
    Delete(head, 6);
    cout << "Printing linked list after deleting 6 from it......." << endl;
    display(head);
    update(head, 7,22);
    cout << "Printing linked list after updating node containg value 7 with 22......." << endl;
    display(head);
    node *newnode = reverse(head);
    cout << "Printing linked list after reversing it......." << endl;
    display(newnode);
    return 0;
}
