#include "msort.h"
#include <string>
#include <iostream>

using namespace std;

/*template<class t>
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

int main()
{
  Ascend<int> sort1;
  Decend<int> sort2;
  vector<int> intVec;
  intVec.push_back(4);
  intVec.push_back(10);
  intVec.push_back(-2);
  intVec.push_back(38);
  intVec.push_back(0);
  intVec.push_back(4);
  intVec.push_back(7);
  intVec.push_back(-6);

  Ascend<sting> sort3;
  Descend<string> sort4;
  vector<string> stringVec;
  stringVec.push_back("cake");
  stringVec.push_back("oranges");
  stringVec.push_back("peanut");
  stringVec.push_back("pancakes");
  stringVec.push_back("chicken");
  stringVec.push_back("pastas");

  cout << "\nAfter sorting in ascending order it is:" << endl;
  mergeSort(intVec, sort1);
  for (vector<int>::iterator i = intVec.begin(); i != intVec.end(); ++i)
    cout << *i << " ";

  cout << "\nAfter sorting in descending order it is:" << endl;
  mergeSort(intVec, sort2);
  for (vector<int>::iterator i = intVec.begin(); i != intVec.end(); ++i)
    cout << *i << " ";
  cout << endl;

  cout << "\nAfter sorting alphabetically it is:" << endl;
  mergeSort(stringVec, sort3);
  for (vector<string>::iterator i = stringVec.begin(); i != stringVec.end(); ++i)
    cout << *i << " ";

  cout << "\nAfter sorting by size it is:" << endl;
  mergeSort(stringVec, sort4);
  for (vector<string>::iterator i = stringVec.begin(); i != stringVec.end(); ++i)
    cout << *i << " ";
cout << endl;
  return 0;
}*/