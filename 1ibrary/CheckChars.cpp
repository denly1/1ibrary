#include "CheckChars.h"
#include <cstring>

extern "C" CHECKCHARS_API bool containsAllChars(const char* str, const char* chars) {
    for (size_t i = 0; i < strlen(chars); ++i) {
        if (strchr(str, chars[i]) == nullptr) {
            return false;
        }
    }
    return true;
}
