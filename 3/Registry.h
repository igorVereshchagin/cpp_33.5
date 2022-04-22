//
// Created by Igor on 22.04.2022.
//

#ifndef INC_3_REGISTRY_H
#define INC_3_REGISTRY_H

#include <map>
#include <vector>
#include <iostream>

template<typename T1, typename T2> class Registry
{
  std::map<T1, std::vector<T2>> registryMap;
public:
  void add(const T1 &key, const T2 &val)
  {
    if (registryMap.find(key) == registryMap.end())
      registryMap.insert(std::make_pair(key, std::vector<T2>({val})));
    else
      registryMap[key].push_back(val);
  }
  void remove(const T1 &key)
  {
    if (registryMap.find(key) != registryMap.end())
      registryMap.erase(key);
  }

  void print()
  {
    for (typename std::map<T1, std::vector<T2>>::iterator it = registryMap.begin(); it != registryMap.end(); it++)
    {
      std::cout << it->first << ": ";
      for (int i = 0; i < it->second.size(); i++)
        std::cout << it->second[i] << " ";
      std::cout << std::endl;
    }
  }
  void find(const T1 &key)
  {
    std::cout << "Searching " << key << std::endl;
    typename std::map<T1, std::vector<T2>>::iterator it = registryMap.find(key);
    if (it != registryMap.end())
    {
      std::cout << it->first << ": ";
      for (int i = 0; i < it->second.size(); i++)
        std::cout << it->second[i] << " ";
      std::cout << std::endl;
    }
  }
};


#endif //INC_3_REGISTRY_H
