#include<iostream>
using namespace std;

template <class T>
struct nodeSL
{
    T data;
    struct nodeSL *next;
};

template <class T>
struct nodeDL
{
    T data;
    struct nodeDL *next;
    struct nodeDL *prev;
};

template <class T>
struct nodeSCL
{
    int data;
    struct nodeSCL *next;
};

template <class T>
struct nodeDCL
{
    int data;
    struct nodeDCL *next;
    struct nodeDCL *prev;
};

template <class T>
struct nodeQ
{
    int data;
    struct nodeQ *next;
};

template <class T>
struct nodeS
{
    T data;
    struct nodeS *next;
};

template <class T>
class SinglyLLG
{
    public :
        struct nodeSL<T> * head;
        int iCount;        

    SinglyLLG();
    void InsertFirst(T No);
    void InsertLast(T No);
    void DeleteFirst();
    void DeleteLast();
    void Display();
    int Count();
    void InsertAtPos(T No, int iPos);
    void DeleteAtPos(int iPos);
};

template <class T>
SinglyLLG<T> :: SinglyLLG()
{
    head = NULL;
    iCount = 0;
}

template <class T>
void SinglyLLG<T> :: InsertFirst(T No)
    {
        struct nodeSL<T> * newn = NULL;

        newn = new nodeSL<T>;
        newn->data = No;
        newn->next = NULL;
        
        if(head == NULL)
        {
            head = newn;
        }
        else
        {
            newn->next = head;
            head = newn;
        }
        iCount++;
    }

template <class T>
void SinglyLLG<T> :: InsertLast(T No)
    {
        struct nodeSL<T> * newn = NULL;
        struct nodeSL<T> * temp = NULL;

        newn = new nodeSL<T>;

        newn->data = No;
        newn->next = NULL;
        
        if(head == NULL)
        {
            head = newn;
        }
        else
        {
            temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newn;
            newn->next = NULL;
        }

        iCount++;
    }

template <class T>
void SinglyLLG<T> :: DeleteFirst()
    {
        struct nodeSL<T> * temp = NULL;

        if(head == NULL)
        {
            cout<<"LinkedList is Empty"<<'\n';
            return;
        }
        else
        if(head->next == NULL)
        {
            delete (head);
            head = NULL;
        }
        else
        {
            temp = head;

            head = head->next;
            delete(temp);
        }  
        iCount--;      
    }

template <class T>
void SinglyLLG<T> :: DeleteLast()
    {
        struct nodeSL<T> * temp = NULL;

        if(head == NULL)
        {
            cout<<"LinkedList is Empty"<<'\n';
            return;
        }
        else
        if(head->next == NULL)
        {
            delete (head);
            head = NULL;
        }
        else
        {
            temp = head;

            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }

            delete(temp->next);
            temp->next = NULL;
        }  
        iCount--; 
    }

template <class T>
void SinglyLLG<T> :: Display()
    {
        struct nodeSL<T> * temp = head;

        cout<<"Elements in the LinkedList is \n";

        while(temp != NULL)
        {
            cout<<"| "<<temp->data<<" ->";
            temp = temp->next;
        }
        cout<<"NULL\n";
        
    }

template <class T>
int SinglyLLG<T> :: Count()
    {
        return iCount;
    }

template <class T>
void SinglyLLG<T> :: InsertAtPos(T No, int iPos)
    {
        struct nodeSL<T> * newn = NULL;
        struct nodeSL<T> * temp = NULL;

        int i = 0;
        int CountNode = 0;

        CountNode = Count();

        if((iPos < 1) || (iPos > CountNode+1))
        {
            cout<<"Invalid Positon"<<"\n";
            return;
        }
        if(iPos == 1)
        {
            InsertFirst(No);
        }
        else
        if(iPos == CountNode + 1)
        {
            InsertLast(No);
        }
        else
        {
            newn = new nodeSL<T>;

            newn->data = No;
            newn->next = NULL;

            temp = head;

            for(i = 1; i < iPos - 1; i++)
            {
                temp = temp->next;
            }

            newn->next = temp->next;
            temp->next = newn;

            iCount++;
        }
    }

template <class T>
void SinglyLLG<T> :: DeleteAtPos(int iPos)
    {
        struct nodeSL<T> * temp = NULL;
        struct nodeSL<T> * target = NULL;

        int i = 0;
        int CountNode = 0;

        CountNode = Count();


        if((iPos < 1) || (iPos > CountNode))
        {
            cout<<"Invalid Positon"<<"\n";
            return;
        }
        if(iPos == 1)
        {
            DeleteFirst();
        }
        else
        if(iPos == CountNode + 1)
        {
            DeleteLast();
        }
        else
        {
            temp = head;

            for(i = 1; i < iPos - 1; i++)
            {
                temp = temp->next;
            }

            target = temp->next;

            temp->next = target->next;
            delete(target);

            iCount--;
        }
    }

template <class T>
class DoubllyLLG
{
    public:
        struct nodeDL<T> * head;
        int iCount;

    DoubllyLLG();
    void InsertFirst(T No);
    void InsertLast(T No);
    void DeleteFirst();
    void DeleteLast();
    void Display();
    int Count();
    void InsertAtPos(T No, int iPos);
    void DeleteAtPos(int iPos);
};

template <class T>
DoubllyLLG<T> :: DoubllyLLG()
{
    head = NULL;
    iCount = 0;
}

template <class T>
void DoubllyLLG<T> :: InsertFirst(T No)
{
    struct nodeDL<T> * newn = NULL;

    newn = new nodeDL<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(head == NULL)
    {
        head = newn;
    }
    else
    {
        newn->next = head;
        head->prev = newn;

        head = newn;
    }

    iCount++;

}

template <class T>
void DoubllyLLG<T> :: InsertLast(T No)
{
    struct nodeDL<T> * newn = NULL;
    struct nodeDL<T> * temp = NULL;

    int i = 0;

    newn = new nodeDL<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(head == NULL)
    {
        newn = head;
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }

    iCount++;
}

template <class T>
void DoubllyLLG<T> :: DeleteFirst()
{
    struct nodeDL<T> * temp = NULL;

    if(head == NULL)
    {
        return;
    }
    else
    if(head->next == NULL)
    {
        delete head;
        head = NULL;
    }
    else
    {
        head = head->next;
        delete (head->prev);
        head->prev = NULL;
    }
    iCount--;
}

template <class T>
void DoubllyLLG<T> :: DeleteLast()
{
    struct nodeDL<T> * temp = NULL;

    if(head == NULL)
    {
        return;
    }
    else
    if(head->next == NULL)
    {
        delete head;
        head = NULL;
    }
    else
    {
        temp = head;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete (temp->next);
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void DoubllyLLG<T> :: Display()
{
    struct nodeDL<T> * temp = head;

    cout<<"Elements of linkelist are : \n";

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<"| <=> ";
        temp = temp -> next;
    }

    cout<<"NULL\n";
}

template <class T>
int DoubllyLLG<T> :: Count()
{
    return iCount;
}

template <class T>
void DoubllyLLG<T> :: InsertAtPos(T No, int iPos)
{
    struct nodeDL<T> * newn = NULL;
    struct nodeDL<T> * temp = NULL;

    int i = 0;
    int CountNode = 0;

    CountNode = Count();

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else
    if(iPos == CountNode + 1)
    {
        InsertLast(No);
    }
    else
    {
        temp = head;

        newn = new nodeDL<T>;

        newn->data = No;
        newn->next = NULL;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        newn->prev = temp;
        temp->next->prev = newn;

        iCount++;
    }
}

template <class T>
void DoubllyLLG<T> :: DeleteAtPos(int iPos)
{
    struct nodeDL<T> * temp = NULL;
    struct nodeDL<T> * targert = NULL;

    int i = 0;
    int CountNode = 0;

    CountNode = Count();

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else
    if(iPos == CountNode + 1)
    {
        DeleteLast();
    }
    else
    {
        temp = head;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        
        targert = temp->next;

        temp->next = targert->next;
        targert->next->prev = temp;

        delete targert;

        iCount--;
    }
}

template <class T>
class SinglyCL
{
    public :
        struct nodeSCL<T> * head; 
        struct nodeSCL<T> * tail;
        int iCount;

    SinglyCL();
    void InsertFirst(T No);
    void InsertLast(T No);
    void DeleteFirst();
    void DeleteLast();
    void Display();
    int Count();
    void InsertAtPos(T No, int iPos);
    void DeleteAtPos(int iPos);

};

template <class T>
SinglyCL<T> :: SinglyCL()
{
    head = NULL;
    tail = NULL;
}

template <class T>
void SinglyCL<T> :: InsertFirst(T No)
{
    struct nodeSCL<T> * newn = NULL;

    newn = new nodeSCL<T>;

    newn->data = No;
    newn->next = NULL;

    if((head == NULL) && (tail == NULL))
    {
        head = newn;
        tail = newn;
    }
    else
    {
        newn->next = head;
        head = newn;  
    }

    tail->next = head;
    
}

template <class T>
void SinglyCL<T> :: InsertLast(T No)
{
    struct nodeSCL<T> * newn = NULL;

    newn = new  nodeSCL<T>;

    newn->data = No;
    newn->next = NULL;

    if((head == NULL) && (tail == NULL))
    {
        head = newn;
        tail = newn;
    }
    else
    {
        tail->next = newn;
        newn->next = head;

        tail = newn;
    }

    tail->next = head;
    
}

template <class T>
void SinglyCL<T> :: DeleteFirst()
{
    if((head == NULL) && (tail == NULL))
    {
        return;
    }
    else
    {
        head = head->next;
        delete(tail->next);
    }

    tail->next = head;
}

template <class T>
void SinglyCL<T> :: DeleteLast()
{
    struct nodeSCL<T> * temp = NULL;

    if((head == NULL) && (tail == NULL))
    {
        return;
    }
    else
    if(head == tail)
    {
        delete head;
        head = NULL;
        tail = NULL;
    }
    else
    {
        temp = head;

        while (temp->next != tail)
        {
            temp = temp->next;
        }

        delete(temp->next);
        tail = temp;
        tail->next = head;
    }
}

template <class T>
void SinglyCL<T> :: Display()
{
    if((head == NULL) && (tail == NULL))
    {
        return;
    }
    do
    {
        cout<<"| "<<head->data<<"| <=> ";
        head = head->next;            
    }while (head != tail->next);

    cout<<"\n";
}

template <class T>
int SinglyCL<T> :: Count()
{
    int iCount = 0;

    if((head == NULL) && (tail == NULL))
    {
        return 0;
    }

    do
    {
        iCount++;
        head = head->next;
    }while(head != tail->next);

    cout<<"\n";
    return iCount;
}

template <class T>
void SinglyCL<T> :: InsertAtPos(T No, int iPos)
{
    int i = 0;
    int iCount = Count();

    struct nodeSCL<T> * temp = NULL;
    struct nodeSCL<T> * newn = NULL;

    if((iPos < 1) || (iPos > iCount + 1))
    {
        cout<<"Invalid Postion"<<"\n";
        return;
    }
    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else
    if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        newn = new  nodeSCL<T>;

        newn->data = No;
        newn->next = NULL;

        temp = head;

        for(i = 1; i < iPos-1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
        
}

template <class T>
void SinglyCL<T> :: DeleteAtPos(int iPos)
{
    int i = 0;
    int iCount = 0;

    iCount = Count();

    struct nodeSCL<T> * temp = NULL;
    struct nodeSCL<T> * target = NULL;

    if((iPos < 1) || (iPos > iCount + 1))
    {
        cout<<"Invalid Postion"<<"\n";
        return;
    }
    if(iPos == 1)
    {
        DeleteFirst();
    }
    else
    if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = head;

        for(i = 1; i < iPos-1; i++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;
        delete(target);
    }         
}

template <class T>
class DoubllyCLG                                               
{
    public :
        struct nodeDCL<T> * head; 
        struct nodeDCL<T> * tail;
        
    DoubllyCLG();                                            
    void InsertFirst(T No);                                 
    void InsertLast(T No);                               
    void DeleteFirst();                                      
    void DeleteLast();                                       
    void Display();                                       
    int Count();                                             
    void InsertAtPos(T No, int iPos);                         
    void DeleteAtPos(int iPos);                                     
};

template <class T>
DoubllyCLG<T> :: DoubllyCLG()                                            // Constructor
{
    head = NULL;
    tail = NULL;            
}

template <class T>
void DoubllyCLG<T> :: InsertFirst(T No)                                 // Insert at first postion 
{
    struct nodeDCL<T> * newn = NULL;

    newn = new nodeDCL<T>;
    
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((head == NULL) && (tail == NULL))
    {
        head = newn;
        tail = newn;
    }
    else
    {
        newn->next = head;
        head->prev = newn;

        head = newn;
    }
    tail->next = head;
    head->prev = tail;
}

template <class T>
void DoubllyCLG<T> :: InsertLast(T No)                                // Insert at last postion 
{
    struct nodeDCL<T> * newn = NULL;

    newn = new nodeDCL<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(head == NULL)
    {
        head = newn;
        tail = newn;
    }
    else
    {
        tail->next = newn;
        newn->prev = tail;

        tail = newn;
    }
    tail->next = head;
    head->prev = tail;        
}  

template <class T>
void DoubllyCLG<T> :: DeleteFirst()                                     // Delete at first postion 
{
    if((head == NULL) && (tail == NULL))
    {
        return;
    }
    else
    {
        head = head->next;
        delete(tail->next);
    }
    tail->next = head;
    head->prev = tail;
}

template <class T>
void DoubllyCLG<T> :: DeleteLast()                                       // Delete at last postion 
{
    if((head == NULL) && (tail == NULL))
    {
        return;
    }
    else
    if(head == tail)
    {
        delete(head);
        head = NULL;
        tail = NULL;
    }
    else
    {
        tail = tail->prev;
        delete(tail->next);

        tail->next = head;
        head->prev = tail;
    }
}

template <class T>
void DoubllyCLG<T> :: Display()                                         // For Display linkedlist
{
    if((head == NULL) && (tail == NULL))
    {
        cout<<"LinkedList is empty"<<"\n";
        return;
    }

    do
    {
        cout<<"| "<<head->data<<"| <=> ";
        head = head->next;
    }while (head != tail->next);
    
    cout<<"\n";
}

template <class T>
int DoubllyCLG<T> :: Count()                                             // Count Elements in Linkedlist
{
    int iCount = 0;

    if((head == NULL) && (tail == NULL))
    {
        return 0;
    }

    do
    {
        iCount++;
        head = head->next;
    }while(head != tail->next);

    cout<<"\n";
    return iCount;
}

template <class T>
void DoubllyCLG<T> :: InsertAtPos(T No, int iPos)                        // // Insert at any postion 
{
    int i = 0;
    int iCount = 0;

    struct nodeDCL<T> * newn = NULL;
    struct nodeDCL<T> * temp = NULL;

    iCount = Count();

    if((iPos < 1) || (iPos > iCount + 1))
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }
    else
    {
        if(iPos == 1)
        {
            InsertFirst(No);
        }
        else
        if(iPos == iCount+1)
        {
            InsertLast(No);
        }
        else
        {
            newn = new nodeDCL<T>;

            newn->data = No;
            newn->next = NULL;
            newn->prev = NULL;

            temp = head;
            for(i = 1; i < iPos - 1; i++)
            {
                temp = temp->next;
            }

            newn->next = temp->next;
            temp->next->prev = newn;

            temp->next = newn;
            newn->prev = temp;
        }
    }
}

template <class T>
void DoubllyCLG<T> :: DeleteAtPos(int iPos)                                       // delete at any postion 
{
    int i = 0;
    int iCount = 0;

    struct nodeDCL<T> * temp = NULL;

    iCount = Count();

    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }
    else
    {
        if(iPos == 1)
        {
            DeleteFirst();
        }
        else
        if(iPos == iCount+1)
        {
            DeleteLast();
        }
        else
        {
            temp = head;

            for(i = 1; i < iPos - 1; i++)
            {
                temp = temp->next;
            }

            temp->next = temp->next->next;
            delete(temp->next->prev);
            temp->next->prev = temp;
        }
    }
}

template <class T>
class QueueG
{
    public:
        struct nodeQ<T> * head;
        int iCount;

        QueueG();
        void enqueue(T no);
        int dequeue();
        void Disply();
        int Count();
};

template <class T>
QueueG<T> :: QueueG()
{
    head = NULL;
    iCount = 0;
}

template <class T>
void QueueG<T> :: enqueue(T no)   // InsertLast
{
    struct nodeQ<T> * newn = NULL;
    struct nodeQ<T> * temp = NULL;

    newn = new nodeQ<T>;
    newn->data = no;
    newn->next = NULL;

    if(head == NULL)
    {
        head = newn;
    }
    else
    {
        temp = head;
        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp->next = newn;
    }
    iCount++;
}

template <class T>
int QueueG<T> :: dequeue()   // DeleteFirst
{
    int no = -1;
    struct nodeQ<T> * temp = NULL;

    if(head == NULL)
    {
        cout<<"Queue is empty\n";
        return -1;
    }
    else if(head->next == NULL)
    {
        no = head->data;
        delete head;
        head = NULL;
    }
    else
    {
        no = head->data;
        temp = head;
        head = head->next;
        delete temp;
    }
    iCount--;
    return no;
}

template <class T>
void QueueG<T> :: Disply()
{
    cout<<"Elements of queue are : \n";
    struct nodeQ<T> * temp = head;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |\n";
        temp = temp -> next;
    }
}

template <class T>
int QueueG<T> :: Count()
{
    return iCount;
}

template <class T>
class StackG
{
    public:
        struct nodeS<T> * head;
        int iCount;

        StackG();
        void push(T no);
        T pop();
        void Disply();
        int Count();

};

template <class T>
StackG<T> :: StackG()
{
    head = NULL;
    iCount = 0;
}

template <class T>
void StackG<T> :: push(T no)   // InsertFirst
{
    struct nodeS<T> * newn = NULL;
    
    newn = new nodeS<T>;
    newn->data = no;
    newn->next = NULL;

    if(head == NULL)
    {
        head = newn;
    }
    else
    {
        newn->next = head;
        head = newn;
    }
    iCount++;
}

template <class T>
T StackG<T> :: pop()   // DeleteFirst
{
    int no = -1;                                                     // other Data type hit change
    struct nodeS<T> * temp = NULL;

    if(head == NULL)
    {
        cout<<"Stack is empty\n";
        return -1;                                                   // other Data type hit change
    }
    else if(head->next == NULL)
    {
        no = head->data;
        delete head;
        head = NULL;
    }
    else
    {
        no = head->data;
        temp = head;
        head = head->next;
        delete temp;
    }
    iCount--;
    return no;
}

template <class T>
void StackG<T> :: Disply()
{
    cout<<"Elements of stack are : \n";
    struct nodeS<T> * temp = head;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |\n";
        temp = temp -> next;
    }
}

template <class T>
int StackG<T> :: Count()
{
    return iCount;
}

int main()
{
    SinglyLLG <int> sllsobj;
    DoubllyLLG <int> dllobj;
    SinglyCL <int> sclsobj;
    DoubllyCLG <int> dclobj;
    QueueG <int> qobj;
    StackG <int> stobj;

    int iRet = 0;

    return 0;
}
