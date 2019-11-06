/**************************************************************************************
** Program name: node.cpp
** Author: Michael Nutt
** Date: 11/05/2019
** Description: Implementation file for the Node class.
**************************************************************************************/
#include "node.hpp"

Node::Node()
{
    val = 1;
    next = nullptr;
    prev = nullptr;
}

Node::Node(int value, Node *nxt, Node *previous)
{
    val = value;
    next = nxt;
    prev = previous;
}

int Node::getVal()
{
    return this->val;
}

void Node::setVal(int value)
{
    this->val = value;
}

Node *Node::getNext()
{
    return this->next;
}

void Node::setNext(Node *newNext)
{
    this->next = newNext;
}

Node *Node::getPrev()
{
    return this->prev;
}

void Node::setPrev(Node *newPrev)
{
    this->prev = newPrev;
}