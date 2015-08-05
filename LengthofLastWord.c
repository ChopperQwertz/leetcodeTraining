int lengthOfLastWord(char* s) {
    int i, output=0, resetTag=0;
	for (i=0; s[i]!='\0'; i++) {
		if (s[i] == (char)0x20) {
			resetTag = 1;
		} else {
			if (resetTag) {
				output = 1;
				resetTag = 0;
			} else {
				output++;
			}			
		}			
	}
	return output;
}
