struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *Scanner=head, *tmp;
	if (!head) 
		return (struct ListNode *)0;
	while (Scanner->next) {
		if (Scanner->val == Scanner->next->val) {
			if (!tmp)
				tmp = Scanner;
		} else {
			if (tmp) {
				tmp->next = Scanner->next;
				tmp = 0;
			}
		}
		Scanner = Scanner->next;		
	}
	if (tmp) 
		tmp->next = 0;	
	return head;
}

