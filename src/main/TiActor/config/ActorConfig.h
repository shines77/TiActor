
#ifndef TIACTOR_CONFIG_ACTORCONFIG_H
#define TIACTOR_CONFIG_ACTORCONFIG_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#define MESSAGE_QUEUE_USE_RINGQUEUE     0
#define MESSAGE_QUEUE_USE_STL           1

#ifdef MESSAGE_QUEUE_MODE
#undef MESSAGE_QUEUE_MODE
#endif
#define MESSAGE_QUEUE_MODE              MESSAGE_QUEUE_USE_RINGQUEUE

#endif  /* TIACTOR_CONFIG_ACTORCONFIG_H */
