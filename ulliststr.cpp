#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <string>  

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

// WRITE YOUR CODE HERE--------------------------------------------------

//push_back function ------------------------------------------------
void ULListStr::push_back(const std::string& val)
{
  if (head_==NULL)
  {
    Item* newitem=new Item;
    head_=newitem;
    tail_=newitem;
    head_->val[head_->first]=val;
    head_->last++;
    size_++;
  }
  else
  {
    Item* temp=tail_;
    if (temp->last<=ARRSIZE-1)
    {
      temp->val[temp->last]=val;
      temp->last++;
      size_++;
    }
    else
    {
      //need to allocate a new node after the current node 
      Item* newnode=new Item;
      temp->next=newnode; 
      newnode->prev=temp;
      newnode->next=NULL;
      newnode->val[0]=val;
      tail_=newnode;
      newnode->last++;
      size_++;
    }
  }
}

//push_front function ----------------------------------------------
void ULListStr::push_front(const std::string& val)
{
  //empty case
  if (head_==NULL)
  {
    Item* newitem=new Item; //create the new node
    head_=newitem; //update the head to the newitem 
    tail_=newitem; //update the tail to the newitem 
    head_->val[ARRSIZE-1]=val; //update the last element in the array to be val 
    head_->first=ARRSIZE-1;
    head_->last=ARRSIZE;
    size_++; //total size 
  }
  else 
  {
    Item* temp=head_; 
    if (temp->first!=0)
    {
      (temp->first)--; 
      temp->val[temp->first]=val; //update the index before the cur first index 
      size_++; 
    }
    else
    {
      //need to create a new node in front of current node 
      Item* newnode=new Item;//allocate the new node
      head_=newnode; //update the head 
      head_->prev=NULL;
      head_->next=temp; 
      temp->prev=head_;
      //tail_=temp; 
      head_->val[ARRSIZE-1]=val;
      head_->first=ARRSIZE-1;
      head_->last=ARRSIZE; 
      size_++; 
    }
  }
}

//pop_front function ------------------------------------------
void ULListStr::pop_front()
{
  if (head_!=NULL)
  {
    head_->val[head_->first]=""; //change the last-1 index element to be empty string 
    head_->first++; //move the last location
    if ((head_->last)-(head_->first)==0 && head_!=tail_) //if the head node become empty amd next node is not null 
    {

      Item* temp=head_;
      head_=temp->next;
      head_->prev=NULL;
      delete temp; 
    }
    else if ((head_->last)-(head_->first)==0 && head_==tail_)
    {
      delete head_;
      head_=NULL;
      tail_=NULL;
    }
    size_--; //update the whole size 
  }
}

//pop_back function --------------------------------------------
 void ULListStr::pop_back()
 {
  //std::cout<<tail_->first<<" "<<tail_->last<<" "<<tail_->val[0]<<std::endl;
  if (tail_!=NULL)
  {
    tail_->val[tail_->last-1]=""; //change the last-1 index element to be empty string 
    tail_->last--; //move the last location
    if ((tail_->last)-(tail_->first)==0 && head_!=tail_) //if the head node become empty amd next node is not null 
    {

      Item* temp=tail_;
      tail_=temp->prev;
      tail_->next=NULL;
      delete temp; 
    }
    else if ((tail_->last)-(tail_->first)==0 && head_==tail_)
    {
      delete head_;
      head_=NULL;
      tail_=NULL;
    }
    size_--; //update the whole size 
  }
 }

//front function ------------------------------------------------
std::string const & ULListStr::front() const
{
  return head_->val[head_->first]; 
}

//back() function -----------------------------------------------
std::string const & ULListStr::back() const
{
  return tail_->val[tail_->last-1];
}

//getValAtLoc(loc) function --------------------------------------
std::string* ULListStr::getValAtLoc(size_t loc) const
{
  if (loc>=size_)
  {
    return NULL;
  }

  Item* temp=head_;
  while (temp->next!=NULL && temp->last-temp->first<=loc)
  {
    loc=loc-(temp->last-temp->first);
    temp=temp->next;  //go to the next node 
  }
  return &(temp->val[temp->first+loc]);

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
