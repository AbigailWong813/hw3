#include "stack.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
    Stack<int> s;
    std::cout << std::boolalpha; 
    cout << "Stack is empty: " << s.empty() << endl;
    cout << "Stack size: " << s.size() << endl;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout << "Stack is empty: " << s.empty() << endl;
    cout << "Stack size: " << s.size() << endl;

    while(!s.empty()){
        cout << "Stack element: " << s.top() << endl;
        s.pop();
    }

    cout << "Stack is empty: " << s.empty() << endl;
    cout << "Stack size: " << s.size() << endl;

    cout << "String stack time" << endl;

    Stack<std::string> t;
    std::cout << std::boolalpha; 
    cout << "Stack is empty: " << t.empty() << endl;
    cout << "Stack size: " << t.size() << endl;
    t.push("One");
    t.push("Two");
    t.push("Three");
    t.push("Four");
    t.push("Five");

    cout << "Stack is empty: " << t.empty() << endl;
    cout << "Stack size: " << t.size() << endl;

    while(!t.empty()){
        cout << "Stack element: " << t.top() << endl;
        t.pop();
    }

    cout << "Stack is empty: " << t.empty() << endl;
    cout << "Stack size: " << t.size() << endl;

    t.pop();

    return 0;

}