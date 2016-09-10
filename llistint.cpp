#include "llistint.h"
#include <cstdlib>
#include <stdexcept>

LListInt::LListInt()
{
    head_ = NULL;
    tail_ = NULL;
    size_ = 0;
}

LListInt::~LListInt()
{
    clear();
}

bool LListInt::empty() const
{
    return size_ == 0;
}

int LListInt::size() const
{
    return size_;
}

void LListInt::insert(int loc, const int& val)
{
    Item* newItem = new Item();

    if(loc < 0 || loc > size_)
    {
        return;
    }

    //Check if list is empty
    if(empty())
    {
        head_ = newItem;
        tail_ = newItem;
        newItem->prev = NULL;
        newItem->next = NULL;
        newItem->val = val;
        size_++;
    }

    else
    {
        //Insert at beginning
        if(loc == 0)
        {
            newItem->val = val;
            newItem->prev = NULL;
            newItem->next = head_;

            head_->prev = newItem;
            head_ = newItem;
            size_++;
        }


        //Insert at end
        else if(loc == size_)
        {
            newItem->val = val;
            newItem->prev = tail_;
            newItem->next = NULL;

            tail_->next = newItem;
            tail_ = newItem;
            size_++;
        }

        //Insert anywhere else
        else
        {
            Item* temp = head_;
            temp = getNodeAt(loc);
            temp = temp->next;

            newItem->val = val;
            newItem->prev = temp->prev;
            temp->prev = newItem;
            newItem->next = temp;
            newItem->prev->next = newItem;
            size_++;
        }
    }
}

void LListInt::remove(int loc)
{
    
    if(empty())
    {
        return;
    }


    if(loc < 0 || loc > size_)
    {
        return;
    }

    //Remove at beginning
    if(loc == 0)
    {
        if(size() == 1)
        {
            Item* temp = head_;
            tail_ = NULL;
            head_ = NULL;
            delete temp;
            size_--;
        }

        else
        {
            Item* temp = head_;
            head_ = temp->next;
            head_->prev = NULL;
            delete temp;
            size_--;
        }
    }

    //Remove at end
    else if(loc == size_)
    {
        Item* temp = tail_;
        tail_ = temp->prev;
        tail_->next = NULL;
        delete temp;
        size_--;
    }


    //Remove anywhere else
    else
    {
        Item* temp = head_;
        temp = getNodeAt(loc);
        temp = temp->next;
        temp = temp->prev;
        size_--;
    }
}

void LListInt::set(int loc, const int& val)
{
    Item *temp = getNodeAt(loc);
    temp->val = val;
}

int& LListInt::get(int loc)
{
    if(loc < 0 || loc >= size_)
    {
        throw std::invalid_argument("bad location");
    }
    Item *temp = getNodeAt(loc);
    return temp->val;
}

int const & LListInt::get(int loc) const
{
    if(loc < 0 || loc >= size_)
    {
        throw std::invalid_argument("bad location");
    }
    Item *temp = getNodeAt(loc);
    return temp->val;
}

void LListInt::clear()
{
    while(head_ != NULL)
    {
        Item *temp = head_->next;
        delete head_;
        head_ = temp;
    }
    tail_ = NULL;
    size_ = 0;
}

//Copy constructor (deep copy)
LListInt::LListInt(const LListInt& other)
{
    //int copied = other.size_;
    //this->size = other.size_;
    this->head_ = NULL;
    this->tail_ = NULL;
    this->size_ = 0;
    for(int i=0; i<other.size_; i++)
    {
        this->insert(i, other.get(i));
    }

    return;
}

//Assignment Operator (deep copy)
LListInt& LListInt::operator=(const LListInt& other)
{
    if(this == &other)
    {
        return *this;
    }

    this->clear();

    for(int i=0; i<other.size_; i++)
    {
        int assigned = other.get(i);
        insert(i, assigned);
    }

    return *this;
}

//Concatenation Operator
LListInt LListInt::operator+(const LListInt& other) const
{
    LListInt copy(*this);

    for(int i=0; i<other.size(); i++)
    {
        copy.insert(copy.size(), other.get(i));
    }

    return copy;
}

//Access Operator (other should be appended to the end of this)
int const & LListInt::operator[](int position) const
{
    return this->get(position);
}

LListInt::Item* LListInt::getNodeAt(int loc) const
{
    Item* temp = head_;

    for(int i=0; i<loc; i++)
    {
        temp = temp->next;
    }

    return temp;
}