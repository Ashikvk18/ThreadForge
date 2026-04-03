// thread_pool.hpp - Declaration of the ThreadPool class
// A thread pool keeps a group of worker threads ready to handle tasks.
// Instead of creating a new thread for every request (slow and wasteful),
// we reuse a fixed number of threads.

#ifndef THREAD_POOL_HPP
#define THREAD_POOL_HPP

class ThreadPool {
public:
    ThreadPool();
    ~ThreadPool();
};

#endif // THREAD_POOL_HPP
