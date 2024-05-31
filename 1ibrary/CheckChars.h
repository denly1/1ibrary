#ifndef CHECKCHARS_H
#define CHECKCHARS_H

#ifdef CHECKCHARS_EXPORTS
#define CHECKCHARS_API __declspec(dllexport)
#else
#define CHECKCHARS_API __declspec(dllimport)
#endif

extern "C" CHECKCHARS_API bool containsAllChars(const char* str, const char* chars);

#endif // CHECKCHARS_H
