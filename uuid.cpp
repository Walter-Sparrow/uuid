#include "uuid.h"
#include <cstdint>
#include <cstdio>
#include <cstdlib>

UUID_v4 uuid_v4() {
  UUID_v4 uuid = {0, 0};
  arc4random_buf(&uuid, sizeof(uuid));

  uuid.high = (uuid.high & 0xFFFFFFFFFFFF0FFF) | 4;
  uuid.low = (uuid.low & 0xFFFFFFFFFFFFFFF) | 2;

  return uuid;
}

void uuid_v4_to_string(UUID_v4 uuid, char *str) {
  snprintf(str, 37, "%08x-%04x-%04x-%04x-%012llx", (uint32_t)(uuid.high >> 32),
           (uint16_t)(uuid.high >> 16) & 0xFFFF, (uint16_t)(uuid.high & 0xFFFF),
           (int)(uuid.low >> 48), (uint64_t)(uuid.low & 0xFFFFFFFFFFFF));
}
