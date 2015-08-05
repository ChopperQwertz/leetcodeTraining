int romanToInt(char* s) {
    int output=0, i=0;
	if (s[i] == '\0')
		return 0;
	while (s[i] == 'M') {
		output +=1000;
		i++;
	}
	if ( (s[i] == 'C') && (s[i+1] == 'M') ) {
		output += 900;
		i+=2;
	} else if ( (s[i] == 'C') && (s[i+1] == 'D') ) {
		output += 400;
		i+=2;
	} 
	if (s[i] == 'D') {
		output += 500;
		i++;
	}
	while (s[i] == 'C') {
		output +=100;
		i++;
	}
	if ( (s[i] == 'X') && (s[i+1] == 'C') ) {
		output += 90;
		i+=2;
	} else if ( (s[i] == 'X') && (s[i+1] == 'L') ) {
		output += 40;
		i+=2;
	} 
	if (s[i] == 'L') {
		output += 50;
		i++;
	}
	while (s[i] == 'X') {
		output +=10;
		i++;
	}
	if ( (s[i] == 'I') && (s[i+1] == 'X') ) {
		output += 9;
		i+=2;
	} else if ( (s[i] == 'I') && (s[i+1] == 'V') ) {
		output += 4;
		i+=2;
	} 
	if (s[i] == 'V') {
		output += 5;
		i++;
	}
	while (s[i] == 'I') {
		output +=1;
		i++;
	}
	return output;   
}

