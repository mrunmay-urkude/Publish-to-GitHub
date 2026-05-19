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
//TC-Nlogn SC - LogN

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

//More optimised to O(Nlogk) tc and sc to logk

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
    struct cmp{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> minHeap;
        for(auto node : lists){
            if(node){
                minHeap.push(node);
            }
        }
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        while(!minHeap.empty()){
            ListNode* smallest = minHeap.top();
            minHeap.pop();
            temp->next = smallest;
            temp = temp->next;
            if(smallest->next){
                minHeap.push(smallest->next);
            }
        }
        return dummy->next;
    }
};