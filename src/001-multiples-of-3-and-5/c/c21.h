#include <stdbool.h>
#include <inttypes.h>
#pragma once

typedef int8_t   i8;
typedef uint8_t  u8;
typedef int16_t  i16;
typedef uint16_t u16;
typedef int32_t  i32;
typedef uint32_t u32;
typedef int64_t  i64;
typedef uint64_t u64;

#define var __auto_type
#define let __auto_type const

#define care __attribute__((warn_unused_result))
#define defer(x) __attribute__((cleanup(x)))

#define forcount(index, count)                                \
  for(size_t index = 0, size = count; index < size; ++index)

#define foruntil(index, end, array)                     \
  for(size_t index = 0; (array)[index] != end; ++index)

#define forrange(index, start, end)                             \
  for(size_t index = start, stop = end; index != stop; ++index)
