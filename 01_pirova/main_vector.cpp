#include <iostream>
#include <vector>

// http://www.cplusplus.com/reference/vector/vector/
// http://ru.cppreference.com/w/cpp/container/vector

template <class T>
void print(std::vector<T>& v)
{
  for (int i = 0; i < v.size(); i++)
    std::cout << v[i] << " ";
  std::cout << std::endl;
}

template <class T>
void print2(std::vector<T>& v)
{
  std::vector<T>::iterator i;
  for (i = v.begin(); i != v.end(); i++)
    std::cout << *i << " ";
  std::cout << std::endl;
}

int main()
{
  std::vector<char> vec1(5);
  std::vector<int>  vec2(4, 5);
  std::vector<int>  vec3(vec2);
  std::vector<char>::iterator it, it1, it2;
 
  // std::cout << vec1; - нет такой перегрузки
  std::cout << "size "<< vec1.size() << std::endl;

  vec1[0] = 'h';
  vec1[1] = 'e';
  vec1.push_back('l');
  vec1.push_back('l');
  vec1.push_back('o');

  std::cout << vec1.size() << std::endl;
  print<char>(vec1); // h e . . . l l o
  print<int>(vec3);

  it = vec1.begin();
  it1 = it + 1;
  it2 = vec1.end() - 3;
  std::cout << *it1 << " " << *it2 << "\n";

  print2<char>(vec1);

  vec1.erase(++it1, it2);
  print<char>(vec1);

  vec1.insert(vec1.begin()+3, 'S');
  print<char>(vec1);


  return 0;
}

