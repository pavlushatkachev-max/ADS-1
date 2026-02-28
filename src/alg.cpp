// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
#include <iostream>
bool checkPrime(uint64_t value) {
  if (value < 2) {
    return false;
  } else if (value == 2) {
    return true;
  } else if (value % 2 == 0) {
    return false;
  } else {
  for (int i = 3; i * i <= value; ++i) {
      if (value % i == 0)
        return false;
      }
    return true;
  }
}
uint64_t nPrime(uint64_t n) {
  if (n == 0) {
    std::cout << "Error! The number starts with 1." << std::endl;
    return -1;
  } else if (n == 1) {
    return 2;
  } else {
    uint64_t value = 3;
    for (uint64_t i = 2; i < n; ++i) {
      value += 2;
      while (!checkPrime(value)) {
        value += 2;
        }
      }
    return value;
  }
}
uint64_t nextPrime(uint64_t value) {
  if (checkPrime(value)) {
    if (value == 2){
      return 3;
      } else {
      value += 2;
      while (!checkPrime(value)) {
        value += 2;
      }
    }
  } else {
    while (!checkPrime(value)) {
      value++;
    }
  }
  return value;
}
uint64_t sumPrime(const uint64_t hbound) {
  if (hbound <= 2) {
    return 0;
  } else {
    uint64_t sum = 0;
    for (uint64_t i = 2; i < hbound; i = nextPrime(i)) {
      sum += i;
    }
    return sum;
  }
}
uint64_t twinPrimes(uint64_t lbound, const uint64_t hbound) {
  if (hbound < 3) {
    return 0;
  } else if (hbound - lbound < 2) {
    return 0;
  } else {
    uint64_t twin = 0;
    while (lbound < hbound) {
      if (!checkPrime(lbound)) {
        lbound = nextPrime(lbound);
      }
      uint64_t pr = lbound;
      lbound = nextPrime(lbound);
      if (lbound >= hbound)
        break;
      if (lbound - pr == 2)
        twin++;
      }
    return twin;
  }
}
