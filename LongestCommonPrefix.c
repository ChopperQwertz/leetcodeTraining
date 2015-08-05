char* longestCommonPrefix(char** strs, int strsSize) {
    int i, j;
    char *output;
	output = (char *)malloc(sizeof(char) * 256);
	if (!strs[0]) 
		return "";
	for (i=0; strs[0][i]!='\0'; i++) 
		output[i] = strs[0][i];
	for(i=1; i<strsSize; i++) {
		j=0;
		while (output[j] != '\0') {
			if (output[j] == strs[i][j]) {
				j++;
			} else {				
				output[j] = '\0';
				break;				
			}			
		}
	}
	return output;
}

