#pragma once

#include <cstdint>

struct UUID_v4 {
  uint64_t high;
  uint64_t low;
};

struct UUID_v4 uuid_v4();

struct UUID_v7 {
  uint64_t high;
  uint64_t low;
};

struct UUID_v7 uuid_v7();

void uuid_to_string(uint64_t high, uint64_t low, char *str);
