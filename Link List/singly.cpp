#include<iostream>
using namespace std;

//Node class that create nodes
class Node{

public:

    int data;
    Node *link;

    Node(int data){
        this -> data = data;
        this -> link = NULL;
    }

};

//list class that add the node into the list
class Linklist{

private:

    Node *head;
    Node *tail;
    int totalNodes;

public:

    Linklist(){
        head = NULL;
        tail = NULL;
        totalNodes = 0;
    }

    //append method that add the node at the end of the link list
    void append(int data){
        //create node with node class
        Node *newNode = new Node(data);
        //initailze the node
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }

        //make the newNode the tail
        tail -> link = newNode;
        tail = newNode;
        totalNodes++;
    }

    //prepend method that add the node at the start of the link list
    void prepend(int data){
        //create node with node class
        Node *newNode = new Node(data);
        //initailze the node
        newNode -> link = head;
        head = newNode;
        totalNodes++;
    }

    //get the length of the link list
    void length(){
        cout<<"The length of the Link List is : "<<totalNodes<<endl;
    }

    //insert method to add the node anywhere in the link list
    void insert(int index , int data){
        //check the parameters
        if(index < 0){
            cout<<"invalid Position"<<endl;
        }
        else if(index == 0){
            //we just simply call the prepend function
            prepend(data);
        }
        else if(index >= totalNodes){
            //we just simply call the append function
            append(data);
        }
        else{
            //create node with node class
            Node *newNode = new Node(data);
            Node *prev = head;
            // we are finding the previous node w.r.t to index where we have to insert our node
            for(int i = 0; i < index - 1; i++){
                prev = prev -> link;
            }

            //assigning previos node pointer to the new node
            //newnode pointer to the next node where previos node pointing previosly
            newNode -> link = prev -> link;
            prev -> link = newNode;

            /*
            prev node                    new node                       next node
            [data,pointer to new node]-->[data, pointer to next node]-->[data, pointer to next node/null]
            */

            totalNodes++;

        }
    }

    //display method
    void display(){
        //check for no node
        if(head == NULL){
            cout<<"\nYou didn't insert any node yet\nPlease insert the Node first"<<endl;
        }

        //print the list
        Node *temp = head;
        for(int i = 0; i < totalNodes-1; i++){
            cout<<temp -> data<<" --> ";
            temp = temp -> link;
        }
        cout<<tail -> data<<endl;
    }

};

int main(){

    Linklist L;
    L.append(3);
    L.append(5);
    L.append(6);
    L.prepend(2);
    L.prepend(1);
    L.insert(0, 0);
    L.insert(10, 7);
    L.insert(4, 4);
    L.display();
    L.length();

    return 0;
}