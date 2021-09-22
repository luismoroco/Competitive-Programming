#include <bits/stdc++.h>

/*
* Aquí generamos un array que nos dirá si existe o no un elemento en el array
* Si no existe se agrega, si no retornamos 0 así evitamos duplicados
*/

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
        dyna = new bool[1000];
        for (size_t i = 0; i < 1000; ++i)
            dyna[i] = false;
    }

    void insert(int data)
    {
        //delete duplicates
        if (dyna[data] == true)
            return;
        else
        {
            //crear nodo
            Node *new_node = new Node;
            dyna[data] = true;

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
    list a;
    a.insert(5);
    a.insert(6);
    a.insert(7);
    a.print();

    puts("agregando duplicado '6' ");
    a.insert(6);
    a.print();

    return 0;
}
