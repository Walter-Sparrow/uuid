#pragma once

#include <cstdint>

struct UUID {
  uint8_t bytes[16];
};

struct UUID uuid_v4();
struct UUID uuid_v7();

void uuid_to_string(const struct UUID *uuid, char *out);
