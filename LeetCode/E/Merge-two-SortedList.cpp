#include <bits/stdc++.h>

using namespace std;

struct ListNode {     
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

    if (!list1) return list2;
    if (!list2) return list1;

    ListNode *ans = (list1->val <= list2->val)? list1 : list2;
    ans->next = (list1->val <= list2->val)? mergeTwoLists(list1->next, list2): mergeTwoLists(list1, list2->next);

    return ans;
}


int main(int argc, char const *argv[])
{
    
    return 0;
}
