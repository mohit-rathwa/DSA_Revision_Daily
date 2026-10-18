class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || k<=1){
            return head;
        }
        ListNode * tmp = head;
        for(int i=0;i<k;i++){
            if(tmp==NULL) return head;
            tmp = tmp->next;
        }

        ListNode * curr = head;
        ListNode * prev = NULL;

        for(int i=0;i<k;i++){
            ListNode * nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        head->next = reverseKGroup(curr , k);

        return prev ;
    }
};