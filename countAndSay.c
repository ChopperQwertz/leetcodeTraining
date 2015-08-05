void subFunc(char *in, char *out) {
	int i, j=0, cnt=0;
	char num;
	for (i=0; in[i] != 0; i++) {
		if (!cnt) {
			num = in[i];
			cnt++;
			continue;
		}
		if (num == in[i]) {
			cnt++;
			continue;
		} else {
			out[j] = (char)(cnt + 0x30);
			out[j+1] = num;
			j+= 2;
            if (in[i+1] != 0) 
                num = in[i];
            else 
                num = in[i];
            cnt = 1;
		}
	}	
	if (cnt) {
		out[j] = (char)(cnt + 0x30);
		out[j+1] = num;
        out[j+2] = '\0';
	} else 
	    out[j] = '\0';
}
char* countAndSay(int n) {
#define ARRAYSIZE 8192
	int i;
	char *output1, *output2;
	output1 = (char *)calloc(ARRAYSIZE, sizeof(char));
	output2 = (char *)calloc(ARRAYSIZE, sizeof(char));
	output1[0] = '1';
    output1[1] = '\0';
	
	for(i=1; i<=n; i++) {
		if (i%2) 
			subFunc(output1, output2);
		else 
			subFunc(output2, output1);
	}
	if (i%2)
		return output2;
	else 
		return output1;
}

