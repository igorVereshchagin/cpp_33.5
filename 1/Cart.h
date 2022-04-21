//
// Created by Igor on 21.04.2022.
//

#ifndef INC_1_CART_H
#define INC_1_CART_H

#include <map>

class Cart
{
  std::map<std::string, int> goods;
  int goodsCounter;
  static const int capacity = 100;

public:
  Cart() : goods(), goodsCounter(0) {}
  std::pair<std::string, int> take(const std::string &code, const int count);
  void put(const std::pair<std::string, int> &inGoods);
};


#endif //INC_1_CART_H
