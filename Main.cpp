#include<iostream>
using namespace std;



///////////////////////////////////////////////////////////////////////////////
//
//    Class Name : Singly Linear Linked-List
//    Struct Name : node
//    Contains Function like :
//                               Count();
//                               InsertFirst(T);
//                               InsertLast(T);
//                               InsertatPos(int , T );
//                               DeleteFirst();   
//                               DeleteLast();   
//                               Display();    
//                               DeleteatPos(int );
//
/////////////////////////////////////////////////////////////////////////////////



template <class T>
 struct node
{
    T data;
    struct node * next;
};



template<class T>
class SinglyLL
{
private:
    struct node <T> *Head ;
    int iSize ;

public:
    SinglyLL();               //Default Constructor
    int Count();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertatPos(int , T );
    void DeleteFirst();
    void DeleteLast();
    void Display();
    void DeleteatPos(int );
    
};

    //constructor function for singly Linear LL
    template<class T>
    SinglyLL<T> :: SinglyLL()               //Default Constructor
    {
        Head = NULL;
        iSize = 0;
    }

    //count function for Singly linear LL
    template<class T>
    int SinglyLL<T> :: Count()
    {
        return iSize;
    }

    // InsertFirst function for SinglyLL
    template<class T>
    void SinglyLL<T> :: InsertFirst(T iValue)
    {
        struct node <T> *newn = NULL;
        newn = new struct node<T>;   // Same as newn = (struct node *)malloc(sizeof(node)); in C language
        newn->data = iValue;
        newn->next = NULL;
        if(Head==NULL)   //LL is empty
        {
            Head = newn;
        }
        else
        {   //LL consist atleast one node
            newn->next=Head;
            Head=newn;
        }
        iSize++;
    }

//  InsertLast function for Singly LL
    template<class T>
    void SinglyLL<T> :: InsertLast(T iValue)
    {
        struct node <T> *newn = NULL;
        newn = new struct node<T>;   // Same as newn = (struct node *)malloc(sizeof(node)); in C language
        newn->data = iValue;
        newn->next = NULL;


        if(Head==NULL)   //LL is empty
        {
            Head = newn;
        }
        else
        {   
            struct node<T> * Temp = Head;
            while(Temp->next!=NULL)
            {
                Temp = Temp->next;                     
            }
            Temp->next = newn;
        }
        iSize++;
    }

    template<class T>
    void SinglyLL<T> :: InsertatPos(int iPos, T iValue)
    {
        if(iPos<1 || iPos >iSize+1)   //LL is empty
        {
            return;
        }
        else if( iPos == 1)
        {
            InsertFirst(iValue);
        }
        else if( iPos == iSize+1)
        {
            InsertLast(iValue);
        }
        else
        {   
        struct node <T> *newn = NULL;
        newn = new struct node<T>;   // Same as newn = (struct node *)malloc(sizeof(node)); in C language
        newn->data = iValue;
        newn->next = NULL;

        struct node<T> * Temp = Head;

            for(int i=1;i<iPos-1;i++)
            {
                Temp = Temp->next;                     
            }
            newn->next = Temp->next;
            Temp->next = newn;
        }
        iSize++;
    }

    template <class T>
    void SinglyLL<T> :: DeleteFirst()
    {
        
        if(Head==NULL)   //LL is empty
        {
           return;
        }
        else
        {   
            struct node<T> * temp = Head;
            Head = Head->next;
            delete temp;    // same as free(temp) in c 
            iSize--;
         }

        // or we can write it as 
        // if(Head==NULL)   //LL is empty
        // { 
        //     struct node<T> * temp = Head;
        //     Head = Head->next;
        //     delete temp;    // same as free(temp) in c 
        //     iSize--;
        //  }
       
    }

    template <class T>
     void SinglyLL<T> :: DeleteLast()
    {
        
        if(Head==NULL)   //LL is empty
        {
           return;
        }
        else if(Head->next == NULL)
        {
            delete Head;
            Head = NULL;
            iSize --;
        }
        else{
            struct node<T> * Temp = Head;

            while(Temp->next->next != NULL)
            {
                Temp = Temp->next;
            }

             delete Temp->next;
             Temp->next = NULL;
             iSize--;
        }  
    }

    template <class T>
    void SinglyLL<T> :: Display()
    {
        struct node<T> * temp = Head;
        while(temp!=NULL)
        {
            cout<<"|"<<temp->data<<"| -> ";
            temp=temp->next;
        }
        cout<<"\n";
    }

     template <class T>
     void SinglyLL<T> :: DeleteatPos(int iPos)
    {
        
        if((iPos<1) || (iPos > iSize))
        {
            return;
        }
        else if( iPos == 1 )
        {
            DeleteFirst();
        }
        else if( iPos == iSize)
        {
            DeleteLast();
        }
        else{
            struct node<T> * Temp = Head;
            struct node<T> * Target = NULL;
            for(int i=1 ; i<iPos-1 ; i++)
            {
                Temp = Temp->next;
            }
            Target = Temp->next;
            Temp->next = Temp->next->next;
            delete Target;
            iSize--;
        }
    }






///////////////////////////////////////////////////////////////////////////////
//
//    Class Name : Doubly Linear Linked-List
//    Struct Name : nodeD
//    Contains Function like :
//                               Count();
//                               InsertFirst(T);
//                               InsertLast(T);
//                               InsertatPos(int , T );
//                               DeleteFirst();   
//                               DeleteLast();   
//                               Display();    
//                               DeleteatPos(int );
//
/////////////////////////////////////////////////////////////////////////////////





template <class T>
struct nodeD
{
    T data;
    struct nodeD *next;
    struct nodeD *prev;              // +
};



template <class T>
class DoublyLL
{
    private:
        struct nodeD<T> *Head;
        int iSize = 0;
    public: 
        DoublyLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        void Display();
        int Count();



};
        template <class T> 
        DoublyLL <T>:: DoublyLL()
        {
            Head = NULL;
            iSize = 0;
        }

        template <class T> 
        void DoublyLL<T> :: InsertFirst(T iNo)
        {
            struct nodeD<T> *newn = new struct nodeD<T>;
            newn->data = iNo;
            newn->next = NULL;
            newn->prev = NULL;
            
            if(iSize == 0)
            {
                Head = newn;
            }
            else
            {
                newn->next = Head;
                Head->prev = newn;
                Head=newn;
                
            }
            iSize++;
        }

        template <class T> 
        void DoublyLL<T> :: InsertLast(T iNo)
        {
            struct nodeD<T> *newn = new struct nodeD<T>;
            newn->data = iNo;
            newn->next = NULL;
            newn->prev = NULL;
        
            if(iSize == 0)   // Linked list is empty
            {
                Head = newn;
            }
            else                        // Linked list contains atleast one node
            {
                struct nodeD<T> *temp = Head;
                while(temp->next != NULL)
                {
                    temp = temp ->next;
                }
                temp->next = newn;
                newn -> prev = temp;
            }
            iSize++;
        }

        template <class T> 
        void DoublyLL<T> :: InsertAtPos(T iNo,int iPos)
        {
            if(iPos < 1 || iPos >iSize+1)
            {
                return;
            }
            else if(iPos == 1)
            {
                InsertFirst(iNo);
            }   
            else if(iPos == iSize+1)
            {
                InsertLast(iNo);
            }
            else
            {
                struct nodeD<T> *newn = new struct nodeD<T>;
                newn->data=iNo;
                newn->next = NULL;
                newn->prev = NULL;
                struct nodeD<T> *temp = Head;
                for(int i=1;i<iPos-1;i++)
                {
                    temp=temp->next;
                }
                newn->next = temp->next;
                temp->next->prev = newn;
                temp->next = newn;
                newn->prev = temp;

                iSize++;
            }
        }

        template <class T> 
        void DoublyLL<T> :: DeleteFirst()
        {
            if(iSize == 0)
            {
                return;
            }
            else if(iSize == 1)
            {
                delete Head;
                Head = NULL;
                iSize = 0;
            }
            else
            {
                Head = Head ->next;
                delete(Head->prev); // delete(Head->prev);
                Head->prev = NULL;
                iSize--;
            }
        }

        template <class T> 
        void DoublyLL<T> :: DeleteLast()
        {
            if(iSize == 0 || Head == NULL)
            {   
                return;
            }   
            else if(Head->next == NULL)
            {
                delete Head;
                Head = NULL;
                iSize--;
            }
            else
            {
                struct nodeD<T> *temp = Head;
                while(temp->next->next!=NULL)
                {
                    temp = temp->next;
                }
                delete temp->next;
                temp->next=NULL;
                iSize--;
            }
        }

        template <class T> 
        void DoublyLL<T> :: DeleteAtPos(int iPos)
        {
            if((iPos < 1) || (iPos > iSize))
            {
                return;
            }
            if(iPos == 1)
            {
                DeleteFirst();
            }
            else if(iPos == iSize)
            {
                DeleteLast();
            }
            else
            {
                struct nodeD<T> *temp = Head;
                for(int i = 1; i < iPos-1; i++)
                {
                    temp = temp->next;
                }
                temp->next = temp->next->next;
                delete(temp->next->prev);
                temp->next->prev = temp;
                iSize--;
            }
        }

        template <class T> 
        void DoublyLL<T> :: Display()
        {
            struct nodeD<T> *temp = Head;
            while(temp!=NULL)
            {
                cout<<temp->data<<"\t";
                temp = temp->next;
            }
            cout<<"\n";
        }

        template <class T> 
        int DoublyLL<T> :: Count()
        {
            return iSize;
        }





///////////////////////////////////////////////////////////////////////////////
//
//    Class Name : Singly Circular Linked-List
//    Struct Name : nodeSCL
//    Contains Function like :
//                               Count();
//                               InsertFirst(T);
//                               InsertLast(T);
//                               InsertatPos(int,T);
//                               DeleteFirst();   
//                               DeleteLast();   
//                               Display();    
//                               DeleteatPos(int );
//
/////////////////////////////////////////////////////////////////////////////////




template <class T>
struct nodeSCL{
    int data;
    struct nodeSCL *next;
};


template<class T>
class SinglyCL
{
    private:
        struct nodeSCL<T> * Head;
        struct nodeSCL<T> * Tail;
        int iSize;
    public:
        SinglyCL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertatPos(T,int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteatPos(int);
        int Count();
        void Display();
        
};

        template<class T>
        SinglyCL<T> :: SinglyCL()
        {
            Head = NULL;
            Tail = NULL;
            iSize = 0;
        }
    
        template<class T>
        void SinglyCL<T> :: InsertFirst(T iNo)
        {
            struct nodeSCL<T> * newn = NULL;
            newn = new struct nodeSCL<T>;
            newn->next = NULL;
            newn->data = iNo;
            
            if(iSize == 0)
            {
                Head = newn;
                Tail = newn;
            }
            else
            {
                newn->next = Head;
                Head = newn;
            }    
            iSize++;
            Tail->next = Head; 
        }

        template<class T>
        void SinglyCL<T> :: InsertLast(T iNo)
        {
            struct nodeSCL<T> * newn ;
            newn = new struct nodeSCL<T>;
            newn->next = NULL;
            newn->data = iNo;
            
            if(iSize == 0)
            {
                Head = newn;
                Tail = newn;
            }
            else
            {
                Tail->next = newn;
                Tail = Tail->next;
            }    
            iSize++;
            Tail->next = Head; 
        }

        template<class T>
        void SinglyCL<T> :: InsertatPos(T iVal,int iPos)
        {

            if((iPos < 1) && (iPos >iSize+1))
            {
                return;
            }
            if(iPos == 1)
            {
                InsertFirst(iVal);
            }
            else if(iPos == iSize+1)
            {
                InsertLast(iVal);
            }
            else
            {
                struct nodeSCL<T> * newn = Head;
                newn = new struct nodeSCL<T>;
                newn->next = NULL;
                newn->data = iVal;
                struct nodeSCL<T> * Temp = Head;
                for(int i=1 ; i<iPos-1 ; i++)
                {
                    Temp = Temp->next;
                }
                newn->next = Temp->next;
                Temp->next = newn;
                iSize++;

            }    
        }

        template<class T>
        void SinglyCL<T> :: DeleteFirst()
        {        
            if(iSize == 0)
            {
                return;
            }
            else if(iSize == 1)
            {
                delete Head;
                Head = NULL;
                Tail = NULL;
                iSize = 0;
            }
            else
            {
                Head = Head->next;
                delete(Tail->next);
                Tail->next = Head; 
                iSize--;
            }    
        }

        template<class T>
        void SinglyCL<T> :: DeleteLast()
        {        
            if(iSize == 0)
            {
                return;
            }
            else if(iSize == 1)
            {
                delete Head;
                Head = NULL;
                Tail = NULL;
                iSize = 0;
            }
            else
            {
                struct nodeSCL<T> * Temp = Head;
                for(int i=1 ; i<iSize-1 ; i++)
                {
                    Temp = Temp->next;
                }
                delete Tail;
                Tail = Temp;
                Tail -> next = Head;
                iSize--;
            }    
        }

        template<class T>
        void SinglyCL<T> :: DeleteatPos(int iPos)
        {        
             if((iPos < 1) && (iPos >iSize+1))
            {
                return;
            }
            
            if(iPos == 1)
            {
                DeleteFirst();
            }
            else if(iPos == iSize)
            {
                DeleteLast();
            }
            else
            {
                struct nodeSCL<T> * Temp = Head;
                struct nodeSCL<T> * Target = NULL;
                for(int i=1 ; i<iPos-1 ; i++)
                {
                    Temp = Temp->next;
                }
                Target = Temp->next;
                Temp->next = Target -> next;
                delete Target;
                iSize--;  
            }    
        }

        template<class T>
        int SinglyCL<T> :: Count()
        {
            return iSize;
        }

        template<class T>
        void SinglyCL<T> :: Display()
        {
            struct nodeSCL<T> * Temp = Head;

            for(int i=1 ; i<=iSize ; i++)
            {
                cout<<Temp->data<<"-> ";
                Temp = Temp->next;    
            }
            cout<<"\n";
        }





///////////////////////////////////////////////////////////////////////////////
//
//    Class Name : Doubly Circular Linked-List
//    Struct Name : nodeDCL
//    Contains Function like :
//                               Count();
//                               InsertFirst(T);
//                               InsertLast(T);
//                               InsertatPos(int,T);
//                               DeleteFirst();   
//                               DeleteLast();   
//                               Display();    
//                               DeleteatPos(int );
//
/////////////////////////////////////////////////////////////////////////////////



template<class T>
struct nodeDCL
{
    T data;
    struct nodeDCL *next;    
    struct nodeDCL *prev;    
};


template<class T>
class DoublyCL
{
    private:
        struct nodeDCL<T> * Head;
        struct nodeDCL<T> * Tail;
        int iSize;
    public:
        DoublyCL() //Default Constructor
        {
            Head = NULL;
            Tail = NULL;
            iSize = 0;
        }

        void InsertFirst(T);
        void InsertLast(T);
        void InsertatPos(int,T);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        void Display();
        int Count();
};

    template<class T>
    void DoublyCL<T> :: InsertFirst(T iVal)
        {
            struct nodeDCL<T> * newn;
            newn = new struct nodeDCL<T> ;
            newn->next = NULL;
            newn->prev = NULL;
            newn->data = iVal;

            if(iSize == 0)
            {
                Head = newn;
                Tail = newn;
            }
            else
            {
                newn->next=Head;
                Head->prev = newn;
                Head = newn;
            }
            iSize++;
            Head->prev = Tail;
            Tail->next = Head;
        }

        template<class T>
        void DoublyCL<T> :: InsertLast(T iVal)
        {
            struct nodeDCL<T> * newn;
            newn = new struct nodeDCL<T> ;
            newn->next = NULL;
            newn->prev = NULL;
            newn->data = iVal;

            if(iSize == 0)
            {
                Head = newn;
                Tail = newn;
            }
            else
            {
                Tail->next = newn;
                newn->prev = Tail;
                Tail = newn;
            }
            Tail->next = Head;
            Head->prev = Tail;
            iSize++;
        }


        template<class T>
        void DoublyCL<T> :: InsertatPos(int iPos,T iNo)
        {
            if((iPos<1)||(iPos>iSize+1))
            {
                return;
            }
            else if(iPos == 1 )
            {
                InsertFirst(iNo);
            }
            else if(iPos == iSize+1)
            {
                InsertLast(iNo);
            }
            else
            {
                
            struct nodeDCL<T> * newn = new struct nodeDCL<T> ;
            newn->next = NULL;
            newn->prev = NULL;
            newn->data = iNo;

            struct nodeDCL<T> * Temp = Head;
            for(int i=1;i<iPos-1;i++)
            {
                Temp = Temp->next;
            }
            newn->next = Temp->next;
            Temp->next->prev = newn;
            Temp->next = newn;
            newn->prev = Temp;
            iSize++; 
            }
        }

        template<class T>
        void DoublyCL<T>  :: Display()
        {
            struct nodeDCL<T> * Temp = Head;
            for(int i=1;i<=iSize;i++)
            {
                cout<<Temp->data<<"\t";
                Temp = Temp->next;
            }
            cout<<"\n";
        }

        template<class T>
        int DoublyCL<T> :: Count()
        {
            return iSize;
        }

        
    template<class T>
    void DoublyCL<T>::DeleteFirst()
    {
            if(iSize == 0)
            {
                return;
            }
            else if(iSize == 1)
            {
                delete Head;
                Head = NULL;
                Tail = NULL;
                iSize--;
            }
            else 
            {
                Head = Head->next;
                delete(Tail->next);
                Head->prev = Tail;
                Tail->next = Head;
                iSize--;
            }
    }

    template<class T>
    void DoublyCL<T>::DeleteLast()
    {   
        if(iSize == 0)
            {
                return;
            }
            else if(iSize == 1)
            {
                delete Tail;
                Head = NULL;
                Tail = NULL;
                iSize--;
                return;
            }
            else 
            {
                Tail = Tail->prev;
                delete(Tail->next);
                Tail->next = Head;
                Head->prev = Tail;
                iSize--;
            }
    }

    template<class T>
    void DoublyCL<T>::DeleteAtPos(int iPos)
    {
        if((iPos<1)||(iPos>iSize))
            {
                return;
            }
            else if(iPos == 1 )
            {
                DeleteFirst();
            }
            else if(iPos == iSize)
            {
                DeleteLast();
            }
            else
            {

            struct nodeDCL<T> * Temp = Head;
            // struct nodeDCL * Target;
            for(int i=1;i<iPos-1;i++)
            {
                Temp = Temp->next;
            }
            Temp->next = Temp->next->next;
            delete(Temp->next->prev);
            Temp->next->prev = Temp;
            // Target = Temp->next;
            // Target->next->prev = Temp;
            // Temp->next = Target->next;
            // delete Target;
            iSize--;
            }
    }




///////////////////////////////////////////////////////////////////////////////
//
//    Class Name : Doubly Circular Linked-List
//    Struct Name : nodeDCL
//    Contains Function like :
//                                 Stack();            //Constructor
//                                 void Push(T);       // void InsertFirst(int);
//                                 int Pop();          // void DeleteFirst()
//                                 void Display();
//                                 int Count();
//
/////////////////////////////////////////////////////////////////////////////////




template <class T>
struct nodestk
{
    T data;
    struct nodestk *next;
};


template<class T>
class Stack
{
private:
    struct nodestk<T> * Head;
    int iSize;

public:
    Stack();        //Constructor
    void Push(T); // void InsertFirst(int);
    int Pop();      // void DeleteFirst()
    void Display();
    int Count();
};

template<class T>
Stack<T>::Stack()
{
    this->Head = NULL; //Same as Head=NULL
    this->iSize = 0;   //same as iSize =0
}


template<class T>
void Stack<T> ::Push(T iNo)
{
    struct nodestk<T> * newn = NULL;
    newn = new struct nodestk<T>;
    newn->data = iNo;
    newn->next = NULL;

    newn->next = Head;
    Head = newn;
    iSize++;
}

template<class T>
int Stack<T>::Pop()
{
    int iRet = -1;
    if (iSize == 0)
    {
        cout << "Stack is Empty \n";
    }
    else
    {
        struct nodestk<T> * Temp = Head;
        Head = Head->next;
        iRet = Temp->data;
        delete Temp;
        iSize--;
    }
    return iRet;
}

template<class T>
void Stack<T>::Display()
{
    struct nodestk<T> * Temp = Head;
    while (Temp != NULL)
    {
        cout << "|" << Temp->data << "|->";
        Temp = Temp->next;
    }
    cout << "NULL\n";
}

template<class T>
int Stack<T>::Count()
{
    return iSize;
}





///////////////////////////////////////////////////////////////////////////////
//
//          Class Name : Queue
//          Struct Name : nodeque
//          Contains Function like :
//                                    Queue();
//                                    void Display();
//                                    int Count();
//                                    void Enqueue(T);
//                                    int Dequeue();
//                                    bool isEmpty();
//                                    int Front();
//
/////////////////////////////////////////////////////////////////////////////////




template <class T>
struct nodeque
{
    int data;
    struct nodeque *next;
};


template <class T>
class Queue
{
private:
    struct nodeque<T> * Head;
    int iSize;
    
public:
    Queue();
    void Display();
    int Count();
    void Enqueue(T);
    int Dequeue();
    bool isEmpty();
    int Front();
};

template <class T>
Queue<T>::Queue()
{
    Head = NULL;
    iSize = 0;
}

template <class T>
void Queue<T>::Display()
{
    struct nodeque<T> * temp = Head;
    cout<<"Elements of queue are\n";
    while(temp != NULL)
    {
        cout<<temp->data<<"\t";
        temp = temp -> next;
    }
    cout<<"\n";
}

template <class T>
int Queue<T>::Count()
{
    return iSize;
}

template <class T>
bool Queue<T> :: isEmpty()
{
    if(iSize == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
int Queue<T>:: Front()
{
    return (Head->data);
}

template <class T>
void  Queue<T>::Enqueue(T iNo)   // InsertLast
{
    struct nodeque<T> * newn = new struct nodeque<T>;
    newn->data = iNo;
    newn->next = NULL;
    
  if(Head == NULL)
  {
      Head = newn;
  }
  else
  {
    struct nodeque<T> * temp = Head;
    while(temp-> next != NULL)
    {
        temp = temp -> next;
    }
    temp->next = newn;
  }
    iSize++;
}

template <class T>
int Queue<T>::Dequeue()    // Delete First
{
    if(Head == NULL)
    {
        cout<<"Queue is empty\n";
        return -1;
    }
    else
    {
        int iNo = Head -> data;
        struct nodeque<T> * temp = Head;
        Head = Head -> next;
        delete temp;
        iSize--;
        
        return iNo;
    }
}

template <class T>
void DoublyLinked(T *obj)
{
    int iChoice2 = 1, iNo1 = 0, iRet = 0, iPos1 = 0;
    while(iChoice2 != 0)
    {
        cout<<"Enter your choice:\n";
        cout<<"1 : Insert First\n";
        cout<<"2 : Insert Last\n";
        cout<<"3 : Insert at pos\n";
        cout<<"4 : Delete first \n";
        cout<<"5 : Delete Last\n";
        cout<<"6 : Delete at pos\n";
        cout<<"7 : Display the elements\n";
        cout<<"8 : Count number of elements\n";
        cout<<"0 : Go Back to Previous Menu\n";
        cin>>iChoice2;
        
        switch(iChoice2)
        {
            case 1:
                cout<<"Enter number\n";
                cin>>iNo1;
                obj->InsertFirst(iNo1);
                break;
                
            case 2 :
                cout<<"Enter number\n";
                cin>>iNo1;
                obj->InsertLast(iNo1);
                break;
                
            case 3:
                cout<<"Enter number\n";
                cin>>iNo1;
                cout<<"Enter position\n";
                cin>>iPos1;
                obj->InsertAtPos(iNo1,iPos1);
                break;
                
            case 4:
                obj->DeleteFirst();
                break;
                
            case 5:
                obj->DeleteLast();
                break;
                
            case 6:
                cout<<"Enter the position\n";
                cin>>iPos1;
                obj->DeleteAtPos(iPos1);
                break;
                
            case 7:
                cout<<"Elements of LL are\n";
                obj->Display();
                break;
                
            case 8:
                iNo1 = obj->Count();
                cout<<"Number of nodes are : "<<iNo1<<"\n";
                break;
                
            case 0:
                cout<<"Thank you for using the application\n";
                break;
                
            default:
                cout<<"Please enter proper option\n";
                break;
        }// End of switch
    }// End of while
}

template<class T>
void SinglyLinked(T *obj1)
{
    int iChoice = 1;
    int iNo = 0;
    int iPos = 0;

    while(iChoice!=0)
    {
        cout<<"\n____________________________________\n";
        cout<<"Enter Your Choice : \n";
        cout<<"1 : Insert at First Position"<<endl;
        cout<<"2 : Insert at Last Position"<<endl;
        cout<<"3 : Insert at a given position"<<endl;
        cout<<"4 : Delete at First Position"<<endl;
        cout<<"5 : Delete at Last Position"<<endl;
        cout<<"6 : Delete at a Given Position"<<endl;
        cout<<"7 : Display the Contents"<<endl;
        cout<<"8 : Count no of Nodes"<<endl;
        cout<<"0 : Go Back to Previous Menu"<<endl;
        cout<<"\n____________________________________\n";
        cin>>iChoice;

        switch(iChoice)
        {
            case 1:
                cout<<"Enter a Number "<<endl;
                cin>>iNo;
                obj1->InsertFirst(iNo);
                break;
            case 2:
                cout<<"Enter a Number "<<endl;
                cin>>iNo;
                obj1->InsertLast(iNo);
                break;
            case 3:
                cout<<"ENter a Position"<<endl;
                cin>>iPos;
                cout<<"Enter a Value"<<endl;
                cin>>iNo;
                obj1->InsertatPos(iPos,iNo);
                break;
            case 4:
                obj1->DeleteFirst();
                break;
            case 5:
                obj1->DeleteLast();
                break;
            case 6:
                cout<<"ENter a Position"<<endl;
                cin>>iPos;
                obj1->DeleteatPos(iPos);
                break;
            case 7:
                obj1->Display();
                break;
            case 8:
                iNo = obj1->Count();
                cout<<"Number of Elements in LL is "<<iNo<<endl;
                break;
            case 0:
                cout<<"Thankyou for using My application"<<endl;
                break;
            default:
                cout<<"Please Select Valid Option"<<endl;
                break;
        }
    } 
}


template<class T>
void SinglyCircular(T *obj3)
{
    int iPos = 0;
    int iChoice = 1;
    int iValue = 0; 
    int iRet = 0;
    
    while(iChoice!=0)
    {
        cout<<"\n________________________________\n";
        cout<<"Select an Option\n";;
        cout<<"1 : Insert First \n";
        cout<<"2 : Insert Last \n";
        cout<<"3 : Insert at given Position \n";
        cout<<"4 : Delete First \n";
        cout<<"5 : Delete Last \n";
        cout<<"6 : Delete at a given Position \n";
        cout<<"7 : Display all node\n";
        cout<<"8 : Count the number of nodes \n";
        cout<<"0 : Go back to previous Menu";
        cout<<"\n________________________________\n";
        cin>>iChoice;

        switch(iChoice)
        {
            case 1:
                cout<<"ENter a Number \n";
                cin>>iValue;
                obj3->InsertFirst(iValue);
                break;
            case 2:
                cout<<"ENter a Number \n";
                cin>>iValue;
                obj3->InsertLast(iValue);
                break;
            case 3:
                cout<<"ENter a Number \n";
                cin>>iValue;
                cout<<"Enter  a Position \n";
                cin>>iPos;
                obj3->InsertatPos(iValue,iPos);
                break;
            case 4:
                obj3->DeleteFirst();
                break;
            case 5:
                obj3->DeleteLast();
                break;
            case 6:
                cout<<"Enter  a Position \n";
                cin>>iPos;
                obj3->DeleteatPos(iPos);
                break;
            case 7:
                obj3->Display();
                break;
            case 8:
                iRet = obj3->Count();
                cout<<"The no of nodes are : \n"<<iRet;
                break;
            case 0:
                cout<<"Thanks for using my application\n";
            default:
                cout<<"ENter a valid option number \n";
        } //End of Switch
    }//Rnd of While
}



template <class T>
void  DoublyCircular(T *obj4)
{
    int iNo = 0;
    int iPos = 0;
    int iChoice = 1;

    while(iChoice != 0)
    {
        cout<<"Enter your choice :"<<"\n";
        cout<<"1 : Insert at first position "<<"\n";
        cout<<"2 : Insert at last position "<<"\n";
        cout<<"3 : Insert at given position "<<"\n";
        cout<<"4 : Delete first node "<<"\n";
        cout<<"5 : Delete last node "<<"\n";
        cout<<"6 : Delete node at give position "<<"\n";
        cout<<"7 : Display the contents "<<"\n";
        cout<<"8 : Count the number of nodes "<<"\n";
        cout<<"0 : Exit the application "<<"\n";
        cin>>iChoice;
        
        switch(iChoice)
        {
            case 1:
                cout<<"Enter number\n";
                cin>>iNo;
                obj4->InsertFirst(iNo);
                break;
                
            case 2:
                cout<<"Enter number\n";
                cin>>iNo;
                obj4->InsertLast(iNo);
                break;
            
            case 3:
                cout<<"ENter a Position"<<endl;
                cin>>iPos;
                cout<<"Enter a Value"<<endl;
                cin>>iNo;
                obj4->InsertatPos(iPos,iNo);
                break;
            
            case 4:
                obj4->DeleteFirst();
                break;
            
            case 5:
                obj4->DeleteLast();
                break;
                
            case 6:
                cout<<"ENter a Position"<<endl;
                cin>>iPos;
                obj4->DeleteAtPos(iPos);
                break;
            
            case 7:
                obj4->Display();
                break;
            
            case 8:
                iNo = obj4->Count();
                cout<<"Number of elements are : "<<iNo<<"\n";
                break;
                
            case 0:
                cout<<"Thank you for using the application\n";
                break;
                
            default:
                cout<<"Please enter procper option\n";
                break;
        } //END of Switch
    }//END of While
}


template<class T>
void Stackfun(T *obj)
{
    int iOption = 1;
    int iRet = 0;
    int iNo = 0;

    while (iOption != 0)
    {
        cout << "_____________________________\n";
        cout << " 1 : Push the Element \n";
        cout << " 2 : Pop the Element \n";
        cout << " 3 : Display the Element \n";
        cout << " 4 : Count nunmber of Element \n";
        cout << " 0 : Exit the Application \n";
        cout << "_____________________________\n";
        cin >> iOption;

        switch (iOption)
        {
        case 1:
            cout << "Enter the Element to push \n";
            cin >> iNo;
            obj->Push(iNo);
            break;
        case 2:
            iRet = obj->Pop();
            cout << "Popped Element is :" << iRet << "\n";
            break;
        case 3:
            cout << "Elements of Stack are : \n";
            obj->Display();
            break;
        case 4:
            iRet = obj->Count();
            cout << "Number of Elements in stack are :" << iRet << "\n";
            break;
        case 0:
            cout << "ThankYou for Using the Application\n";
            // Here user wants to terminate the prog so 
            break;
        default:
            cout << "Enter a Valid Option \n";
            break;
        } //End of switch
    }     // End of while
}


template<class T>
void Queuefun(T *obj)
{
    int iChoice = 1, iNo = 0, iRet = 0;
    bool bRet = false;
    while(iChoice != 0)
    {
        cout<<"Pleaseeneter the option\n";
        cout<<"1 : Enqueue\n";
        cout<<"2 : Dequeue\n";
        cout<<"3 : check isEmpty\n";
        cout<<"4 : Display Front\n";
        cout<<"5 : Display the elemenets\n";
        cout<<"6 : Count the enumber of elements\n";
        cout<<"0 : Terminate the application\n";
        cin>>iChoice;
        switch(iChoice)
        {
            case 1:
                cout<<"Enter the elemenet\n";
                cin>>iNo;
                obj->Enqueue(iNo);
                break;
                
            case 2:
                iRet = obj->Dequeue();
                cout<<"Removed element is : "<<iRet<<"\n";
                break;

            case 3:
                bRet = obj->isEmpty();
                if(bRet)
                {
                    cout<<"Queue is Empty\n"<<endl;
                }
                else
                {
                    cout<<"Queue is Not Empty\n"<<endl;
                }
                break;

            case 4:
                iRet = obj->Front();
                cout<<"Element at front is :"<<iRet<<endl;
                break;
                
            case 5:
                obj->Display();
                break;
                
            case 6 :
                iRet = obj->Count();
                cout<<"Number of elements in queue are : "<<iRet<<"\n";
                break;
                
            case 0:
                cout<<"Thank you for using the application\n";
                break;
                
            default:
                cout<<"Please enter the proper choice\n";
                break;
        }// End of switch
    } // End of while
}


int main()
{
    int iMOption=1;
    //for SLL
    int iSLLOption = 1;

    // for DLL
    int iDLLOption = 1;

    //for SCL
    int iSCLOption = 1;

    //for DCL
    int iDCLOption = 1;

    //for stack
    int iStackOption = 1;

    //for queue
    int iQueueOption = 1;



    while(iMOption!=0)
    {
        cout<<"Please Select One of the Following : \n";
        cout<<" 1 : Singly Linear Linked-List \n";
        cout<<" 2 : Doubly Linear Linked-List \n";
        cout<<" 3 : Singly Circular Linked-List \n";
        cout<<" 4 : Doubly Circular Linked-List \n";
        cout<<" 5 : Stack \n";
        cout<<" 6 : Queue \n";
        cout<<" 0 : Exit the Application \n";
        cin>>iMOption;

        switch(iMOption)
        {
            case 1:
                    iSLLOption = 1;
                    while(iSLLOption!=0)
                    {
                        cout<<"Which type of data Do you want to Insert in the SLL \n";
                        cout<<" 1 : INTEGER\n";
                        cout<<" 2 : FLOAT\n";
                        cout<<" 3 : CHAR\n";
                        cout<<" 4 : DOUBLE\n";
                        cout<<" 0 : Go Back to Main Menu \n";
                        cin>>iSLLOption;
                            if(iSLLOption == 1) 
                            {
                                SinglyLL <int> *obj1 = new SinglyLL<int> ;
                                SinglyLinked(obj1);
                                delete obj1;
                            }   
                            else if(iSLLOption == 2)
                            {
                                SinglyLL <float> *obj1 = new SinglyLL<float> ;                               
                                SinglyLinked(obj1);
                                delete obj1;
                            }    // break of case2
                            else if(iSLLOption == 3)
                            {                       
                                SinglyLL <char> *obj1 = new SinglyLL<char> ;                                 
                                SinglyLinked(obj1);
                                delete obj1;
                            }   //break of case 3     
                            else if(iSLLOption == 4)
                            {   
                                SinglyLL <double> *obj1 = new SinglyLL<double> ;                
                                SinglyLinked(obj1);
                                delete obj1;
                            }
                            else if(iSLLOption == 0)
                            {
                                break;
                            }
                            else
                            {
                                cout<<"Please Select a Valid Option \n";
                            } 
                    }
                break;
            case 2:
                    iDLLOption = 1;
                    while(iDLLOption!=0)
                    {
                        cout<<"Which type of data Do you want to Insert in the DLL \n";
                        cout<<" 1 : INTEGER\n";
                        cout<<" 2 : FLOAT\n";
                        cout<<" 3 : CHAR\n";
                        cout<<" 4 : DOUBLE\n";
                        cout<<" 0 : Go Back to Main Menu \n";
                        cin>>iDLLOption;

                        if(iDLLOption == 1)
                        {
                            DoublyLL <int> *obj2 = new DoublyLL<int>;
                            DoublyLinked(obj2);
                            delete obj2;
                        }
                        else if(iDLLOption == 2)
                        {
                          DoublyLL <float> *obj2 = new DoublyLL<float>;
                            DoublyLinked(obj2);   
                            delete obj2;                        
                        }
                        else if(iDLLOption == 3)
                        {
                           DoublyLL <char> *obj2 = new DoublyLL<char>;
                            DoublyLinked(obj2);  
                            delete obj2;            
                        }
                        else if(iDLLOption == 4)
                        {
                           DoublyLL <double> *obj2 = new DoublyLL<double>;
                            DoublyLinked(obj2);
                            delete obj2;                       
                        }
                        else if(iDLLOption == 0)
                        {
                            break;
                        }
                        else
                        {
                            cout<<"Select a Valid Option"<<endl;
                        }
                    } //end of iDLLoption
                break;
            case 3:
                    iSCLOption = 1;
                    while(iSCLOption!=0)
                    {
                        cout<<"Which type of data Do you want to Insert in the SCL \n";
                        cout<<" 1 : INTEGER\n";
                        cout<<" 2 : FLOAT\n";
                        cout<<" 3 : CHAR\n";
                        cout<<" 4 : DOUBLE\n";
                        cout<<" 0 : Go Back to Main Menu \n";
                        cin>>iSCLOption;

                        if(iSCLOption == 1)
                        {
                            SinglyCL <int> *obj3 = new SinglyCL <int>;
                            SinglyCircular(obj3); 
                            delete obj3;
                        }
                        else if(iSCLOption == 2)
                        {
                            SinglyCL <float> *obj3 = new SinglyCL <float>;
                            SinglyCircular(obj3); 
                            delete obj3;                           
                        }
                        else if(iSCLOption == 3)
                        {
                            SinglyCL <char> *obj3 = new SinglyCL <char>;
                            SinglyCircular(obj3);
                            delete obj3;               
                        }
                        else if(iSCLOption == 4)
                        {
                            SinglyCL <double> *obj3 = new SinglyCL <double>;
                            SinglyCircular(obj3);
                            delete obj3;                        
                        }
                        else if(iSCLOption == 0)
                        {
                            break;
                        }
                        else
                        {
                            cout<<"Select a Valid Option"<<endl;
                        }
                    } //end of iDLLoption

                break;
            case 4:
                iDCLOption = 1;
                    while(iDCLOption!=0)
                    {
                        cout<<"Which type of data Do you want to Insert in the DCL \n";
                        cout<<" 1 : INTEGER\n";
                        cout<<" 2 : FLOAT\n";
                        cout<<" 3 : CHAR\n";
                        cout<<" 4 : DOUBLE\n";
                        cout<<" 0 : Go Back to Main Menu \n";
                        cin>>iDCLOption;
                            if(iDCLOption == 1) 
                            {
                                DoublyCL <int> *obj = new DoublyCL <int>;
                                DoublyCircular(obj);
                                delete obj;
                            }   
                            else if(iDCLOption == 2)
                            {
                                DoublyCL <float> *obj = new DoublyCL <float>;
                                DoublyCircular(obj);
                                delete obj;
                            }    // break of case2
                            else if(iDCLOption == 3)
                            {                       
                                DoublyCL <char> *obj = new DoublyCL <char>;
                                DoublyCircular(obj);
                                delete obj;
                            }   //break of case 3     
                            else if(iDCLOption == 4)
                            {   
                                DoublyCL <double> *obj = new DoublyCL <double>;
                                DoublyCircular(obj);
                                delete obj;
                            }
                            else if(iDCLOption == 0)
                            {
                                break;
                            }
                            else
                            {
                                cout<<"Please Select a Valid Option \n";
                            } 
                    }

                break;
            case 5:
                iStackOption = 1;
                    while(iStackOption!=0)
                    {
                        cout<<"Which type of data Do you want to Insert in the Stack \n";
                        cout<<" 1 : INTEGER\n";
                        cout<<" 2 : FLOAT\n";
                        cout<<" 3 : CHAR\n";
                        cout<<" 4 : DOUBLE\n";
                        cout<<" 0 : Go Back to Main Menu \n";
                        cin>>iStackOption;
                            if(iStackOption == 1) 
                            {
                                Stack <int> *obj = new Stack<int>; //  object memory gets allocated and constructor is called implicitly when we allocate memory to object
                                Stackfun(obj);
                                delete obj;
                            }   
                            else if(iStackOption == 2)
                            {
                                Stack <float> *obj = new Stack<float>; //  object memory gets allocated and constructor is called implicitly when we allocate memory to object
                                Stackfun(obj);
                                delete obj;
                            }    // break of case2
                            else if(iStackOption == 3)
                            {                       
                                Stack <char> *obj = new Stack<char>; //  object memory gets allocated and constructor is called implicitly when we allocate memory to object
                                Stackfun(obj);
                                delete obj;
                            }   //break of case 3     
                            else if(iStackOption == 4)
                            {   
                                Stack <double> *obj = new Stack<double>; //  object memory gets allocated and constructor is called implicitly when we allocate memory to object
                                Stackfun(obj);
                                delete obj;
                            }
                            else if(iStackOption == 0)
                            {
                                break;
                            }
                            else
                            {
                                cout<<"Please Select a Valid Option \n";
                            } 
                    }
                break;
            case 6:
                iQueueOption = 1;
                    while(iQueueOption!=0)
                    {
                        cout<<"Which type of data Do you want to Insert in the Queue \n";
                        cout<<" 1 : INTEGER\n";
                        cout<<" 2 : FLOAT\n";
                        cout<<" 3 : CHAR\n";
                        cout<<" 4 : DOUBLE\n";
                        cout<<" 0 : Go Back to Main Menu \n";
                        cin>>iQueueOption;
                            if(iQueueOption == 1) 
                            {
                                Stack <int> *obj = new Stack<int>; //  object memory gets allocated and constructor is called implicitly when we allocate memory to object
                                Stackfun(obj);
                                delete obj;
                            }   
                            else if(iQueueOption == 2)
                            {
                                Stack <float> *obj = new Stack<float>; //  object memory gets allocated and constructor is called implicitly when we allocate memory to object
                                Stackfun(obj);
                                delete obj;
                            }    // break of case2
                            else if(iQueueOption == 3)
                            {                       
                                Stack <char> *obj = new Stack<char>; //  object memory gets allocated and constructor is called implicitly when we allocate memory to object
                                Stackfun(obj);
                                delete obj;
                            }   //break of case 3     
                            else if(iQueueOption == 4)
                            {   
                                Stack <double> *obj = new Stack<double>; //  object memory gets allocated and constructor is called implicitly when we allocate memory to object
                                Stackfun(obj);
                                delete obj;
                            }
                            else if(iQueueOption == 0)
                            {
                                break;
                            }
                            else
                            {
                                cout<<"Please Select a Valid Option \n";
                            } 
                    }
                break;
            case 0:
                cout<<"Thankyou For using My Application \n";
                break;
            default : 
                cout<<"Please Select a Valid option \n";
        }

    }
    return 0;
}