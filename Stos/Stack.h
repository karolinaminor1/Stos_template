#pragma once
using namespace std;
#include <iostream>

typedef unsigned short int USINT;
#define STACK_OVERFLOW 0X001
#define STACK_UNDERFLOW 0x002
#define OTHER_ERROR 0x000


class StackException {
public:
	StackException( USINT errorCode = OTHER_ERROR ) { m_Error = errorCode; }
	const char* getReason();
private:
	USINT m_Error;
};

inline const char* StackException::getReason()
{
	switch( m_Error )
	{
	case STACK_OVERFLOW: return "Stack overflow!\n";
	case STACK_UNDERFLOW: return "Stack underflow!\n";
	default: return "Other stack error!\n";
	}
}



template <class T> class StackItem {													
private:

	StackItem() {
		m_Item;
		m_pNext = NULL;
	}

	StackItem(StackItem* s, T x) {

		m_pNext = new(nothrow) StackItem;
		if(!m_pNext) {
			throw StackException(STACK_OVERFLOW);
		}
		m_pNext = s;
		m_Item = x;
	}

	template <class T> friend class Stack;

	T m_Item;
	StackItem<T>* m_pNext;
};



template <class T> class Stack
{
public:
	Stack();
	virtual ~Stack();

	bool isEmpty();
	void push(T);
	T top();
	T pop();
	void del();

	void printStack();


private:
	StackItem<T>* m_top;
};


template <class T>  Stack<T>::Stack() 
{
	m_top = new( nothrow ) StackItem<T>;
	if( !m_top ) {
		throw StackException( STACK_OVERFLOW  );
	}
}


template <class T> Stack<T>::~Stack() {
	if( !isEmpty() ) {
		del();
	}
}


template <class T> void Stack<T>::push(T k) {                                     
	StackItem<T>* p = new( nothrow ) StackItem<T>;
	if( !p ) {
		throw StackException( STACK_OVERFLOW );
	}
	*p = StackItem<T>( m_top, k );


	m_top = p;
}


template <class T> bool Stack<T>::isEmpty() {                                     
	return !m_top;
};


template <class T> T Stack<T>::top() {
	if( !isEmpty() )                                          
		return ( this->m_top )->m_Item;
	else throw StackException(STACK_UNDERFLOW);
};


template <class T> T Stack<T>::pop() {
	if( !isEmpty() ) {
		T k = top();
		del();
		return k;
	}

	throw StackException( STACK_UNDERFLOW );
}


template <class T> void Stack<T>:: del() {
	if( !isEmpty() ) {
		StackItem<T>* p = m_top;
		m_top = p->m_pNext;
		delete p;
	}
	else throw StackException( STACK_UNDERFLOW );
}


template <class T> void Stack<T>::printStack() {
	if( !isEmpty() ) {
		StackItem<T>* top = m_top;
		while( top->m_pNext ) {
			cout << top->m_Item << endl;
			top = top->m_pNext;
		}
	}
}





/*class StackItem {													//wszystko as int
private:

	StackItem() {
		m_pNext = NULL;
		m_Item = 0;
	}

	StackItem(StackItem* s, int x) {
	
		m_pNext = new(nothrow) StackItem;
		if(!m_pNext) {
			throw StackException(STACK_OVERFLOW);
		}
		m_pNext = s;
		m_Item = x;
	}

	friend class Stack;

	int m_Item;
	StackItem* m_pNext;
};


class Stack 
{
public:
	Stack();
	virtual ~Stack();

	bool isEmpty();
	void push(int);
	int top();
	int pop();
	void del();

	void printStack();


private:
	StackItem* m_top;													//wskaznik na element na szczycie stosu
};

*/