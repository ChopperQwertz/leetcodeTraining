bool checkPal(int x, int cnt) {
	if (cnt==2)
		return (bool)((x%10) == (x/10));
	else if (cnt==4) {
		if ( (x%1000/100) != (x%100/10) )
			return false;
		else 
			return checkPal((x/1000*10)+(x%10), 2);
	} else if (cnt==6) {
		if ( (x%10000/1000) != (x%1000/100) )
			return false;
		else 
			return checkPal((x/10000*100)+(x%100), 4);
	} else if (cnt==8) {
		if ( (x%100000/10000) != (x%10000/1000) )
			return false;
		else 
			return checkPal((x/100000*1000)+(x%1000), 6);
	} else if (cnt==10) {
		if ( (x%1000000/100000) != (x%100000/10000) )
			return false;
		else 
			return checkPal((x/1000000*10000)+(x%10000), 8);
	} else 
		return false;
}
bool isPalindrome(int x) {
	if (x<0)
		return false;
	else if(x==0) 
		return true;
	else { // 1~2147483647
		if (x<10) 
			return true;
		else if (x<100) 
			return checkPal(x, 2);
		else if (x<1000)
			return checkPal((x/100*10)+(x%10), 2);
		else if (x<10000)
			return checkPal(x, 4);
		else if (x<100000)
			return checkPal((x/1000*100)+(x%100), 4);
		else if (x<1000000)
			return checkPal(x, 6);
		else if (x<10000000)
			return checkPal((x/10000*1000)+(x%1000), 6);
		else if (x<100000000)
			return checkPal(x, 8);
		else if (x<1000000000)
			return checkPal((x/100000*10000)+(x%10000), 8);
		else if (x<2147483647)
			return checkPal(x, 10);
		else
			return false;
	}
}

