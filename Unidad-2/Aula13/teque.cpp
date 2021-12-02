#include <bits/stdc++.h>
using namespace std;

// https://open.kattis.com/problems/teque

class Node {
    public:
        int data;
        Node* next;
};

class teque {
    private:
        Node* root;
        Node* last;
        Node* front;
        Node* midle;
        int tam;
    public:
        teque()
        {
            root = NULL;
            last = NULL;
            front = NULL;
            midle = NULL;
            tam = 0;
        }

        void push_back(int data) {
            Node* newNode = new Node;
            newNode -> data = data;

            if (root == NULL) 
            {
                root = newNode;
                root -> next = last;
            }
            else
            {
                root -> next = newNode;
            }
        }

};







int main(){

    return EXIT_SUCCESS;
}