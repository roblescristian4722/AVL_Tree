#include <iostream>
#include "avl_tree.h"
#include "vector.h"
using namespace std;

int main()
{
    AVLTree<int> tree;
    Vector<int> vec;
    tree.insertData(50);
    tree.insertData(20);
    tree.insertData(18);
    tree.insertData(19);
    tree.insertData(60);
    tree.parseInOrder(vec);
    for (size_t i = 0; i < vec.size(); ++i)
        cout << vec[i] << endl;

    cout << endl << tree.height() << endl;
    return 0;
}