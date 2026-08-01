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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr){
            return head;
        }
        int count =0;
        ListNode* curr = head;
        while(curr!=nullptr){
            count++;
            curr= curr->next;
        }
        int valfromfront = count-n;
        if (valfromfront == 0) {
            return head->next;
        }
        ListNode* curr2 = head;
        int count2 = 1;
        while(count2<valfromfront){
            count2++;
            curr2=curr2->next;
        }
        ListNode* del = curr2->next;
        ListNode* nxt = del->next;
        curr2->next = nxt;
        return head;

    }
};