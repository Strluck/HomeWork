#include "ArrayQueue.h"

// NewQueue 初始化队列
ArrayQueue NewQueue(int len) {
    ArrayQueue queue = *new ArrayQueue;
    queue.front = 0;
    queue.rear = 0;
    return queue;
}

// EnQueue 入队
bool EnQueue(ArrayQueue& queue, ElemType& e) {
    // 判断队列是否已满
    if (queue.front - 1 == queue.rear || (queue.front - 1 == 0 && queue.rear == M - 1)) {
        return ERROR;
    }

    if (++queue.rear == M) {
        queue.rear = 0;
    }
    
    queue.array[queue.rear] = e;
    return OK;
}

// DeQueue 出队
bool DeQueue(ArrayQueue& queue, ElemType& e) {
    // 判断队列是空
    if (queue.front == queue.rear) {
        return ERROR;
    }

    if (++queue.front == M) {
        queue.front = 0;
    }

    e = queue.array[queue.front];
    return OK;
}