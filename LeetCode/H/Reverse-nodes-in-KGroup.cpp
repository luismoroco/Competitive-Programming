#include <bits/stdc++.h>

using namespace std;

struct ListNode {     
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* reverseKGroup(ListNode* head, int k) {

    if (!head || k < 2) return head;

    int tam = 0;
    ListNode *c = head; 
    while (head) { ++tam; head = head -> next;}

    


}




int main(int argc, char const *argv[]) {
    
    return 0;
}
