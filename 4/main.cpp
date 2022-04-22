#include <iostream>

template<typename T>
void input(T array[8])
{
  std::cout << "Fill the array (8):";
  for (int i = 0; i < 8; ++i)
    std::cin >> array[i];
}

template<typename T>
T mean(T array[8])
{
  T sum = T(0);
  for (int i = 0; i < 8; ++i)
    sum += array[i];
  return sum / T(8);
}


int main()
{
  int arrayInt[8];
  float arrayFloat[8];
  double arrayDouble[8];
  input(arrayInt);
  std::cout << "Mean: " << mean(arrayInt) << std::endl;
  input(arrayFloat);
  std::cout << "Mean: " << mean(arrayFloat) << std::endl;
  input(arrayDouble);
  std::cout << "Mean: " << mean(arrayDouble) << std::endl;
  return 0;
}
