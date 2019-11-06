/**************************************************************************************
** Program name: dubLinkedList.cpp
** Author: Michael Nutt
** Date: 11/05/2019
** Description: Implementation file for the LinkedList class.
**************************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include "dubLinkedList.hpp"
#include "node.hpp"
#include "menu.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

DubLinkedList::DubLinkedList()
{
    head = nullptr;
    tail = nullptr;
}

void DubLinkedList::addHead(int value)
{
    // If the list is empty
    if (head == nullptr)
    {
        // Set the head to the new node
        head = new Node(value, head, head);
        // Set the tail equal to the head
        tail = head;
    }
    // If the list is not empty
    else
    {
        // Point the current head's prev value to the new node
        // The new node;s next value points to the current head
        head->setPrev(new Node(value, head, nullptr));
        // Set the head to the new node
        head = head->getPrev();
    }

    cout << "Your new list: " << endl;
    printList();
}

void DubLinkedList::addTail(int value)
{
    // If the list is empty
    if (tail == nullptr)
    {
        // create a new tail and set next and prev to itself
        tail = new Node(value, tail, tail);
        // set the head equal to the tail
        head = tail;
    }
    // If the list is not empty
    else
    {
        // Point the current tail's next value to the new node
        // The new node's prev property points to the old tail
        tail->setNext(new Node(value, nullptr, tail));
        // Set the tail to the new node
        tail = tail->getNext();
    }

    cout << "Your new list: " << endl;
    printList();
}

void DubLinkedList::deleteHead()
{
    Node *currentHead = head;

    // If the list is empty
    if (head == nullptr)
    {
        cout << "The list is currently empty. Nothing to delete." << endl;
    }
    // If the list is not empty
    else
    {
        // If the list contains only one node
        if (head == tail)
        {
            head = nullptr;
            tail = nullptr;
        }
        // If the list contains more than one node
        else
        {
            // Reassign the head to the second node
            head = head->getNext();
            // Set the new head's prev value to point to a nullpointer
            head->setPrev(nullptr);
        }

        // Delete the old head
        delete currentHead;

        cout << "Your new list: " << endl;
        printList();
    }
}

void DubLinkedList::deleteTail()
{
    Node *currentTail = tail;

    // If the list is empty
    if (tail == nullptr)
    {
        cout << "The list is currently empty. Nothing to delete." << endl;
    }
    // If the list is not empty
    else
    {
        // If the list contains only one node
        if (head == tail)
        {
            head = nullptr;
            tail = nullptr;
        }
        // If the list contains more than one node
        else
        {
            // Set the tail to the current tail's prev value
            tail = tail->getPrev();
            // Set the new tail's next value to a nullptr
            tail->setNext(nullptr);
        }

        // Delete the old tail
        delete currentTail;

        cout << "Your new list: " << endl;
        printList();
    }
}

void DubLinkedList::printInReverse()
{
    // If the list is empty
    if (head == nullptr)
    {
        cout << "The list is currently empty. Nothing to print." << endl;
    }
    // If the list is not emtpy
    else
    {
        // If the list contains only one node
        if (head == tail)
        {
            cout << tail->getVal() << endl;
        }
        // If the list contains more than one node
        else
        {
            Node *currentNode = tail;

            // While there are nodes to traverse
            while (currentNode != nullptr)
            {
                cout << currentNode->getVal() << endl;

                // Reset currentNode to the previous node in the list
                currentNode = currentNode->getPrev();
            }
        }
    }
}

void DubLinkedList::printList()
{
    // If the list is empty
    if (head == nullptr)
    {
        cout << "The list is currently empty. Nothing to print." << endl;
    }
    // If the list is not emtpy
    else
    {
        Node *currentNode = head;

        // While there are nodes to traverse
        while (currentNode != nullptr)
        {
            cout << currentNode->getVal() << endl;

            // Reset currentNode to the previous node in the list
            currentNode = currentNode->getNext();
        }
    }
}

void DubLinkedList::printHeadVal()
{
    // If the list is empty
    if (head == nullptr)
    {
        cout << "The list is currently empty. Nothing to print." << endl;
    }
    else
    {
        cout << "Head value: " << head->getVal() << endl;
    }
}

void DubLinkedList::printTailVal()
{
    // If the list is empty
    if (tail == nullptr)
    {
        cout << "The list is currently empty. Nothing to print." << endl;
    }
    else
    {
        cout << "Tail value: " << tail->getVal() << endl;
    }
}

void DubLinkedList::runProgram()
{
    const string TITLE = "Doubly-Linked List";
    const string OPTION_1 = "Add a new head to the list.";
    const string OPTION_2 = "Add a new tail to the list.";
    const string OPTION_3 = "Delete the head.";
    const string OPTION_4 = "Delete the tail.";
    const string OPTION_5 = "Print the list in reverse order.";
    const string OPTION_6 = "**EC: Print the value of the head node.";
    const string OPTION_7 = "**EC: Pring the value of the tail node.";
    const string OPTION_8 = "Exit the program.";

    vector<string> options{OPTION_1, OPTION_2, OPTION_3, OPTION_4, OPTION_5, OPTION_6, OPTION_7, OPTION_8};

    bool programSelection = startMenu(TITLE);

    if (!programSelection)
    {
        cout << "Exiting program..." << endl;
        exit(0);
    }

    int menuSelection = multiOptionMenu(options);

    while (menuSelection)
    {
        handleSelection(menuSelection);

        menuSelection = multiOptionMenu(options);
    }
}

void DubLinkedList::handleSelection(int selection)
{

    switch (selection)
    {
    // Add a new head
    case 1:
    {
        string newHead = "new head value";
        int headVal = gameMenuRange(newHead, 0, 100);
        addHead(headVal);
        break;
    }
    // Add  new tail
    case 2:
    {
        string newTail = "new tail value";
        int tailVal = gameMenuRange(newTail, 0, 100);
        addTail(tailVal);
        break;
    }
    // Delete the head
    case 3:
    {
        deleteHead();
        break;
    }
    // Delete the tail
    case 4:
    {
        deleteTail();
        break;
    }
    // Print in reverse
    case 5:
    {
        cout << "Your list in reverse order: " << endl;
        printInReverse();
        break;
    }
    // Print head value
    case 6:
    {
        printHeadVal();
        break;
    }
    case 7:
    {
        printTailVal();
        break;
    }
    // Exit
    case 8:
    {
        cout << "Exiting program..." << endl;
        deallocateMem();
        exit(0);
        break;
    }
    }
}

void DubLinkedList::deallocateMem()
{
    Node *currentNode = head;

    // If the list is not emtpy
    if (currentNode != nullptr)
    {
        // While there are nodes
        while (currentNode->getNext() != nullptr)
        {
            currentNode = currentNode->getNext();
            delete currentNode->getPrev();
        }
        delete currentNode;
    }
}