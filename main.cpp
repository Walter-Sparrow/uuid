#include "uuid.h"
#include <cstdio>

int main(void) {
  UUID_v4 uuid = uuid_v4();
  char str[128];
  uuid_v4_to_string(uuid, str);
  printf("%s\n", str);

  return 0;
}
