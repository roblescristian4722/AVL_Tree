#include <iostream>
#include "avl_tree.h"
#include "vector.h"
using namespace std;

int main()
{
    AVLTree<int> tree;
    Vector<int> vec;

    tree.insertData(12);
    tree.insertData(23);
    tree.insertData(34);
    tree.insertData(25);
    tree.insertData(26);

    tree.removeData(26);

    tree.parseInOrder(vec);

    for (size_t i = 0; i < vec.size(); ++i)
        cout << vec[i] << endl;

    cout << endl << tree.height() << endl;

    return 0;
}