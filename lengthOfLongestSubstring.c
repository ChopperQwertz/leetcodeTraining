int lengthOfLongestSubstring(char* s) {	
#define STRING_SIZE 256
    int max=0, head=0, tail=0, i=0, j;
	char *StoredString; // ring buffer
	StoredString = (char *)calloc(STRING_SIZE, sizeof(char));

	while (s[i] != '\0') {
		for (j=tail; j!=head; j++) {
			if (s[i] == StoredString[j]) {
				tail = j+1;
				if (tail == STRING_SIZE)
					tail = 0;
				break;
			}
			if (j >= STRING_SIZE)
				j %= STRING_SIZE;
		}
		StoredString[head++] = s[i]; 
		if (head >= STRING_SIZE)
			head %= STRING_SIZE;
		if (head > tail) 
			max = (max > head - tail)?max:(head - tail);
		else 
			max = (max > head + STRING_SIZE - tail)?max:(head + STRING_SIZE - tail);		
		i++;
	}	
	return max;
}