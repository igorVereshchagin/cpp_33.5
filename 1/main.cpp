#include <iostream>
#include <map>
#include <exception>

void fillStore(std::map<std::string, int> &goods);

int main()
{
  std::map<std::string, int> goods;
  bool goodInput = false;
  while (!goodInput)
  {
    try
    {
      fillStore(goods);
      goodInput = true;
    }
    catch (const std::invalid_argument &x)
    {
      std::cerr << x.what() << std::endl;
    }
  }

  for (std::map<std::string, int>::iterator it = goods.begin(); it != goods.end(); it++)
    std::cout << it->first << " " << it->second << std::endl;

  return 0;
}

void fillStore(std::map<std::string, int> &goods)
{
  goods.clear();
  std::string inputStr;
  do
  {
    int inputInt;
    std::cin >> inputStr;
    if (inputStr == "end")
      continue;
    std::cin >> inputInt;
    if (goods.find(inputStr) != goods.end())
    {
      std::cout << "article " << inputStr << " have been initialized already" << std::endl;
      continue;
    }
    goods[inputStr] = inputInt;
  }while (inputStr != "end");
}