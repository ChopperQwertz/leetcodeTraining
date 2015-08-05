/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int index=0;
	struct ListNode *Scanner, *Target;
	Scanner = head;
	do {
		if ( index == n ){
			Target = head;
		} else if (index > n) {
			Target = Target->next;
		}
		Scanner = Scanner->next;
		index++;
	} while (Scanner) ;
	if (index == n)
	    return head->next;
	if (!Target->next)
	    return 0;
	if (Target->next->next)
	    Target->next = Target->next->next;
	else 
	    Target->next = 0;
	return head;
}

