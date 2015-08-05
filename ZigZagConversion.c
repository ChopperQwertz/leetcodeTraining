char* convert(char* s, int numRows) {
    int i, j=0, x, y, index=0;
    int index_x, index_y, tmp_x, tmp_y;
    int length = strlen(s);
    char *output;
    char **charPool;
    output = (char *)calloc(strlen(s)+1, sizeof(char));
    if (numRows == 1) 
        return s;
    x = (length<numRows)?1:(length/2 +1);
    y = numRows;
    charPool = (char **)calloc(x, sizeof(char *));
    for (i=0; i<x; i++) {        
        charPool[i] = (char *)calloc(numRows, sizeof(char));        
    }
    for (i=0; s[i]!='\0'; i++) {
        if (i < numRows) {
            index_x = 0;
            index_y = i;
        }
        else {
            index_x = i / (2*(numRows-1));
            tmp_x = i - index_x * (2*(numRows-1));
            if (tmp_x < numRows) {
                index_y = i % (2*(numRows-1));
                index_x *= (numRows-1);
            } else {
                index_y = (numRows-1) - (tmp_x % (numRows-1));
                index_x *= (numRows-1);
                index_x += (tmp_x % (numRows-1));
            }            
        }
        charPool[index_x][index_y] = s[i];
    }
    
    for (j=0; j<numRows; j++) {
        for (i=0; i<x; i++){
            if (charPool[i][j]) {
                output[index++] = charPool[i][j];
            }
        }
    }
    output[length] = '\0';
    return output;
}

