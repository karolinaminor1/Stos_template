#include "Stack.h"




/*Stack::Stack() {
    m_top = new(nothrow) StackItem;
    if(!m_top) {
        throw StackException(STACK_OVERFLOW);
    }
}

Stack::~Stack() {
    if(!isEmpty()) {
        del();
    }
}


void Stack::push(int k) {                                     
    StackItem* p = new(nothrow) StackItem;
    if(!p) {
        throw StackException(STACK_OVERFLOW);
    }
    *p = StackItem(m_top, k);
    

    m_top = p;
}

bool Stack::isEmpty() {                                     
    return !m_top;
}

int Stack::top() {
    if(!isEmpty())                                          
        return (this->m_top)->m_Item;
    return -1;
}

int Stack::pop() {
    if(!isEmpty()) {
        int k = top();
        del();
        return k;
    }

    throw StackException(STACK_UNDERFLOW);
}


void Stack::del() {
    if(!isEmpty()) {
        StackItem* p = m_top;
        m_top = p->m_pNext;
        delete p;
    }
    else throw StackException(STACK_UNDERFLOW);
}


void Stack::printStack() {
    if(!isEmpty()) {
        StackItem* top = m_top;
        while(top->m_pNext) {
            cout << top->m_Item << endl;
            top = top->m_pNext;
        }
    }
}

*/