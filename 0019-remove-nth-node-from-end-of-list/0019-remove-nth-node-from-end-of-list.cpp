class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * curr = head;
        int  len = 0;
        while(curr!=NULL){
            len++;
            curr = curr->next;
        }

        ListNode * dummy = new ListNode(0);
        dummy->next = head;
        ListNode * prev = dummy;

        for(int i=0;i<(len-n);i++){
            prev = prev->next;
        }

        prev->next = prev->next->next;

        return dummy->next;
    }
};