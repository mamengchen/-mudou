// 任务队列
#pragma once

#include <queue>
#include <functional>
#include <mutex>
#include <condition_variable>

class TaskQueue {
public:
    using Task = std::function<void()>;

    void push(Task task);
    Task pop();
private:
    std::queue<Task> queue_;
    std::mutex mutex_;
    std::condition_variable cond_;
};