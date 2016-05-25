#include <iostream>
#include <list>
#include <unordered_set>
#include <complex>
#include "concepts.h"

using namespace Concepts;
using namespace std;

Common{...Args} void common(Args... args) {}

Compatible{A, B} void compatible(A,B){}

Incrementable{I} void incr(I){}

#define PRINT(...) std::cout << #__VA_ARGS__ ":\t" << __VA_ARGS__ << std::endl

struct Foo{};

int main() {
  common(3, std::complex<double>());
  compatible(3, 3.0f);
  std::cout << std::boolalpha;
  PRINT(Incrementable<int>);
  PRINT(Bitmask<int>);
  PRINT(Bitmask<float>);
  PRINT(ShiftableBitmask<int>);
  PRINT(Ordered<int, float>);
  PRINT(Ordered<complex<float>>);
  PRINT(Arithmetic<int>);
  PRINT(Arithmetic<complex<float>>);
  PRINT(CompatibleArithmetic<complex<float>, float>);
  PRINT(CompatibleArithmetic<float, complex<float>>);
  PRINT(Swappable<int>);
  PRINT(ValueSwappable<int*>);
  PRINT(RandomAccessIterator<int*>);
  PRINT(BidirectionnalIterator<list<int>::iterator>);
  PRINT(RandomAccessIterator<list<int>::iterator>);
  PRINT(ForwardIterator<unordered_set<int>::iterator>);
  PRINT(BidirectionnalIterator<unordered_set<int>::iterator>);
  PRINT(ReversibleContainer<list<int>>);
  PRINT(Container<unordered_set<int>>);
  PRINT(ReversibleContainer<unordered_set<int>>);
  PRINT(Container<int[]>);
  PRINT(Allocator<allocator<int>>);
  return 0;
}
