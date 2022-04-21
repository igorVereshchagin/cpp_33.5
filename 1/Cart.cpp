//
// Created by Igor on 21.04.2022.
//

#include "Cart.h"

std::pair<std::string, int> Cart::take(const std::string &code, const int count)
{
  if (goods.find(code) == goods.end())
    throw std::invalid_argument("Missing article " + code + " in the cart");
  if (goods[code] < count)
    throw std::invalid_argument("Not enough of " + code + " in the cart");
  goods[code] -= count;
  goodsCounter -= count;
  if (0 == goods[code])
    goods.erase(code);
  return std::make_pair(code, count);
}

void Cart::put(const std::pair<std::string, int> &inGoods)
{
  if (goodsCounter + inGoods.second > Cart::capacity)
    throw std::runtime_error("Cart is full");
  if (goods.find(inGoods.first) != goods.end())
    goods[inGoods.first] = inGoods.second;
  else
    goods[inGoods.first] += inGoods.second;
  goodsCounter += inGoods.second;
}
