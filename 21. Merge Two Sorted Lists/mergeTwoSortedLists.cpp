 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            //dummy acts as the latest node added to merged list.
            //head maintains first node of merged list.
            //list1_p is a pointer that iterates through list1.
            //list2_p is a pointer that iterates through list2.
            ListNode *dummy = new ListNode(),
                     *current = dummy;
            
            //go thru each list, selecting lowest value between both and iterating thru
            while( list1 != nullptr && list2 != nullptr ) {        
                if ( list1->val <= list2->val ) {
                    current->next = list1;
                    list1 = list1->next;
                } else {
                    current->next = list2;
                    list2 = list2->next;
                } 
    
                current = current->next;
            }
    
            current->next = list1 ? list1 : list2;
    
            return dummy->next;
        }
    };