#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

int Hash(int x)
{
    return x%10;
}

void SortedInsert(struct Node **p,int x)
{
    struct Node *q=NULL;
    struct Node *H=*p;
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;
    if(*p==NULL)
    {
        *p=t;
    }
    else
    {
        while(H&&H->data>x)
        {
            q=H;
            H=H->next;
        }
        q->next=t;
        t->next=H;
    }
}

int Search(struct Node *p[],int key)
{
    int index=Hash(key);
    struct Node *t=p[index];
    while(t!=NULL)
    {
        if(t->data==key)
        {
            return 1;
        }
        t=t->next;
    }
    return -1;
}

void Insert(struct Node* p[],int x)
{
    int index=Hash(x);
    SortedInsert(&p[index],x);
}

int main()
{
    cout<<"Enter the number of elements to be entered in the array : "<<endl;
    int n;
    cin>>n;
    cout<<"Enter the elements in the array :" <<endl;
    int A[100];
    struct Node *p[10];
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
        Insert(p,A[i]);
    }
    cout<<"Enter the element to be searched from the Array : "<<endl;
    int key;
    cin>>key;
    int index=Search(p,key);
    if(index==1)
        cout<<"The element "<<key<<" was found in the search "<<endl;
    else
        cout<<"The element "<<key<<" was not found in the search "<<endl;
    return 0;
}
