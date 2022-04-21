//
// Created by Igor on 21.04.2022.
//

#include <iostream>
#include "Store.h"

void Store::fill()
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
      std::cout << "Article " << inputStr << " have been initialized already" << std::endl;
      continue;
    }
    goods[inputStr] = inputInt;
  }while (inputStr != "end");
}

std::pair<std::string, int> Store::take(const std::string &code, const int count)
{
  if (goods.find(code) == goods.end())
    throw std::invalid_argument("Missing article " + code + " in the store");
  if (goods[code] < count)
    throw std::invalid_argument("Not enough of " + code + " in the store");
  goods[code] -= count;
  return std::make_pair(code, count);
}

void Store::put(const std::pair<std::string, int> &inGoods)
{
  if (goods.find(inGoods.first) == goods.end())
    throw std::runtime_error("Invalid article " + inGoods.first);
  goods[inGoods.first] += inGoods.second;
}
