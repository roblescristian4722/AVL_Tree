#ifndef AVL_TREE
#define AVL_TREE

#include <iostream>
#include <stdexcept>
#include "vector.h"
using namespace std;

template<typename T>
class AVLTree
{
private:
    struct AVLTreeNode
    {
        T* dataPtr;
        AVLTreeNode* right;
        AVLTreeNode* left;

        AVLTreeNode(const T& data)
        {
            dataPtr = new T(data);
            right = nullptr;
            left = nullptr;
        }
        ~AVLTreeNode()
        {
            delete dataPtr;
            dataPtr = nullptr;
        }
    };
    AVLTreeNode* m_root;

    // MODIFY DATA
    void insertData(const T& data, AVLTreeNode*& node);
    void removeData(const T& data, AVLTreeNode*& node);

    // PARSE
    void parsePreOrder(AVLTreeNode*& node, Vector<T> &vec);
    void parsePostOrder(AVLTreeNode*& node, Vector<T> &vec);
    void parseInOrder(AVLTreeNode*& node, Vector<T> &vec);

    // PROPERTIES
    unsigned int height(AVLTreeNode*& node);

    // AVL PROPERTIES
    void doBalancing(AVLTreeNode*& node);
    unsigned int balanceFactor(AVLTreeNode*& node);

    // AVL ACTIONS
    void simpleLeftRotation(AVLTreeNode*& node);
    void simpleRightRotation(AVLTreeNode*& node);
    void doubleLeftRotation(AVLTreeNode*& node);
    void doubleRightRotation(AVLTreeNode*& node);

public:
    AVLTree() : m_root(nullptr) {}
    ~AVLTree(){}

    // MODIFY DATA
    void insertData(const T& data);
    void removeData(const T& data);

    // PARSE
    void parseInOrder(Vector<T> &vec);
    void parsePreOrder(Vector<T> &vec);
    void parsePostOrder(Vector<T> &vec);

    // PROPERTIES
    bool isLeaf();
    bool isLeaf(AVLTreeNode*& node);
    unsigned int height();
};

/*
 * PRIVATE METHODS
*/
template<typename T>
void AVLTree<T>::insertData(const T& data, AVLTreeNode*& node)
{
    if (node == nullptr)
        node = new AVLTreeNode(data);
    else if (*(node->dataPtr) == data)
        cout << "Data has already been inserted" << endl;
    else if (data < *(node->dataPtr))
        insertData(data, node->left);
    else
        insertData(data, node->right);
    doBalancing(node);
}

template<typename T>
void AVLTree<T>::parseInOrder(AVLTreeNode*& node, Vector<T> &vec)
{
    if (node != nullptr)
    {
        parseInOrder(node->left, vec);
        vec.push_back(*(node->dataPtr));
        parseInOrder(node->right, vec);
    }
}

template<typename T>
void AVLTree<T>::parsePreOrder(AVLTreeNode*& node, Vector<T> &vec)
{
    if (node != nullptr)
    {
        vec.push_back(*(node->dataPtr));
        parsePreOrder(node->left, vec);
        parsePreOrder(node->right, vec);
    }
}

template<typename T>
void AVLTree<T>::parsePostOrder(AVLTreeNode*& node, Vector<T> &vec)
{
    if (node != nullptr)
    {
        parsePostOrder(node->left, vec);
        parsePostOrder(node->right, vec);
        vec.push_back(*(node->dataPtr));
    }
}

template<typename T>
unsigned int AVLTree<T>::height(AVLTreeNode*& node)
{
    if (node == nullptr)
        return 0;
    else if (isLeaf(node))
        return 1;
    int rightHeight = height(node->right);
    int leftHeight = height(node->left);
    return max(rightHeight, leftHeight) + 1;
}

template<typename T>
void AVLTree<T>::doBalancing(AVLTreeNode*& node)
{
    switch (balanceFactor(node))
    {
        case 2:
            if (balanceFactor(node->right) == 1)
                simpleLeftRotation(node);
            else
                doubleLeftRotation(node);
        break;

        case -2:
            if(balanceFactor(node->left) == -1)
                simpleRightRotation(node);
            else
                doubleLeftRotation(node);
        break;
    }
}

template<typename T>
unsigned int AVLTree<T>::balanceFactor(AVLTreeNode*& node)
{
    return height(node->right) - height(node->left);
}

template<typename T>
void AVLTree<T>::simpleLeftRotation(AVLTreeNode*& node)
{
    AVLTreeNode* aux = node->right;
    node->right = aux->left;
    aux->left = node;
    node = aux;
}

template<typename T>
void AVLTree<T>::simpleRightRotation(AVLTreeNode*& node)
{
    AVLTreeNode* aux = node->left;
    node->left = aux->right;
    aux->right = node;
    node = aux;
}

template<typename T>
void AVLTree<T>::doubleLeftRotation(AVLTreeNode*& node)
{
    
}
template<typename T>
void AVLTree<T>::doubleRightRotation(AVLTreeNode*& node)
{
    
}


/*
 * PUBLIC METHODS
*/
template<typename T>
bool AVLTree<T>::isLeaf(AVLTreeNode*& node)
{
    if (node->right == nullptr && node->left == nullptr)
        return true;
    return false;
}

template <typename T>
bool AVLTree<T>::isLeaf()
{
    return isLeaf(m_root);
}

template<typename T>
void AVLTree<T>::insertData(const T& data)
{
    insertData(data, m_root);
}

template<typename T>
void AVLTree<T>::parseInOrder(Vector<T> &vec)
{
    parseInOrder(m_root, vec);
}

template<typename T>
void AVLTree<T>::parsePreOrder(Vector<T> &vec)
{
    parsePreOrder(m_root, vec);
}

template<typename T>
void AVLTree<T>::parsePostOrder(Vector<T> &vec)
{
    parsePostOrder(m_root, vec);
}

template<typename T>
unsigned int AVLTree<T>::height()
{
    return height(m_root);
}

#endif