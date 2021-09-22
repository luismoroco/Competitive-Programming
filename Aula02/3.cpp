#include <bits/stdc++.h>

struct Node
{
    int data;
    Node *next;
};

class list
{
private:
    Node *root;
    bool *dyna;

public:
    list()
    {
        root = NULL;
    }

    void insert(int data)
    {
        //crear nodo
        Node *new_node = new Node;

        //actualizar info
        new_node->data = data;
        new_node->next = NULL;

        //modificar punteros
        if (root == NULL)
            root = new_node;
        else
        {
            Node *tmp = root;
            while (tmp->next != NULL)
                tmp = tmp->next;

            tmp->next = new_node;
        }
    }

    int obtainreverse()
    {
        std::vector<int> rvs;
        Node *tmp = root;
        while (tmp)
        {
            rvs.push_back(tmp->data);
            tmp = tmp->next;
        }

        std::reverse(rvs.begin(), rvs.end());
        int d = 1;
        int total = 0;
        for (auto &it : rvs)
        {
            total += it * d;
            d *= 10;
        }

        return total;
    }

    void print()
    {
        Node *tmp = root;
        while (tmp)
        {
            std::cout << tmp->data << " -> ";
            tmp = tmp->next;
        }
        std::cout << " NULL " << std::endl;
    }
};

int main()
{

    list adj1, adj2;

    //(315)-> 513
    adj1.insert(3);
    adj1.insert(1);
    adj1.insert(5);

    //(592)-> 295
    adj2.insert(5);
    adj2.insert(9);
    adj2.insert(2);

    std::cout << adj1.obtainreverse() + adj2.obtainreverse();

    return 0;
}
