// һ���򵥵�ջʵ��
#include "SimpleStack.h"

// NewStack �½�ջ���ҳ�ʼ��
SimpleStack NewStack() {
    SimpleStack stack = *new SimpleStack;
    stack.length = 0;
    stack.end = NULL;
    return stack;
}

// StackEmpty ջ�Ƿ�Ϊ��
bool StackEmpty(SimpleStack& stack) {
    return stack.length == 0;
}

// ClearStack ���ջ
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

// DestoryStack ����ջ
bool DestoryStack(SimpleStack* stack) {
    ClearStack(*stack);
    delete stack;

    return OK;
}

// Push ��ջ
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

// Pop ��ջ
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