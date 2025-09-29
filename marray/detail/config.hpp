#ifndef MARRAY_CONFIG_HPP
#define MARRAY_CONFIG_HPP

#include <cassert>

#ifndef MARRAY_DEBUG
#ifndef NDEBUG
#define MARRAY_DEBUG 1
#else
#define MARRAY_DEBUG 0
#endif
#endif

#ifndef MARRAY_ASSERT
#if MARRAY_DEBUG
#define MARRAY_ASSERT(e) assert(e)
#else
#define MARRAY_ASSERT(e) ((void)0)
#endif
#endif

#define MARRAY_LIKELY(x) __builtin_expect((x),1)
#define MARRAY_UNLIKELY(x) __builtin_expect((x),0)

#endif //MARRAY_CONFIG_HPP

