//
//  main.cpp
//  Circular-Doubly LinkedList
//
//  Created by Shirong Zheng on 2016/05/20.
//
//

#include <iostream>
#include<cstdio>
#include<cstdlib>
#include"Header.h"
using namespace std;

int main() {

        int choice;
        CDlist<int> cdl;

        complex L1(5.4,6.9);
        complex L2(8.8,3.2);
    
        while (1)
        {
           
            cout<<"1.Insert element at Beginning"<<endl;
            cout<<"2.Insert element at Last"<<endl;
            cout<<"3.Insert element at Position"<<endl;
            cout<<"4.Display The Created List"<<endl;
            cout<<"5.Exit"<<endl;
            cout<<"Enter the work functions from 1-4, or enter 5 to exit : ";
            cin>>choice;
            switch(choice)
            {
                case 1:
                    cdl.insert_begin();
                    break;
                case 2:
                    cdl.insert_last();
                    break;
                case 3:
                    cdl.insert_pos();
                    break;
                case 4:
                    cdl.display();
                    break;
                case 5:
                    exit(1); 
                default:
                    cout<<"Sorry, Computer cannot understand your command"<<endl;
            }
        }
    
   
    return 0;
    }

