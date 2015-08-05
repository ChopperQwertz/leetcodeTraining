int reverse(int x) {
    int output=0, i=0, input=abs(x), last;    
    do {
        last = output;
        output *= 10;
        output += input % 10;
        input /= 10;      
        if (output /10 != last)
            output = 0;
    } while(input);    
    if (x < 0)
        output = -output;    
    return output;
}








































int main() {
    
    int output = reverse(1534236469);
	
	printf("\noutput=%d\n", output);	
	system("pause");
	
	return 0;	
}



