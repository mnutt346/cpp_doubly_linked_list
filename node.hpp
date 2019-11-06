/**************************************************************************************
** Program name: node.hpp
** Author: Michael Nutt
** Date: 11/05/2019
** Description: Declaration and header file for the Node class.
**************************************************************************************/
#ifndef NODE_HPP
#define NODE_HPP

class Node
{
private:
    Node *next;
    Node *prev;
    int val;

public:
    Node();
    Node(int, Node *, Node *);
    int getVal();
    void setVal(int);
    Node *getNext();
    void setNext(Node *);
    Node *getPrev();
    void setPrev(Node *);
};

#endif