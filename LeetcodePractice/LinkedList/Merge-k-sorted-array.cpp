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
    ListNode*convert(priority_queue<int, vector<int>, greater<int>> a){
        ListNode*aloo=new ListNode(a.top());
        a.pop();
        ListNode*tempp=aloo;
        while(!a.empty()){
            ListNode*temp=new ListNode(a.top());
            a.pop();
            tempp->next=temp;
            tempp=temp;
        }
        return aloo;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(auto i:lists){
            while(i){
                minHeap.push(i->val);
                i=i->next;
            }
        }
        if(minHeap.empty()) return nullptr;
        return convert(minHeap);
    }
};