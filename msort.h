#ifndef MSORT_H
#define MSORT_H

#include <iostream>
#include <vector>

using namespace std;

//Ascend and Descend is used in the DoSorting in the DebuggerWindow
template<class t>
struct Ascend
{
    bool operator()(const t& lhs, const t& rhs) const
    {
        return lhs <= rhs;
    }
};

template<class t>
struct Descend
{
    bool operator()(const t& lhs, const t& rhs) const
    {
        return lhs >= rhs;
    }
};

//allows to change how you want to sort
template <class T, class Comparator>
void mergeSort(vector<T>& myArray, Comparator comp)
{
    vector<T> temp(myArray);
    mergerecurse(myArray, temp, comp, 0, myArray.size()-1);
}

template <class T, class Comparator>
void mergerecurse(vector<T>& myArray, vector<T>& temp, Comparator comp, int start, int end)
{
    if(start >= end)
    {
        return;
    }

    else
    {
        int mid = (start+end)/2;
        //recursive call on first half of myArray
        mergerecurse(myArray, temp, comp, start, mid);
        //recursive call on second half of myArray           
        mergerecurse(myArray, temp, comp, mid+1, end);
        merge(myArray, temp, comp, start, mid+1, end);
    }
}

template <class T, class Comparator>
void merge(vector<T>& myArray, vector<T>& temp, Comparator comp, int start, int mid, int end)
{
    //don't change parameter definitions--set it to an variable
    int start_end = mid-1;
    int temp_pos = start;
    int left = start;
    int right = mid;

    //look at left and right element
    while((left <= start_end) && (right <= end))
    {
        if(comp(myArray[left], myArray[right]))
        {
            temp[temp_pos] = myArray[left];
            temp_pos++;
            left++;
        }
        else
        {
            temp[temp_pos] = myArray[right];
            temp_pos++;
            right++;
        }
    }

    //first half of the list
    while(left <= start_end)
    {
        temp[temp_pos] = myArray[left];
        left++;
        temp_pos++;
    }

    //second half of list
    while(right <= end)
    {
        temp[temp_pos] = myArray[right];
        right++;
        temp_pos++;
    }

    //copy contents into sorted array
    for(int i=start; i<=end; i++)
    {
        myArray[i] = temp[i];
    }
};
#endif