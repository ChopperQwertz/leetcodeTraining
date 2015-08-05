int myAtoi(char* str) {
    unsigned int unSignVal=0, unSignLast=-1;
    int output=0, index=0;
    int sgnd=0; //0: positive, 1:negitive

    if (str[index] == '\0')
        return 0;
    while(str[index] == 0x20) 
        index++;
    
    if ((str[index] == '+') || (str[index] == '-')) {        
        if (str[index] == '-')
            sgnd = 1;
        index++;
    }        
    while( str[index] != '\0') {
        if (unSignVal >= 0x0CCCCCCC) {
            unSignLast = 0x80000001;
            break;
        }          
        if ((int)str[index] == 0x20) {
            if (unSignLast)
                break;
            if (unSignLast != -1)
                return 0;
            index++;      
            continue;
        }
        if ( ((int)str[index]>=0x3A || (int)str[index]<=0x2F) ) {
            break;
        }
        unSignVal += (unsigned int)(str[index]-0x30);
        index++;     
        unSignLast = unSignVal;
        unSignVal *= 10;      
    }
    if (unSignLast != -1)
        unSignVal = unSignLast;
    if (unSignVal >= 0x80000000 && !sgnd)
        unSignVal = 0x7FFFFFFF;
    else if (unSignVal >= 0x80000001 && sgnd)
        unSignVal = 0x80000000;    
    if (sgnd)
        output = -(int)unSignVal;
    else 
        output = (int)unSignVal;
    
    return output;
}

