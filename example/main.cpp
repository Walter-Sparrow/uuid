#include "../uuid.h"
#include <cstdio>

int main(void) {
  UUID uuidv4 = uuid_v4();
  char str[37];
  uuid_to_string(&uuidv4, str);
  printf("V4: %s\n", str);

  UUID uuidv7 = uuid_v7();
  uuid_to_string(&uuidv7, str);
  printf("V7: %s\n", str);

  return 0;
}
