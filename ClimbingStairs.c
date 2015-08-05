int climbStairs(int n) {
    // it's fibonacci sequence
	int i, num1=1,num2=2;
	if (n==0)
		return 0;
	if (n==1)
		return 1;		
	if (n==2)
		return 2;				
	
	for (i=3; i<=n; i++) {
		if (num1<num2)
			num1 += num2;
		else 
			num2 += num1;
	}	
	if (num1>num2) 
		return num1;
	else 
		return num2;
}

