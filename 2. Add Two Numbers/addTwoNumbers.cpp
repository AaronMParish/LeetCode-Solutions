struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


class Solution {
public:
    void createSum( ListNode** currentNode, ListNode* l1, ListNode* l2, int carry ) {
        bool l1Empty = ( l1 == nullptr ),
             l2Empty = ( l2 == nullptr );
        int integerNumber = 0;

        //if list 1 node isnt null, add to sum
        if ( !l1Empty )
        {
            integerNumber += l1->val;
            l1 = l1->next;
        }

        //if list 2 node isnt null, add to sum
        if ( !l2Empty )
        {
            integerNumber += l2->val;
            l2 = l2->next;
        }

        //add carry bit
        integerNumber += carry;
        carry = 0;

        //find new carry bit
        if ( integerNumber > 9 )
        {
            integerNumber = integerNumber % 10;
            carry = 1;
        }

        l1Empty = ( l1 == nullptr );
        l2Empty = ( l2 == nullptr );

        (*currentNode)->val = integerNumber;

        //create new node if more data to compute
        if ( !l1Empty || !l2Empty || carry != 0 )
        {
            (*currentNode)->next = new ListNode();
            createSum(&((*currentNode)->next), l1, l2, carry);
        }
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();

        //summate two numbers using recursion
        createSum(&head, l1, l2, 0);

        return head;
    }
};