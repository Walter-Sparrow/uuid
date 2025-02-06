# UUID Generation (Version 4 & 7)

This repository contains a simple implementation of **UUID Version 4** and **UUID Version 7**, referencing [RFC 9562](https://datatracker.ietf.org/doc/rfc9562/) (a draft revision of RFC 4122). **Note** that this code is **not production-ready** and is provided primarily for demonstration and educational purposes.

---

## Overview

- **`UUID_v4`**: Generates a Version 4 UUID, which is purely random aside from the mandatory bits for version (4) and variant (`10`).
- **`UUID_v7`**: Generates a Version 7 UUID, which includes a millisecond timestamp in part of the 128-bit space, following RFC 9562 guidelines for storing a 48-bit timestamp. It also sets the version to 7 and the variant bits to `10`.

### Important Caveats

1. **Draft / Non-Final**  
   The Version 7 specification is still in draft form (referred to here as _RFC 9562_). It may change before final publication. This implementation attempts to follow the draft, but future revisions could differ in format or bit layout.

2. **Not Production-Ready**  
   This code has not been thoroughly tested or audited. Use at your own risk. If you need cryptographic-grade UUID generation, consider using a well-reviewed library.

3. **Portability**  
   The code uses `arc4random_buf` for randomness, which is not available on all platforms without additional libraries (e.g., `libbsd` on some Linux systems). If you require broader compatibility, you can replace `arc4random_buf` with another secure source, such as `getrandom()` or `/dev/urandom`.

---

## Usage Example

```c
#include "uuid.h"
#include <stdio.h>

int main(void) {
    UUID_v4 v4 = uuid_v4();
    UUID_v7 v7 = uuid_v7();

    char buffer[37];  // 36 characters + null terminator

    uuid_to_string(v4.high, v4.low, buffer);
    printf("Version 4 UUID: %s\n", buffer);

    uuid_to_string(v7.high, v7.low, buffer);
    printf("Version 7 UUID: %s\n", buffer);

    return 0;
}
```
