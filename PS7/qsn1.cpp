#include <iostream>
#include <string>
#include <time.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void insertNodeAtBegining(int aData, Node *&aHead);
void insertNodeAtSpecifiedPosn(int aData, Node *aHead, int posn);
void insertNodeAtEnd(int aData, Node *aHead);
void deleteNodeAtBegining(Node *&aHead);
void deleteNodeAtSpecifiedPosn(Node *aHead, int posn);
void deleteNodeAtEnd(Node *aHead);
void reverseTheLinkedList(Node *&aHead);
void countNodes(int &cnt, Node *aHead);
void merge2LinkedLists(Node *aHd1, Node *aHd2, int cnt1, int cnt2);
void swapNodeData(Node *&node1, Node *&Snode2);
void sortLinkedList(Node *aHd);
void printReverse(Node *&aHead);
void swapNodesWithOutSwappingData(Node *aHd, Node *node1, Node *node2);
void intersectionPt(Node *n1, Node *n2);

Node *getLastNode(Node *aHd);
Node *getANewNode(int aData);
void printNodeData(Node *aHead);

int main()
{
    srand(time(0));
    Node *temp;
    Node *head;
    Node *n[5];
    for (int i = 0; i < 5; i++)
    {
        n[i] = new Node();
    }
    temp = n[0];
    for (int i = 1; i < 5; i++)
    {
        int theData = rand() % 10; // 2 * i;
        insertNodeAtBegining(theData, temp);
    }
    head = temp;
    cout << "\n\nAfter new insert at begining : ";
    printNodeData(head);
    int theData = 105;
    int atPosn = 3;
   // insertNodeAtSpecifiedPosn(theData, head, atPosn);
    //   cout << "\n\nAfter new insert at spcified posn : ";
    //   printNodeData(head);
    theData = 205;
  //  insertNodeAtEnd(theData, head);
    //   cout << "\n\nAfter new insert at end : ";
    //   printNodeData(head);
  //  deleteNodeAtBegining(head);
    //    cout << "\n\nAfter delete node at begining : ";
    //    printNodeData(head);
    atPosn = 2;
  //  deleteNodeAtSpecifiedPosn(head, atPosn);
    //   cout << "\n\nAfter delete node at specified position : ";
    //   printNodeData(head);
  //  deleteNodeAtEnd(head);
    //   cout << "\n\nAfter delete node at end : ";
    //    printNodeData(head);
    Node *head2;
    //    cout << "\n\nReverse print recursive : ";
    //    printReverse(head);
    //    cout << "\n\nAfter Reverse :";
  //  reverseTheLinkedList(head);
    //    printNodeData(head);
    int cntNodes = 0;
    countNodes(cntNodes, head);
    //   cout << "\n\nNo of nodes : " << cntNodes;
    Node *temp2;
    Node *n2[7];
    for (int i = 0; i < 7; i++)
    {
        n2[i] = new Node();
    }
    n2[0]->data = 1;
    temp2 = n2[0];
    for (int i = 1; i < 7; i++)
    {
        int theData = rand() % 10; // 2 * i + 1;
        insertNodeAtBegining(theData, temp2);
    }
    head2 = temp2;
    cout << "\n\nAfter new insert at begining print list 2 : ";
    printNodeData(head2);
    cout <<endl <<endl;
    intersectionPt(head, head2);
    int cntNodes2 = 0;
    countNodes(cntNodes2, head2);
    cout <<endl <<endl;
   // cout << "\n\nNo of nodes list 2 : " << cntNodes2 <<endl;
    merge2LinkedLists(head, head2, cntNodes, cntNodes2);
    cout << "\n\nAfter Merge of the 2 linked lists : ";
    if (cntNodes > cntNodes2)
    {
         printNodeData(head);
        // temp2 = head;
    }
    else
    {
          printNodeData(head2);
          temp2 = head2;
    }

  //  cout << "\n\nAfter sort using swap data :";
  //  sortLinkedList(temp2);
  //  printNodeData(temp2);
   // cout <<"\nhead->data : "<<head->data<<"  head2->data : "<< head2->data << endl;

   

    //  cout << "\n---End Test line ---";
    return 0;
}


void makeALoopChk(Node *n1)
{
    Node *temp = new Node();
    Node *head = new Node();
    head = n1;
    temp = n1;
    if(head == NULL ||head->next == NULL)
    return;
    while(temp->next != NULL)
    {
        
    }


}

void intersectionPt(Node *n1, Node *n2)
{
    Node *temp1 = new Node();
    Node *temp2 = new Node();
    temp1 = n1;
    temp2 = n2;
    int intPt = 0;
    bool intNotFound = true;
    while (temp1 != NULL && temp2 != NULL && intNotFound)
    {
       // cout <<"\ntemp1->data : "<<temp1->data<<"  temp2->data : "<< temp2->data << endl;
        if (temp1->data == temp2->data)
        {
            intNotFound = false;
           // break;
        }
        intPt++;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    if (intNotFound)
    {
        cout << "\nIntersection point NOT found " << endl;
    }
    else
    {
        cout << "\nIntersection point found at : " << intPt;
    }
}

void insertNodeAtBegining(int aData, Node *&aHead)
{
    Node *newNode = getANewNode(aData);
    newNode->next = aHead;
    aHead = newNode;
}

void insertNodeAtSpecifiedPosn(int aData, Node *aHead, int posn)
{
    Node *newNode = getANewNode(aData);
    int count = 1;
    Node *temp = aHead;
    while (count < posn - 1) // to reach last node so one could manipulate or work with last node
    {
        temp = temp->next;
        count++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertNodeAtEnd(int aData, Node *aHead)
{
    Node *newNode = getANewNode(aData);
    Node *temp = aHead;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteNodeAtBegining(Node *&aHead)
{
    aHead = aHead->next;
}

void deleteNodeAtSpecifiedPosn(Node *aHead, int posn)
{
    int count = 2;
    Node *temp = aHead;
    while (count < posn)
    {
        temp = temp->next;
        count++;
    }
    temp->next = temp->next->next;
}

void deleteNodeAtEnd(Node *aHead)
{
    Node *temp = aHead;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}

void reverseTheLinkedList(Node *&aHead)
{
    Node *prev = NULL, *fwd = NULL, *temp = NULL;
    temp = aHead;
    while (temp != NULL)
    {
        fwd = temp->next;
        temp->next = prev;
        prev = temp;
        temp = fwd;
    }
    aHead = prev;
}

void printReverse(Node *&aHead)
{
    if (aHead->next != NULL)
        printReverse(aHead->next);
    cout << " " << aHead->data;
}

void countNodes(int &cnt, Node *aHead)
{
    int count = 0;
    Node *temp = aHead;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    // cout << "\nNo of nodes : "<< count;
    cnt = count;
}

void merge2LinkedLists(Node *aHd1, Node *aHd2, int cnt1, int cnt2)
{
    Node *temp1 = aHd1;
    Node *temp2 = aHd2;
    Node *lastNode1 = new Node();
    Node *lastNode2 = new Node();
    if (cnt1 > cnt2)
    {
        lastNode1 = getLastNode(temp1);
        lastNode1->next = temp2;
    }
    else
    {
        lastNode2 = getLastNode(temp2);
        lastNode2->next = temp1;
    }
}

void sortLinkedList(Node *aHd)
{
    Node *temp1 = aHd;
    Node *temp2 = aHd;
    int count = 0;
    cout << "\n1. Count : " << count;
    while (temp1->next != NULL)
    {
        //  cout << "\n1. temp1->data : "<< temp1->data << endl;
        //   cout << "\n2. temp1->next->data : "<< temp1->next->data << endl;
        temp2 = temp1->next;
        while (temp2 != NULL)
        {
            if (temp1->data > temp2->data)
            {
                //  swapNodeData(temp1, temp2);
                // cout << "\n11. temp1->data : "<< temp1->data << endl;
                //   cout << "\n22. temp2->data : "<< temp2->data << endl;
                swapNodesWithOutSwappingData(aHd, temp1, temp2);
            }
            temp2 = temp2->next;
        }
        count++;
        cout << "\n2. Count : " << count;
        cout << "\n21. temp1->data : " << temp1->data << endl;
        cout << "\n22. temp1->next->data : " << temp1->next->data << endl;
        temp1 = temp1->next;
        cout << "\n33. temp1->data : " << temp1->data << endl;
    }
    cout << "\n3. Count : " << count;
}

void swapNodeData(Node *&node1, Node *&node2)
{
    //   cout <<"  Swapping data :";
    Node *temp = new Node();
    temp->data = node1->data;
    //        cout <<"\nnode1->data : " << node1->data <<" node2->data : " << node2->data ;

    node1->data = node2->data;
    node2->data = temp->data;
    //      cout <<"\nnode1->data : " << node1->data <<" node2->data : " << node2->data ;
}

void swapNodesWithOutSwappingData(Node *aHd, Node *node1, Node *node2)
{
    if (node1->data == node2->data)
        return;
    Node *prev1 = new Node();
    Node *prev2 = new Node();
    Node *temp1 = new Node();
    Node *temp2 = new Node();
    // Search for node1->data1 (keep track of its previous and current)
    temp1 = aHd;
    while (temp1 && temp1->data != node1->data)
    {
        prev1 = temp1;
        temp1 = temp1->next;
    }
    //  cout << "\ntemp1->data : " << temp1->data << endl;

    // Search for node2->data2 (keep track of its previous and current)
    temp2 = aHd;
    while (temp2 && temp2->data != node2->data)
    {
        prev2 = temp2;
        temp2 = temp2->next;
    }
    //   cout << "\ntemp2->data : " << temp2->data << endl;
    // If either node1 or node2 is not present, return
    if (temp1 == NULL || temp2 == NULL)
        return;

    // swap the prev pointers
    //  If node1 is not the head of the linked list
    if (prev1 != NULL)
        prev1->next = temp2;
    //  else
    //    aHd = temp2; // make temp2 the new head

    // If node2 is not the head of the linked list
    if (prev2 != NULL)
        prev2->next = temp1;
    //  else
    //      aHd = temp1; // make temp1 the new head

    // Swap the node->next pointers of node1 and node2
    cout << "\n1. temp2->data : " << temp2->data << "  temp1->data : " << temp1->data << endl;
    Node *temp = new Node();
    temp->next = temp2->next;
    //  cout <<"\nTemp->data : "<< temp->data;
    temp2->next = temp1->next;
    temp1->next = temp->next;
    //   cout << "\nSwap here 2";
    cout << "\n2. temp2->data : " << temp2->data << "  temp1->data : " << temp1->data << endl;
    cout << "\n3. temp2->next->data : " << temp2->next->data << "  temp1->next->data : " << temp1->next->data << endl
         << endl;
}

/* ***** DO NOT DELETE *****

while (temp != NULL)//to print all node contents
    {
        cout << "\n Data : " << temp->data;// prints 3, 5
        temp = temp->next;
    }
    temp = head;
    cout << endl;
    while (temp->next != NULL)//to reach last node so one could manipulate or work with last node
    {
        cout << "\n Data : " << temp->data;// prints only 3
        temp = temp->next;
    }
    ***** DO NOT DELETE *****
*/
Node *getLastNode(Node *aHd)
{
    Node *temp = aHd;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    return temp;
}

void printNodeData(Node *aHead)
{
    Node *temp = aHead;
    while (temp != NULL)
    {
        cout << " " << temp->data;
        temp = temp->next;
    }
}

Node *getANewNode(int aData)
{
    int theData = aData;
    Node *newNode = new Node();
    newNode->data = theData;
    newNode->next = NULL;
    return newNode;
}
