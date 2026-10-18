class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * dummy = new ListNode(0);
        ListNode * tmp = dummy;
        ListNode * curr = head;
        stack<ListNode *> st;

        while(curr!=NULL){
            int cnt = 0;
            while(curr!=NULL && cnt<k){
                st.push(curr);
                curr=curr->next;
                cnt++;
            }

            if(cnt==k){
                while(!st.empty()){
                ListNode * tp =st.top();
                st.pop();
                tmp->next = tp;
                tmp = tmp->next;
                }
            }
            else{
                vector<ListNode *> keep;
                while(!st.empty()){
                    keep.push_back(st.top());
                    st.pop();
                }
                for(int i=keep.size()-1;i>=0;i--){
                    tmp->next = keep[i];
                    tmp=tmp->next;
                }
            }
            
        }
        tmp->next = NULL;
        return dummy->next;
    }
};