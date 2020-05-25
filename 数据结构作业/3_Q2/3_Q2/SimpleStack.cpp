// 一个简单的栈实现
#include "SimpleStack.h"

// NewStack 新建栈并且初始化
SimpleStack NewStack() {
    SimpleStack stack = *new SimpleStack;
    stack.length = 0;
    stack.end = NULL;
    return stack;
}

// StackEmpty 栈是否为空
bool StackEmpty(SimpleStack& stack) {
    return stack.length == 0;
}

// ClearStack 清空栈
void ClearStack(SimpleStack& stack) {
    if (StackEmpty(stack)) {
        return;
    }

    SimpleStackNode* node = stack.end;
    SimpleStackNode* barkNode;
    do {
        barkNode = node->next;
        delete node;
        node = barkNode;
    } while (node);

    stack.end = NULL;
    stack.length = 0;
}

// DestoryStack 销毁栈
bool DestoryStack(SimpleStack* stack) {
    ClearStack(*stack);
    delete stack;

    return OK;
}

// Push 入栈
bool Push(SimpleStack& stack, ElemType& e){
    SimpleStackNode* node = new SimpleStackNode();
    node->data = e;
    if (StackEmpty(stack)) {
    } else {
        node->next = stack.end;
    }
    stack.end = node;

    stack.length++;
    return OK;
}

// Pop 出栈
bool Pop(SimpleStack& stack, ElemType& e) {
    if (StackEmpty(stack)) {
        return ERROR;
    }

    SimpleStackNode* node = stack.end;
    e = node->data;
    stack.end = node->next;

    stack.length--;
    return OK;
}