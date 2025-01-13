// 任务队列
#include "task_queue.h"

void TaskQueue::push(Task task) {
    {
        std::lock_guard<std::mutex> lock(mutex_);
        queue_.push(std::move(task));
    }
    cond_.notify_one();
}

TaskQueue::Task TaskQueue::pop() {
    std::unique_lock<std::mutex> lock(mutex_);
    cond_.wait(lock,[this]{return !queue_.empty();});
    Task task = std::move(queue_.front());
    queue_.pop();
    return task;
}