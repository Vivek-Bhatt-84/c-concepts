#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct ListNode{
  int val ;
  ListNode* next;
  ListNode(int v) : val(v) , next(NULL) {}
};

class Solution{
 public:
 ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<pair<int,ListNode*> , vector<pair<int,ListNode*>> , greater<pair<int,ListNode*>>> pq;

    for(int i = 0 ; i < lists.size() ; i++){
        if(lists[i]){
            pq.push({lists[i] -> val , lists[i]});
        }
    }

    ListNode* dummy = new ListNode(-1);
    ListNode* tmp = dummy;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        if(it.second -> next){
            pq.push({it.second->next->val , it.second->next});
        }
        tmp -> next = it.second;
        tmp = tmp -> next;
    }

    return dummy -> next;
    
}
    //  ListNode* mergeKLists(vector<ListNode*>& lists) {
    //     vector<int> res;
    //     for(int i = 0 ; i < lists.size() ; i++){
    //         ListNode* tmp  = lists[i];
    //         while(tmp != NULL){
    //             res.push_back(tmp -> val);
    //             tmp = tmp -> next;
    //         }
    //     }
    //     sort(res.begin() , res.end());
        
    //     if(res.empty()) return NULL;
        
    //         ListNode* head = new ListNode(res[0]);
    //         ListNode* curr = head;
            
    //         for(int i = 1 ; i < res.size() ; i++){
    //             curr -> next = new ListNode(res[i]);
    //             curr = curr -> next;
    //         }
            
    //         return head;
    //  }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

ListNode* createList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (int i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

int main()
{
    Solution sol;
   vector<ListNode*> lists;
   
   lists.push_back(createList({1,4,5}));
   lists.push_back(createList({1, 3, 4}));
    lists.push_back(createList({2, 6}));
    
    ListNode* mergedList = sol.mergeKLists(lists);
     cout << "Merged List: ";
    printList(mergedList);
    
    return 0;
}