/**************************************************************************************
** Program name: dubLinkedList.hpp
** Author: Michael Nutt
** Date: 11/05/2019
** Description: Declaration and header file for the LinkedList class.
**************************************************************************************/
#ifndef DUBLINKEDLIST_HPP
#define DUBLINKEDLIST_HPP

#include "node.hpp"

class DubLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    DubLinkedList();
    void addHead(int);
    void addTail(int);
    void deleteHead();
    void deleteTail();
    void printInReverse();
    void printList();
    void runProgram();
    void handleSelection(int);
    void printHeadVal();
    void printTailVal();
    void deallocateMem();
};

#endif