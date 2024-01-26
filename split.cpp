/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */


void split(Node*& in, Node*& odds, Node*& evens){
  if(in==nullptr){
    return;
  }else{
    //creating temp node for the odds and evens
    Node* sortedNode = new Node(in->value,nullptr);
    Node * temp4next = in -> next;
    if(in->value % 2 == 0){
      //deleting the in head which requires it to set it to null before deleting the content
      Node * temp2delete = in;
      in = nullptr;
      delete temp2delete;
      if(evens==nullptr){
        //if there's no items in evens
        evens = sortedNode;
        split(temp4next, odds , evens);
      }
      else{
        evens -> next = sortedNode;
        split(temp4next, odds , evens->next);
      }
    }
    else{
      //deleting the in head which requires it to set it to null before deleting the content
      Node * temp2delete = in;
      in = nullptr;
      delete temp2delete;
      if(odds==nullptr){
        //if there's no items in odds
        odds = sortedNode;
        split(temp4next, odds , evens);
      }
      else{
        odds->next = sortedNode;
        split(temp4next, odds->next , evens);
      }
    }
  }
}

