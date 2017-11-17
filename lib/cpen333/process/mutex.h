/**
 * @file
 * @brief Inter-process shared mutex implementation
 */

#ifndef CPEN333_PROCESS_MUTEX_H
#define CPEN333_PROCESS_MUTEX_H

#include <mutex>  // for locks

#include "cpen333/os.h"
#ifdef WINDOWS
#include "cpen333/process/impl/windows/mutex.h"
#else
#include "impl/posix/mutex.h"
#endif

/**
 * @class cpen333::process::mutex
 * @brief An inter-process mutual exclusion synchronization primitive
 *
 * Used to protect access to a resource shared by multiple processes.  This is an alias to either
 * cpen333::process::posix::mutex or cpen333::process::windows::mutex depending on your platform.
 */

#endif //CPEN333_PROCESS_MUTEX_H
