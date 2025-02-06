#include "uuid.h"
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <sys/time.h>

UUID uuid_v4() {
  UUID uuid;
  arc4random_buf(&uuid.bytes, sizeof(uuid));

  uuid.bytes[6] = (uuid.bytes[6] & 0x0F) | 0x40;
  uuid.bytes[8] = (uuid.bytes[6] & 0x3F) | 0x80;

  return uuid;
}

UUID uuid_v7() {
  UUID uuid;
  arc4random_buf(&uuid.bytes, sizeof(uuid));

  struct timeval ts;
  gettimeofday(&ts, NULL);
  uint64_t epoch = 1000 * ts.tv_sec + ts.tv_usec / 1000;
  epoch &= 0xFFFFFFFFFFFF;

  for (int i = 0; i <= 5; i++) {
    uuid.bytes[i] = (epoch >> 8 * (5 - i)) & 0xFF;
  }

  uuid.bytes[6] = (uuid.bytes[6] & 0x0F) | 0x70;
  uuid.bytes[8] = (uuid.bytes[6] & 0x3F) | 0x80;

  return uuid;
}

void uuid_to_string(const struct UUID *uuid, char *out) {
  snprintf(
      out, 37,
      "%02x%02x%02x%02x-%02x%02x-%02x%02x-%02x%02x-%02x%02x%02x%02x%02x%02x",
      uuid->bytes[0], uuid->bytes[1], uuid->bytes[2], uuid->bytes[3],
      uuid->bytes[4], uuid->bytes[5], uuid->bytes[6], uuid->bytes[7],
      uuid->bytes[8], uuid->bytes[9], uuid->bytes[10], uuid->bytes[11],
      uuid->bytes[12], uuid->bytes[13], uuid->bytes[14], uuid->bytes[15]);
}
