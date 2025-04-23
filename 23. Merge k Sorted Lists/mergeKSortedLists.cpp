#include <vector>
#include <queue>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto compare = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> heap(compare);
        
        for( auto list : lists ) {
            if ( list )
                heap.push(list);
        }

        ListNode* sorted = new ListNode();
        ListNode* dummy = sorted;

        while( !heap.empty() ) {
            ListNode* min = heap.top();
            heap.pop();
            
            if ( min->next ) {
                heap.push( min->next );
            }

            dummy->next = min;
            dummy = dummy->next;
        }

        return sorted->next;
    }
};