#include <iostream>
#include "Registry.h"

int main()
{
  Registry<std::string, int> reg1;
  reg1.add("001", 12);
  reg1.add("001", 24);
  reg1.add("001", 36);
  reg1.add("002", 48);
  reg1.print();
  reg1.find("001");

  Registry<double, int> reg2;
  reg2.add(1.001, 1);
  double k = 1.002;
  k *= 10000000000000000000000.0;
  k -= 10000000000000000000.0;
  k /= 10000000000000000000000.0;
  reg2.add(k, 2);
  reg2.add(1.0009999999999999, 3);
  reg2.add(1.0010000000000001, 4);
  reg2.print();


  Registry<int, std::string> reg3;
  reg3.add(1, "Hello");
  reg3.add(1, "world!");
  reg3.add(2, "Lorem");
  reg3.add(3, "ipsum");
  reg3.print();
  reg3.remove(1);
  reg3.print();

  return 0;
}
