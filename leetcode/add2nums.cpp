#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *res = new ListNode(0);
    ListNode *i = res;

    int sum, dig, carry = 0;

    while (l1 != nullptr && l2 != nullptr)
    {
        sum = l1->val + l2->val;
        dig = (sum + carry) % 10;
        carry = (sum + carry) / 10;

        i->val = dig;

        if (l1->next != nullptr && l2->next != nullptr)
        {
            ListNode *nextNode = new ListNode(0);
            i->next = nextNode;
            i = nextNode;
        }

        l1 = l1->next;
        l2 = l2->next;
    }

    while (l1 != nullptr)
    {
        sum = (l1->val + carry) % 10;
        carry = (l1->val + carry) / 10;
        ListNode *nextNode = new ListNode(sum);
        i->next = nextNode;
        i = nextNode;

        l1 = l1->next;
    }

    while (l2 != nullptr)
    {
        sum = (l2->val + carry) % 10;
        carry = (l2->val + carry) / 10;
        ListNode *nextNode = new ListNode(sum);
        i->next = nextNode;
        i = nextNode;

        l2 = l2->next;
    }

    if (carry != 0)
    {
        ListNode *nextNode = new ListNode(carry);
        i->next = nextNode;
    }

    return res;
}

int main()
{
}