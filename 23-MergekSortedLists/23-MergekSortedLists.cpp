// Last updated: 5/17/2025, 7:18:28 PM
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<lists.size();i++){
            ListNode *head= lists[i];
            while(head!=NULL){
                pq.push(head->val);
                head=head->next;
            }
        }
        ListNode *head= new ListNode(-1);
         ListNode *ref=head;
        while(pq.size()>0){
            int data= pq.top();pq.pop();
            ListNode* temp= new ListNode(data);
            head->next=temp;
            head=head->next;
        }
        return ref->next;
    }
};