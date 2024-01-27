#include <cstddef>
#include <iostream>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& val)
{
  //if there is no items
  if(tail_ == NULL){
    Item* newItem = new Item();
    newItem->val[0] = val;
    head_ = newItem;
    tail_ = newItem;
    newItem->last++;
  }
  else{
    //check if the final item is full
    //if so, create a new item and link it
    if(tail_->last == ARRSIZE){
      std::cout << "new node" << val << std::endl;
      Item* newItem = new Item();
      newItem->val[0] = val;
      tail_->next = newItem;
      newItem->prev = tail_;
      tail_ = newItem;
      tail_->last++;
    }
    else{
      //when no new nodes needs to be made
      tail_->val[tail_->last] = val;
      tail_->last++;
    }
  }
  size_++;
}

void ULListStr::pop_back()
{
  //setting the final space as blank to pop
  tail_->val[tail_->last-1] = "";
  tail_->last--;
  //if there is no more values in the item
  if(tail_->first == tail_->last){
    Item* temp = tail_;
    //if there is no more items left
    if(head_==tail_){
      tail_ = NULL;
      head_ = NULL;
      delete temp;
    }
    //if there are other items left
    else{
      tail_->prev->next = NULL;
      tail_ = tail_ -> prev;
      temp->prev = NULL;
      delete temp;
    }
  }
  size_--;
}

void ULListStr::push_front(const std::string& val)
{
  if(head_ == NULL){
    //if there are no items
    Item* newItem = new Item();
    newItem->val[0] = val;
    head_ = newItem;
    tail_ = newItem;
    newItem->last++;
  }
  else{
    //if there are no spaces to the left to place the value, create a new node
    if(head_->first == 0){
      Item * newItem = new Item();
      newItem->val[ARRSIZE-1] = val;
      head_->prev = newItem;
      newItem->next = head_;
      head_ = newItem;
      head_->first = ARRSIZE-1;
      head_->last = ARRSIZE;
    }
    else{
      head_->val[head_->first-1] = val;
      head_->first--;
    }
  }
  size_++;
}

void ULListStr::pop_front()
{
  //get rid of the value first
  head_->val[head_->first].clear();
  head_->first++;
  //if there are no more values in the item, delete it
  if(head_->first == head_->last){
    Item* temp = head_;
    //if there are no more items
    if(head_ == tail_){
      tail_ = NULL;
      head_ = NULL;
      delete temp;
    }
    else{
      head_->next->prev = NULL;
      head_ = head_ -> next;
      //temp->next = NULL;
      delete temp;
    }
  }
  size_--;
}

std::string const & ULListStr::back() const
{
  return tail_->val[tail_->last-1];
}

std::string const & ULListStr::front() const
{
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  Item* temp = head_;
  int position = head_->first + loc;
  int nodeDifference = position/ARRSIZE;
  int positionDiff = position%ARRSIZE;
  //go through to the correct item and then locate the correct value location
  for(int i = 0; i< nodeDifference ; i++){
    temp = temp->next;
  }
  return &temp->val[positionDiff];
}



void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
