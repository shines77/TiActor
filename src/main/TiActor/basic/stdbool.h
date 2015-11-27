
#ifndef TIACTOR_BASIC_STDBOOL_H
#define TIACTOR_BASIC_STDBOOL_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#if defined(_MSC_VER) && (_MSC_VER < 1700)
#include "TiActor/basic/msvc/stdbool.h"
#else
#include <stdbool.h>
#endif  /* _MSC_VER */

#endif  /* TIACTOR_BASIC_STDBOOL_H */
