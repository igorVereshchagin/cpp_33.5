#include <iostream>
#include "Store.h"
#include "Cart.h"

int main()
{
  Store store;
  Cart cart;
  store.fill();
  std::cout << store;
  std::cout.flush();

  std::string cmd;
  do
  {
    std::cin >> cmd;
    try
    {
      if ("add" == cmd)
      {
        std::string code;
        int count;
        std::cin >> code >> count;
        cart.put(store.take(code, count));
      } else if ("rem" == cmd)
      {
        std::string code;
        int count;
        std::cin >> code >> count;
        store.put(cart.take(code, count));
      }
    }
    catch (const std::invalid_argument& x)
    {
      std::cerr << x.what() << std::endl;
    }
    catch (const std::runtime_error& x)
    {
      std::cerr << x.what() << std::endl;
    }
  } while ("exit" != cmd);
  return 0;
}
