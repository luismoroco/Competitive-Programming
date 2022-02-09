#include <bits/stdc++.h>

using namespace std;

struct ListNode {     
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
        
    priority_queue<int, vector<int>, greater<int>> dp;

    for (int i = 0; i < lists.size(); ++i) {
        struct ListNode *tmp = lists[i];
        while (tmp) {
            dp.push(tmp -> val);
            tmp = tmp -> next;
        }
    }

    struct ListNode *reco = nullptr;
    struct ListNode *ans = nullptr;

    while (!dp.empty()) {
        struct ListNode *tmp = new ListNode(dp.top());
        dp.pop();
        if (!ans) ans = tmp;
        else {
            reco = ans;
            while (reco -> next != nullptr) { reco = reco -> next;}
            reco -> next = tmp;
        }
    }

    return ans;
}

int main(int argc, char const *argv[]) {

    priority_queue<int> x;
    x.push(1);
    x.push(2);
    x.push(-1);
    x.push(1);

    while (!x.empty()) {
        cout << x.top() << ' '; x.pop();
    }

    
    return 0;
}
