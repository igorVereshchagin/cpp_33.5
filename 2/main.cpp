#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>

class Fish : public std::exception
{

};

class Boot : public std::exception
{

};

int main()
{
  std::exception* pool[9];
  for (int i = 0; i < 9; i++)
      pool[i] = nullptr;

  std::srand(std::time(nullptr));
  pool[std::rand() % 9] = new Fish;
  for (int i = 0; i < 3; i++)
  {
    int r;
    do
      r = std::rand() % 9;
    while (pool[r] != nullptr);
    pool[r] = new Boot;
  }
  int sector;
  int ret = 0;
  bool caught = false;
  Boot bootEx;
  while (!caught)
  {
    do
    {
      std::cout << "input sector (0..8): " << std::endl;
      std::cin >> sector;
    } while (sector > 8 || sector < 0);
    try
    {
      if (pool[sector] != nullptr)
        throw bootEx; //*(pool[sector]);
    }
    catch (const Fish &x)
    {
      std::cout << "Fish" << std::endl;
      caught = true;
      continue;
    }
    catch (const Boot &x)
    {
      std::cout << "Boot" << std::endl;
      ret = -1;
      caught = true;
      continue;
    }
    std::cout << "It's empty, try again" << std::endl;
  }
  for (int i = 0; i < 9; i++)
    if (nullptr != pool[i])
      delete pool[i];
  return ret;
}
