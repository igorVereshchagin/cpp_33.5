#include <iostream>
#include <map>
#include <vector>

template<typename T1, typename T2> class Registry : public std::map<T1, std::vector<T2>>
{

};

int main()
{
  Registry<std::string, int> reg1;
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
