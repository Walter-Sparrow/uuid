#include "../uuid.h"
#include <cstdio>

int main(void) {
  UUID_v4 uuidv4 = uuid_v4();
  char str[37];
  uuid_to_string(uuidv4.high, uuidv4.low, str);
  printf("V4: %s\n", str);

  UUID_v7 uuidv7 = uuid_v7();
  uuid_to_string(uuidv7.high, uuidv7.low, str);
  printf("V7: %s\n", str);

  return 0;
}
