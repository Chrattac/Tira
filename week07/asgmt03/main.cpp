#include "header.h"

int main(){

// a)

    Node *p0 = new Node('1'),
    *p1 = new Node('2');

    p0->next = p1;

    std::cout << "a)\n";
    std::cout << "p0 entry: " << p0->entry << '\n';
    std::cout << "p0 next (address): " << p0->next << '\n';
    std::cout << "p0 next entry: " << p0->next->entry << "\n\n";

    std::cout << "p1 entry:" << p1->entry << '\n';
    std::cout << "p1 address: " << p1 << "\n\n\n";
    delete p0;
    delete p1;

//b)

    Node *q0 = new Node('0'),
    *q1 = new Node('1'),
    *q2 = q1;

    q1->next = q0;

    std::cout << "b)\n";
    std::cout << "q0 entry: " << q0->entry << '\n';
    std::cout << "q0 address: " << q0 << "\n\n";

    std::cout << "q1 address: " << q1 << '\n';
    std::cout << "q2 address: " << q2 << '\n';
    std::cout << "q1 entry: " << q1->entry << '\n';
    std::cout << "q2 entry: " << q2->entry << '\n';
    std::cout << "q1 next: " << q1->next << '\n';
    std::cout << "q2 next: " << q2->next << "\n\n";
    std::cout << "q1 next entry: " << q1->next->entry << '\n';
    std::cout << "q2 next entry: " << q2->next->entry << "\n\n\n"; 

    delete q0;
    delete q1;

//c)

    Node *r0 = new Node('0'),
    *r1 = new Node('1'),
    *r2 = new Node('2');

    r0->next = r1;
    r1->next = r2;
    r2->next = r1;

    std::cout << "c)\n";
    std::cout << "r0 entry: " << r0->entry << '\n';
    std::cout << "r0 next: " << r0->next << '\n';
    std::cout << "r1 entry: " << r1->entry << '\n';
    std::cout << "r1 next: " << r1->next << '\n';
    std::cout << "r2 entry: " << r2->entry << '\n';
    std::cout << "r2 next: " << r2->next << "\n\n";
    std::cout << "r1 address: " << r1 << '\n';
    std::cout << "r2 address: " << r2 << "\n\n";

    delete r0;
    delete r1;
    delete r2;

    return 0;
}