#include <iostream>
using namespace std;


class Node
{
    public:
    int rowindex;
    int colindex;
    int value;
    Node *next;
};

void newNode(Node **p, int indexofrow,int indexofcolumn, int value){
	Node *temp = *p;
    Node *r;
    if (temp == NULL)
    {
        temp = new Node();
        temp->rowindex = indexofrow;
        temp->colindex = indexofcolumn;
        temp->value = value;
        temp->next = NULL;
        *p = temp;
    }
    
     else
    {
        while (temp->next != NULL)   
            temp = temp->next;
             
        r = new Node();
        r->rowindex = indexofrow;
        r->colindex = indexofcolumn;
        r->value = value;
        r->next = NULL;
        temp->next = r;
    }
}
 
 
void printOutput(Node *start)
{
    Node *ptr = start;
    while (ptr != NULL)
    {
        cout << ptr->rowindex << " ";
        ptr = ptr->next;
    }
    cout << endl;
    ptr = start;
    while (ptr != NULL)
    {
        cout << ptr->colindex << " ";
        ptr = ptr->next;
    }
    cout << endl;
    ptr = start;
     
    while (ptr != NULL)
    {
        cout << ptr->value << " ";
        ptr = ptr->next;
    }
}   
    

int main()
{
    int i = 0;
    int input_matrix[4][5] =
        {
            {0, 0, 3, 0, 4},
            {0, 0, 5, 7, 0},
            {0, 0, 0, 0, 0},
            {0, 2, 6, 0, 0}
        };
Node *initial = NULL;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if (input_matrix[i][j] != 0)
                newNode(&initial, i, j,input_matrix[i][j]);
        }
        
         }
    printOutput(initial);
 
    return 0;
}