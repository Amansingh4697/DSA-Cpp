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
//    ListNode* merge(ListNode* head1,ListNode* head2){
//     ListNode* Dnode = new ListNode(-1);
//     ListNode* temp = Dnode;
//     ListNode* t1 = head1;
//     ListNode* t2 = head2;
//     while(t1 != NULL && t2 != NULL){
//         if(t1->val<t2->val){
//             temp->next = t1;
//             t1 = t1->next;
//         }
//         else{
//             temp->next = t2;
//             t2 = t2->next;
//         }
//         temp = temp->next;
//     }
//     while(t2){
//         temp->next = t2;
//         t2 = t2->next;
//         temp = temp->next;
//     }
//     while(t1){
//         temp->next = t1;
//         t1 = t1->next;
//         temp = temp->next;
//     }
//     return Dnode->next;
//    }
class compare{
    public:
    bool operator()(ListNode* a , ListNode* b){
        return a->val>b->val;
    }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    //    ListNode* mergedlist = nullptr;
    //    for(int i=0;i<lists.size();i++){
    //     mergedlist = merge(mergedlist,lists[i]);
    //    }
    //    return mergedlist;
    priority_queue<ListNode*, vector<ListNode*> ,compare> pq;
    ListNode* Dnode = new ListNode(-1);
    ListNode* temp = Dnode;
    // step1 saree list ka first Node insert krdo
    for(int i = 0;i<lists.size();i++){
        if(lists[i] != NULL){
          pq.push(lists[i]);
        }   
    }
    // step2 top element ko push kro go to next Node if exist;
    while(pq.size()>0){
     ListNode* newNode = pq.top();
     temp->next = newNode;
     temp = temp->next;
     pq.pop();
     if(newNode->next != NULL){
        pq.push(newNode->next);
     }
    }
    temp->next = NULL;
    return Dnode->next;
    }
};
