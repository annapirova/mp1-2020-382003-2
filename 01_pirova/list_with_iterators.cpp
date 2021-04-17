#include <iostream>
#include <list>

using namespace std;

void Print(list<char>& myList)
{
  list<char>::iterator it;
  for(it = myList.begin(); it != myList.end(); it++)
    cout << *it << " ";
  cout << "\n";
}


int main()
{
  list<char> myList, myList2(5);
  
  int n = 10;
  for (int i = 0; i < n / 2; i++)
    myList.push_back('a' + i);
  for (int i = n / 2; i < n ; i++)
    myList.push_front('a' + i);
  // j i h g f a b c d e
  Print(myList);

  myList2.push_back('w');
  myList2.push_back('z');
  myList2.push_back('y');
  // . . . . . w z y
  cout << "myList " << myList.size() << " " << myList.max_size() << "\n";
  cout << "myList2 " << myList2.size() << " " << myList2.max_size() << "\n";

  myList.insert(--myList.end(), 'p');
  Print(myList); // j i h g f a b c d p e
  myList.insert(myList.begin(), 3, 'm'); 
  Print(myList); // m m m j i h g f a b c d p e
  myList.insert(++myList.begin(), --(--myList.end()), myList.end());
  Print(myList); // m p e m m j i h g f a b c d p e

  myList.remove('m');
  Print(myList); // p e j i h g f a b c d p e

  myList2.sort();
  Print(myList2);
  myList.sort();
  Print(myList);

  myList.merge(myList2);
  Print(myList); // . . . . . a b c d e e f g h i j p p w y z

  myList.erase(myList.begin(), ++(++myList.begin()));
  myList.erase(--myList.end(), myList.end());
  Print(myList); // . . . a b c d e e f g h i j p p w y

}