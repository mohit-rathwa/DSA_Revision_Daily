class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * dummy = new ListNode(0);
        ListNode * curr = head;
        ListNode * tmp = dummy;
        stack<ListNode *> st;

        while(curr!=nullptr){
            int cnt = 0;

            while(curr!=NULL && cnt<k){
                cnt++;
                st.push(curr);
                curr = curr->next;
            }

            if(cnt == k){
                while(!st.empty()){
                    ListNode * tp = st.top();
                    st.pop();
                    tmp->next = tp;
                    tmp = tmp->next;
                }
            }
            else{
                vector<ListNode *> vec;
                while(!st.empty()){
                    vec.push_back(st.top());
                    st.pop();
                }
                for(int i = vec.size()-1;i>=0;i--){
                    tmp->next = vec[i];
                    tmp = tmp->next;
                }
            }
        }
        tmp->next = nullptr;
        return dummy->next;
    }
};