// N. Adhikary submitted at Oct 15, 2025 00:47 Runtime 0ms Beats 100.00% Memory 77.09MB Beats 74.70%
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    /*
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr)
        {
            ListNode* next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }*/
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    { 
        ListNode dummy;
        ListNode* curr = &dummy;
        int c = 0;
        while(l1||l2||c)
        {
            int sum = c;
            if (l1)
            {
                sum += l1 -> val;
                l1 = l1 -> next;
            }
            if (l2)
            {
                sum += l2 -> val;
                l2 = l2 -> next;
            }

            curr -> next = new ListNode(sum % 10);
            curr = curr -> next;
            c = sum / 10;
        }
        return dummy.next;

    }
};
