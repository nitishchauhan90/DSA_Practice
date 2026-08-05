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
    // void convert(ListNode* l,long long &numb){
    //     if(l==nullptr){
    //         return;
    //     }
    //     ListNode* curr = l;
    //     long long ten =1;
    //     while(curr){
    //         long long val = curr->val*ten;
    //         numb+=val;
    //         ten*=10;
    //         curr= curr->next;
    //     }
    // }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // long long first = 0;
        // long long second = 0;
        // convert(l1,first);
        // convert(l2,second);
        // long long numb = first+second;
        // string s = to_string(numb);
        // int i=s.size()-1;
        // ListNode* nehead = new ListNode(s[i]-'0');
        // i--;
        // ListNode* temp = nehead;
        // while(i>=0){
        //     temp->next=new ListNode(s[i]-'0');
        //     temp=temp->next;
        //     i--;
        // }

        // return nehead;
        ListNode* dummy = new ListNode(0);

        ListNode* tail = dummy;

        int carry = 0;
        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            tail->next = new ListNode(sum % 10);
            tail = tail->next;

        }
        return dummy->next;
    }
};