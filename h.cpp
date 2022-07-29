#include <stdint.h>
template<size_t dp, char z>
constexpr int32_t DoubleToFixed(double d)
{
  return int32_t(d * double(1 << dp) + (d >= 0 ? 0.5 : -0.5));
}

int main()
{
  constexpr int32_t a = DoubleToFixed<16, 3>(3.5);
  const int z = 5 >> 1;
}