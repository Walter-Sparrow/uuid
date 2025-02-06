#include "uuid.h"
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <sys/time.h>

UUID_v4 uuid_v4() {
  UUID_v4 uuid = {0, 0};
  arc4random_buf(&uuid, sizeof(uuid));

  uuid.high = (uuid.high & 0xFFFFFFFFFFFF0FFF) | (1 << 14);
  uuid.low = (uuid.low >> 2) | ((uint64_t)1 << 63);

  return uuid;
}

struct UUID_v7 uuid_v7() {
  UUID_v7 uuid = {0, 0};
  arc4random_buf(&uuid, sizeof(uuid));

  struct timeval ts;
  gettimeofday(&ts, NULL);
  uint64_t epoch = 1000 * ts.tv_sec + ts.tv_usec / 1000;
  uuid.high =
      (uuid.high & 0x000000000000FFFF) | ((epoch << 16) & 0xFFFFFFFFFFFF0000);

  uuid.high = (uuid.high & 0xFFFFFFFFFFFF0FFF) | (0b0111 << 12);
  uuid.low = (uuid.low >> 2) | ((uint64_t)1 << 63);

  return uuid;
}

void uuid_to_string(uint64_t high, uint64_t low, char *str) {
  snprintf(str, 37, "%08x-%04x-%04x-%04x-%012llx", (uint32_t)(high >> 32),
           (uint16_t)(high >> 16) & 0xFFFF, (uint16_t)(high & 0xFFFF),
           (int)(low >> 48), (uint64_t)(low & 0xFFFFFFFFFFFF));
}
