int strStr(char* haystack, char* needle) {
    int i=0, j=0, k=0, m=0;
    int needleSize, haystackSize, shiftVal=1;
    if (haystack[0]=='\0' && needle[0]!='\0')
        return -1;
    if (needle[0]=='\0')
        return 0;
	for (i=0; needle[i] != '\0'; i++) {}
	needleSize = i;
	for (i=0; haystack[i] != '\0'; i++) {}
	haystackSize = i;	
	for (i=0; haystack[i] != '\0'; i+=shiftVal) {
		if (i+needleSize > haystackSize)
			return -1;
		for(j=i, k=0; needle[k] != '\0'; j++, k++) {
			if (haystack[j] != needle[k]) {
				// count shift value
				for (m=needleSize-1; m>=0; m--) {
					if (haystack[i+needleSize] !=  '\0' && needle[m] == haystack[i+needleSize]) {
						shiftVal = needleSize - m;
						break;
					}
				}
                break;
			}
			if (needle[k+1] == '\0') 
                return i;
		} 
	}
	return -1;
}
