#pragma once

#include <cstdint>
struct UUID_v4 {
  uint64_t high;
  uint64_t low;
};

struct UUID_v4 uuid_v4();
void uuid_v4_to_string(UUID_v4 uuid, char *str);
