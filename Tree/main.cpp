#include <iostream>
#include <string>
#include "tree.h"

using namespace std;

int main() {
    Tree t;
    setlocale(LC_ALL, "Russian");

    t.insert(5);
    t.insert(1);
    t.insert(3);
    t.insert(6);
    t.insert(7);
    t.insert(8);

    t.show();

    return 0;
}

