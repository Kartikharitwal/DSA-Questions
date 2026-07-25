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
    ListNode* merge(ListNode* l1,ListNode*l2){
        ListNode* dummy=new ListNode(-1);
        ListNode* tail=dummy;
        while(l1 && l2){
            if(l1->val<=l2->val){
                ListNode* newnode=new ListNode(l1->val);
                tail->next=newnode;
                tail=newnode;
                l1=l1->next;
            }
            else {
                ListNode* newnode=new ListNode(l2->val);
                tail->next=newnode;
                tail=newnode;
                l2=l2->next;
            }
        }
        while(l1){
            ListNode* newnode=new ListNode(l1->val);
            tail->next=newnode;
            tail=newnode;
            l1=l1->next;
        }
        while(l2){
            ListNode* newnode=new ListNode(l2->val);
            tail->next=newnode;
            tail=newnode;
            l2=l2->next;
        }
        return dummy->next;
    }
    ListNode* divide(vector<ListNode*>&lists,int low,int high){
        if(low>high){
            return nullptr;
        }
        if(low==high){
            return lists[low];
        }
        int mid=(low+high)/2;
        ListNode* left=divide(lists,low,mid);
        ListNode* right=divide(lists,mid+1,high);
        return merge(left,right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        int low=0;
        int high=lists.size()-1;
        return divide(lists,0,high);
    }
};