//
//  Header.h
//  Circular-Doubly LinkedList
//
//  Created by Shirong Zheng on 2016/05/20.
//
//

#ifndef Header_h
#define Header_h

#include<cstdlib>
#include<iostream>

using namespace std;

int data = 0;
struct node
{
    int info;
    struct node *next;
    struct node *prev;
} *start, *last;


template<class T>
class CDlist
{
public:
    node *create_node(int);
    void insert_begin();
    void insert_last();
    void insert_pos();
    void display();
    friend std::ostream & operator<<(std::ostream & os, const CDlist<T> & cdl);
     CDlist()
    {
        start = NULL;
        last = NULL;
    }
};

template<class T>
node* CDlist<T>::create_node(int value)
{
    data++;
    struct node *temp;
    temp = new(struct node);
    temp->info = value;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

template<class T>
void CDlist<T>::insert_begin()
{
    int value;
    cout<<endl<<"Enter the element to be store: ";
    cin>>value;
    struct node *temp;
    temp = create_node(value);
    
    if (start == last && start == NULL)
    {
        cout<<"Element stored in empty list"<<endl;
        start = last = temp;
        start->next = last->next = NULL;
        start->prev = last->prev = NULL;
    }
    else
    {
        temp->next = start;
        start->prev = temp;
        start = temp;
        start->prev = last;
        last->next = start;
        cout<<"Element stored"<<endl;
    }
}


template<class T>
void CDlist<T>::insert_last()
{
    int value;
    cout<<endl<<"Enter the element to be stored: ";
    cin>>value;
    struct node *temp;
    temp = create_node(value);
    if (start == last && start == NULL)
    {
        cout<<"Element stored in empty list"<<endl;
        start = last = temp;
        start->next = last->next = NULL;
        start->prev = last->prev = NULL;
    }
    else
    {
        last->next = temp;
        temp->prev = last;
        last = temp;
        start->prev = last;
        last->next = start;
    }
}

template<class T>
void CDlist<T>::insert_pos()
{
    int value, pos, n;
    cout<<endl<<"Please type the element to be stored: ";
    cin>>value;
    cout<<endl<<"Please type the postion of element stored: ";
    cin>>pos;
    struct node *temp, *s, *ptr;
    temp = create_node(value);
    if (start == last && start == NULL)
    {
        if (pos == 1)
        {
            start = last = temp;
            start->next = last->next = NULL;
            start->prev = last->prev = NULL;
        }
        else
        {
            cout<<"Position out of range"<<endl;
            data--;
            return;
        }
    }
    else
    {
        if (data< pos)
        {
            cout<<"Position out of range"<<endl;
            data--;
            return;
        }
        s = start;
        for (n = 1;n <= data;n++)
        {
            ptr = s;
            s = s->next;
            if (n == pos - 1)
            {
                ptr->next = temp;
                temp->prev = ptr;
                temp->next = s;
                s->prev = temp;
                cout<<"Element stored"<<endl;
                break;
            }
        }
    }
}

template<class T>
void CDlist<T>::display()
{
    int n;
    struct node *s;
    if (start == last && start == NULL)
    {
        cout<<"The List is empty, nothing to display"<<endl;
        return;
    }
    s = start;
    for (n = 0;n < data-1;n++)
    {
        cout<<s->info<<"<->";
        s = s->next;
    }
    cout<<s->info<<endl;
}

template <class T>
std::ostream & operator<<(std::ostream & os, const CDlist<T> & cdl)
{
    os<<"case1:"<<cdl.insert_begin<<" ";
    os<<"case2:"<<cdl.insert_last<<" ";
    os<<"case3:"<<cdl.insert_pos<<" ";
    return os;
}

class complex{
public:
    complex();
    complex(int img0,int real0);
    void setImg(int img0);
    void setReal(int Real0);
    int getImag()const;
    int getReal()const;
    void add(complex &);
    friend complex operator+(const complex& L1, const complex& L2);
    
private:
    int img;
    int real;
};



void complex::setImg(int img0){
    img=img0;
}

void complex::setReal(int real0){
    real=real0;
}

int complex::getImag()const{
    return img;
}

int complex::getReal()const{
    return real;
}

complex::complex(){
    img=1;
    real=1;
}

complex::complex(int img0,int real0){
    img=img0;
    real=real0;
}

template<class T>
complex operator+(const complex& L1, const complex& L2){
    return complex(L1.getImag()+L2.getImag(),L1.getReal()+L2.getReal());
}


#endif /* Header_h */
