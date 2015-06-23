struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {	
	int overflow=0;
	struct ListNode *output, *outputPtr, *input1, *input2;
	output = (struct ListNode *)calloc(1, sizeof(struct ListNode));
	outputPtr = output;
	input1 = l1;
	input2 = l2;	
	// do overlapping part
	do {		
		if ( (outputPtr->val = input1->val + input2->val + overflow) >= 10) {
			outputPtr->val -= 10;
			overflow = 1;
		} else 
			overflow = 0;			
		input1 = input1->next;
		input2 = input2->next;
		if (input1 && input2) { 
			outputPtr->next = (struct ListNode *)calloc(1, sizeof(struct ListNode));
			outputPtr = outputPtr->next;		
		}
	} while ( input1 && input2);	
	// handle other part
	if (input1) {
		do {	
			outputPtr->next = (struct ListNode *)calloc(1, sizeof(struct ListNode));
			outputPtr = outputPtr->next;		
			if ((outputPtr->val = input1->val + overflow) >= 10) {
				outputPtr->val -= 10;
				overflow = 1;
			} else 
				overflow = 0;
			input1 = input1->next;
		} while (input1);		
	} else if (input2) {
		do {				
			outputPtr->next = (struct ListNode *)calloc(1, sizeof(struct ListNode));
			outputPtr = outputPtr->next;		
			if ((outputPtr->val = input2->val + overflow) >= 10) {
				outputPtr->val -= 10;
				overflow = 1;
			} else 
				overflow = 0;				
			input2 = input2->next;
		} while (input2);
	}		
	if (overflow) {
		outputPtr->next = (struct ListNode *)calloc(1, sizeof(struct ListNode));
		outputPtr = outputPtr->next;
		outputPtr->val = 1;
	} 	
	return output;
}