#include <bits/stdc++.h>

using namespace std;

struct ListNode {     
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    string a, b;
    ListNode *tmp1 = l1, *tmp2 = l2; 
    while (tmp1->next != nullptr && tmp2->next != nullptr){
        a.push_back(static_cast<char>(tmp1->val));
        b.push_back(static_cast<char>(tmp2->val));
        tmp1 = tmp1->next; tmp2 = tmp2 -> next;
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int num = stoi(a) + stoi(b);
    string fin = to_string(num);
    reverse(fin.begin(), fin.end());

    ListNode * NewList = new ListNode(fin[0]);
    for (int i = 1; i < fin.length(); ++i){
        ListNode *tmp = new ListNode(fin[i]);
        NewList->next = tmp2;
    }
    return NewList;    
}


int main(int argc, char const *argv[])
{
    return 0;
}
