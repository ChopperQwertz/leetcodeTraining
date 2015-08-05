/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *ptrl1, *ptrl2, *tmp, *output;
    int switcher=0; // 1:force switch to 1 when equal 2: force switch to 2 when equal
	ptrl1 = l1;
	ptrl2 = l2;
	if (!ptrl1)
		return ptrl2;
	if (!ptrl2)
		return ptrl1;
	if (ptrl2->val <= ptrl1->val)
		output = ptrl2;
	else 
		output = ptrl1;
	while (ptrl1 && ptrl2 && ptrl1->next && ptrl2->next) {
        if (ptrl1->val == ptrl2->val) {
            if (switcher == 1 || switcher == 0) {
                tmp = ptrl2->next;
				ptrl2->next = ptrl1;
				ptrl2 = tmp;
                switcher = 2;                
            } else { // switcher == 2       
				tmp = ptrl1->next;
				ptrl1->next = ptrl2;
				ptrl1 = tmp;
                switcher = 1;                     
            }
        } else if (ptrl1->val > ptrl2->val) {
            if ( ptrl2->next->val == ptrl1->val ) {
                if (switcher == 1 || switcher == 0) {
                    tmp = ptrl2->next->next;
                    ptrl2->next->next = ptrl1;
                    ptrl2 = tmp;
                    switcher = 2;    
                } else { // switcher == 2
                    tmp = ptrl1->next->next;
                    ptrl1->next->next = ptrl2;
                    ptrl1 = tmp;
                    switcher = 1;        
                }
            } else if (ptrl2->next->val > ptrl1->val) {
				tmp = ptrl2->next;
				ptrl2->next = ptrl1;
				ptrl2 = tmp;
                switcher = 2;
			} else { // ptrl2->next->val < ptrl1->val
				ptrl2 = ptrl2->next;
                switcher = 1;
			}
		} else{ // ptrl1->val < ptrl2->val
		    if (ptrl1->next->val == ptrl2->val) {
                if (switcher == 1) {
                    tmp = ptrl2->next->next;
                    ptrl2->next->next = ptrl1;
                    ptrl2 = tmp;
                    switcher = 2;    
                } else { // switcher == 2
                    tmp = ptrl1->next->next;
                    ptrl1->next->next = ptrl2;
                    ptrl1 = tmp;
                    switcher = 1;        
                }
            } else if (ptrl1->next->val > ptrl2->val) {
				tmp = ptrl1->next;
				ptrl1->next = ptrl2;
				ptrl1 = tmp;
                switcher = 1;                
			} else { // ptrl1->next->val < ptrl2->val
				ptrl1 = ptrl1->next;
                switcher = 2;
			}
		} 
	}
    // handle last round
	if (ptrl1 && ptrl1->next) {
        if (!ptrl2)
            return output;
        if (ptrl1->val == ptrl2->val) {
            tmp = ptrl1->next;
            ptrl1->next = ptrl2;
            ptrl2->next = tmp;
        } else if (ptrl1->val > ptrl2->val) {
			ptrl2->next = ptrl1;
		} else { // ptrl1->val < ptrl2->val
			while( ptrl1 && (ptrl2->val > ptrl1->val) ) {
				tmp = ptrl1;
				ptrl1 = ptrl1->next;
			}
			if (!ptrl1) {	
				tmp->next = ptrl2;
			} else {		
				ptrl2->next = ptrl1;
				tmp->next = ptrl2;
			}
		}
	} else if (ptrl2 && ptrl2->next) {
        if (!ptrl1)
            return output;
        if (ptrl2->val == ptrl1->val) {
            tmp = ptrl2->next;
            ptrl2->next = ptrl1;
            ptrl1->next = tmp;
        } else if (ptrl2->val > ptrl1->val) {
			ptrl1->next = ptrl2;
		} else { // ptrl2->val < ptrl1->val
			while( ptrl2 && (ptrl1->val > ptrl2->val) ) {
				tmp = ptrl2;
				ptrl2 = ptrl2->next;
			}
			if (!ptrl2) {
				tmp->next = ptrl1;
			} else {
				ptrl1->next = ptrl2;
				tmp->next = ptrl1;
			}
		}
	} else {
		if (ptrl1->val >= ptrl2->val) {
			ptrl2->next = ptrl1;
		} else {
			ptrl1->next = ptrl2;
		}
	}
	return output;          
}

