bool isPowerOfTwo(int n) {
	int val=n;
    if (val==1)
		return true;
	if (val==0)
		return false;
	if (val & 0x1) 
		return false;
	else if (val>1) {
		while (1) {
			val >>= 1;
			if (val & 0x1) 
				break;
		}
		if (val == 0x1)
			return true;
		else 
			return false;		
	} else {
		return false;
	}
}