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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head || head->next==nullptr || head->next->next==nullptr){
            return {-1,-1};
        }
        vector<int>ans;
        ListNode *prev=head;
        ListNode *curr=head->next;
        int cnt=1;
        while(curr->next){
            ListNode *nextnode=curr->next;
            if((curr->val>prev->val && curr->val>nextnode->val) || (curr->val <prev->val && curr->val<nextnode->val)){
                ans.push_back(cnt);
            }
            cnt++;
            prev=curr;
            curr=nextnode;
            
        }
        int n=ans.size();
        if(n<=1){
            return {-1,-1};
        }
        int mini=INT_MAX;
        int maxi=ans[n-1]-ans[0];
        for(int i=1;i<n;i++){
            mini=min(mini,ans[i]-ans[i-1]);

        }
        return {mini,maxi};
        

        
    }
};