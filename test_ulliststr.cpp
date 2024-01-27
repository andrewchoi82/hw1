#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite
using namespace std;
int main(int argc, char* argv[])
{ 
  ULListStr list;
	for (int i = 0; i < 30; ++i) {
    list.push_back(to_string(i));
  }

  for (int i = 0; i < 30; ++i) {
    cout<<list.get(i) <<endl;
  }



  cout<<list.front()<<endl;
  cout<<list.back()<<endl;
  cout<<list.get(27)<<endl;
  cout<<list.get(25)<<endl;

  
  ULListStr items;
  //testing push back
  items.push_back("first");
  items.push_back("second");
  items.push_back("third");
  items.push_back("fourth");
  items.push_back("fifth");
  items.push_back("sixth");
  items.push_back("seventh");
  items.push_back("eighth");
  items.push_back("nineth");
  items.push_back("tenth");
  //testing adding new item
  items.push_back("eleven");
  items.push_back("twelve");
  //cout<< "items:" + items.get(8) <<endl;
  cout<< "items:" + items.get(11) <<endl;

  items.pop_back();
  items.pop_back();
  cout<< "items:" + items.back()<<endl;

  items.pop_back();
  cout<< "items:" + items.back()<<endl;

  //testing pop front
  items.pop_front();
  items.pop_front();
  items.pop_front();
  cout<< "items:" + items.front()<<endl;

  items.push_front("newthird");
  items.push_front("newsecond");
  items.push_front("newfirst");
  cout<< "items:" + items.front()<<endl;


  items.push_front("negativeone");
  items.push_front("negativetwo");
  cout<< "items:" + items.front()<<endl;


  items.pop_front();
  items.pop_front();

  items.pop_front();
  cout<< "items:" + items.front()<<endl;
  cout<< "items:" + items.get(0) <<endl;
  cout<< "items:" + items.get(5) <<endl;


  //cout<< "items:" + items.get(8) <<endl;
  //cout<< "items:" + items.get(4) <<endl;

}
