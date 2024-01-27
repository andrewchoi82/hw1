/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/
#include <cstddef>
#include "split.h"
using namespace std;

int main(int argc, char* argv[])
{
  Node* lin = new Node(7,NULL);
  Node* rin = new Node(6,lin);
  Node* sin = new Node(3,rin);
  Node* bin = new Node(4,sin);
  Node* tin = new Node(10,bin);
  Node* in = new Node(4,tin);

  Node* odds = NULL;
  Node* evens = NULL;

  split(in,odds,evens);
  
  
}
