#include <bits/stdc++.h>

// Aquí el arbol dse balancea cada que se insertan nodos 

class Node
{
    friend class BST;

private:
    int data;
    short int ht;

public:
    Node *left, *right;
    Node(const int tmp, Node *lf, Node *rt, short int h = 0)
        : data{tmp}, left{lf}, right{rt}, ht{h} {}
    void setdata(const int data) { this->data = data; }
    void setht(int ht) { this->ht = ht; }
    int getdata() const { return data; }
    int getht() const { return ht; }
};

class BST
{
private:
    Node *root;

public:
    //building
    BST() { root = nullptr; }

    //inserting function
    bool isrtrec(Node *&node, const int data)
    {
        if (!node)
        {
            std::cout << "inserting:" << data << std::endl;
            node = new Node(data, nullptr, nullptr);
        }
        else if (data == node->getdata())
        {
            std::cout << "Value already exist!:" << data << std::endl;
            return false;
        }
        else if (data < node->getdata())
            isrtrec(node->left, data);
        else if (data > node->getdata())
            isrtrec(node->right, data);
        return true;
    }

    void insert(int data)
    {
        isrtrec(root, data);
        balanceNode(root);
    }

    int high(Node *node) const { return node == nullptr ? -1 : node->getht(); }

    //balancing function
    Node *balanceNode(Node *&node)
    {
        if (balanceFactor(node) > 1)
        {
            if (balanceFactor(node->left) > 0)
                node = rotateLL(node);
            else
                node = rotateLR(node);
        }
        else if (balanceFactor(node) < -1)
        {
            if (balanceFactor(node->right) > 0)
                node = rotateRL(node);
            else
                node = rotateRR(node);
        }
        return node;
    }

    Node *rotateLL(Node *node)
    {
        Node *tempNode = node->left;
        node->left = tempNode->right;
        tempNode->right = node;
        return tempNode;
    }

    Node *rotateLR(Node *node)
    {
        Node *tempNode = node->left;
        node->left = rotateRR(tempNode);
        return rotateLL(node);
    }

    Node *rotateRL(Node *node)
    {
        Node *tempNode = node->right;
        node->right = rotateLL(tempNode);
        return rotateRR(node);
    }

    Node *rotateRR(Node *node)
    {
        Node *tempNode = node->right;
        node->right = tempNode->left;
        tempNode->left = node;
        return tempNode;
    }

    int balanceFactor(Node *&node) const
    {
        int leftHeight = node->left ? high(node->left) : 0;
        int rightHeight = node->right ? high(node->right) : 0;
        return (leftHeight - rightHeight);
    }
    //end balancing

    //display function with types on vectors
    std::vector<int> preOrden(std::vector<int> &a, Node *tmp) const
    {
        if (tmp != NULL)
        { //root, left, right
            a.push_back(tmp->getdata());
            std::cout << tmp->getdata() << " ";
            preOrden(a, tmp->left);
            preOrden(a, tmp->right);
        }
        return a;
    }

    void show()
    {
        std::vector<int> a;
        preOrden(a, root);
        std::cout << std::endl;
    }
};

int main()
{
    BST abb;
    std::vector<int> a = {6, 2, 1, 9, 12, 11, 34, 5, 8};
    for (auto i : a) abb.insert(i);

    abb.show();

    return 0;
}