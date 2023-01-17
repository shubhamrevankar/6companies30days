//1171. Remove Zero Sum Consecutive Nodes from Linked List
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int,ListNode*> m;
        int sum=0;
        ListNode* start = new ListNode(10000);
        
        start->next = head;
        bool flag = true;
        while(flag){
            flag=false;
            m.clear();sum=0;
            m[0] = start;
            ListNode* cur = start->next;
            while(cur!=NULL){
                sum+=cur->val;
                if(m[sum]!=NULL){
                    m[sum]->next = cur->next;
                    flag=true;
                }
                else{
                    m[sum] = cur;
                }
                cur = cur->next;
            }
        }
        
        return start->next;
    }
};