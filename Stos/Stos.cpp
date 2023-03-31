
#include"Stack.h"
#include <iostream>
using namespace std;
int main()
{


    cout << "---------- char: ----------" << endl;
    Stack<char> stos;
    stos.push('c');
    stos.push('%');
    stos.push('?');
    stos.push('8');

    stos.printStack();


    cout << "-------- stos string: --------" << endl;
    Stack<string> stos1;
    stos1.push("blablabla");
    stos1.push("<3 <3 <3");
    stos1.push(":(");
    stos1.push("abcdwdaa");
   
    stos1.printStack();


    cout << "---------- stos int: ----------" << endl;
    Stack<int> stos2;
    stos2.push(66);
    stos2.push(129);
    stos2.push(12);
    stos2.push(21);

    stos2.printStack();

    cout << "-------- stos double: --------" << endl;
    Stack<double> stos3;
    stos3.push(9.8);
    stos3.push(0.777);
    stos3.push(69.147);
    stos3.push(1.21);

    stos3.printStack();
 
    
    
    return 0;
}

