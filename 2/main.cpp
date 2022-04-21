#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>

class Fish : public std::exception
{
public:
  const char * what() const noexcept override
  {
    return "Fish";
  }
  virtual ~Fish() {}
};

class Boot : public std::exception
{
public:
  const char * what() const noexcept override
  {
    return "Boot";
  }
  virtual ~Boot() {}
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
  int counter = 0;
  bool caught = false;
  while (!caught && (counter++ < 9))
  {
    do
    {
      std::cout << "input sector (0..8): " << std::endl;
      std::cin >> sector;
    } while (sector > 8 || sector < 0);
    try
    {
      if (pool[sector] != nullptr)
        throw pool[sector];
    }
    catch (const std::exception* const x)
    {
      const Fish* const pFish = dynamic_cast <const Fish* const>(x);
      const Boot* const pBoot = dynamic_cast <const Boot* const>(x);
      if (nullptr != pFish)
      {
        std::cout << pFish->what() << std::endl;
        std::cout << "Number of attempts: " << counter << std::endl;
      }
      else if (nullptr != pBoot)
      {
        std::cout << pBoot->what() << std::endl;
        ret = -1;
      }
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
