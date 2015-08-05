int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int i, start=-1, end=0, *output;
	for (i=0; i<digitsSize; i++) {
		if (start==-1 && digits[i] == 9) {
			start = i;
		} else if (digits[i] == 9) {
			end = i;
		} else if (digits[i] != 9) {
			start = -1;
			end = 0;
		}
	}    
	if (start==0 && end) {
		output = (int *)calloc(digitsSize+1, sizeof(int));
		output[0] = 1;
		returnSize[0] = digitsSize+1;
	} else if (start==0 && !end) {
        if (digits[0] == 9) {
            output = (int *)calloc(digitsSize+1, sizeof(int));		
            output[0] = 1;
            output[1] = 0;           
            returnSize[0] = 2;
            return output;
        } else {
	    	digits[digitsSize-1] += 1;
    		returnSize[0] = digitsSize;
            return digits;
        }        
	} else if (start == -1) {
	    output = (int *)calloc(digitsSize, sizeof(int));		
        for (i=0; i<digitsSize; i++) 
            output[i] = digits[i];
        output[i-1]++;
		returnSize[0] = digitsSize;
	} else{
		output = (int *)calloc(digitsSize, sizeof(int));		
		for (i=0; i<digitsSize; i++) {
			if (i+1 == start) {
				output[i] = digits[i]+1;
				break;
			} else {
				output[i] = digits[i];
			}
		}
		returnSize[0] = digitsSize;
	}
	return output;
}
    
