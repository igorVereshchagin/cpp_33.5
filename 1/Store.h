//
// Created by Igor on 21.04.2022.
//

#ifndef INC_1_STORE_H
#define INC_1_STORE_H

#include <map>
#include <iostream>


class Store
{
  std::map<std::string, int> goods;
public:
  Store() : goods() {}
  void fill();
  std::pair<std::string, int> take(const std::string &code, const int count);
  void put(const std::pair<std::string, int> &inGoods);
  friend std::ostream& operator<< (std::ostream& os, Store store)
  {
    for (std::map<std::string, int>::iterator it = store.goods.begin(); it != store.goods.end(); it++)
      os << it->first << " " << it->second << std::endl;
    return os;
  }
};


#endif //INC_1_STORE_H
