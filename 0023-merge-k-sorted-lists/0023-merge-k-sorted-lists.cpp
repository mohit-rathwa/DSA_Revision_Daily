class Solution {
public:
    struct compare {
        bool operator()(ListNode * a,ListNode * b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode * dummy = new ListNode(0);
        ListNode * curr = dummy;

        priority_queue<ListNode * , vector<ListNode *> , compare> pq;

        for(auto it : lists){
            if(it) pq.push(it);
        }
        while(!pq.empty()){
            ListNode * tp = pq.top();
            pq.pop();
            dummy->next = tp;
            dummy = dummy->next;
            if(tp->next) pq.push(tp->next);
        }

        return curr->next;
    }
};