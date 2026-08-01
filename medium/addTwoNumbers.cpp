
typedef struct ListNode {
    int val;
    struct ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, struct ListNode *node) : val(x), next(node) {}
}ListNode;

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

    ListNode *list = new ListNode();
    ListNode *current = list;


    int remainder = 0;
    while (true) {

        int val1 = 0;
        int val2 = 0;

        if (l1 != nullptr) {
            val1 = l1->val;
            l1 = l1->next;
        }

        if (l2 != nullptr) {
            val2 = l2->val;
            l2 = l2->next;
        }

        int res = val1 + val2;
        if (remainder == 1) {
            res++;
            remainder = 0;
        }

        if (res >= 10) {
            remainder = 1;
            res -= 10;
        }

        current->val = res;

        if (l1 == nullptr && l2 == nullptr && remainder == 0) break;
        current->next = new ListNode();
        current = current->next;
    }

    return list;
}
