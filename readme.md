# UUID Generation (Version 4 & 7)

This repository provides a simple implementation of **UUID Version 4** and **UUID Version 7**, based on [RFC 9562](https://datatracker.ietf.org/doc/rfc9562/) (a draft revision of RFC 4122). **Note** that this code is **not** production-ready and is intended primarily for learning or demonstration.

---

## Overview

1. **`uuid_v4()`**  
   Generates a Version 4 UUID (random-based).

   - Clears the upper 4 bits of byte 6, then sets them to `0x4` (Version 4).
   - Clears the upper 2 bits of byte 8, then sets them to `10` (RFC 4122 variant).

2. **`uuid_v7()`**  
   Generates a Version 7 UUID (time-ordered + randomness).

   - Uses a 48-bit millisecond Unix epoch timestamp (bits 0–47), stored in the first 6 bytes in big-endian order.
   - Sets the version nibble (`0x7`) in byte 6.
   - Sets the variant bits (`10`) in byte 8.

3. **`uuid_to_string(const struct UUID *uuid, char *out)`**  
   Converts the 128-bit UUID (stored in `uuid->bytes`) into a standard UUID string format (`xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx`).

### Important Note

- This code uses **`arc4random_buf`** for randomness, which may not be available on all platforms without extra libraries (e.g., `libbsd` on some Linux systems).
- Replace it with another secure random method (e.g. `getrandom()`, `/dev/urandom`) if needed.

---

## Example Usage

```c
#include "uuid.h"
#include <stdio.h>

int main(void) {
    // Generate a Version 4 UUID
    UUID v4 = uuid_v4();

    // Generate a Version 7 UUID
    UUID v7 = uuid_v7();

    // Convert to string
    char buf[37];  // 36 chars + null terminator

    uuid_to_string(&v4, buf);
    printf("Version 4 UUID: %s\n", buf);

    uuid_to_string(&v7, buf);
    printf("Version 7 UUID: %s\n", buf);

    return 0;
}
```
