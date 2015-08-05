bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    int i,j,x,y,round;
	int arr[10] = {0,0,0,0,0,0,0,0,0,0};
	for (i=0; i<boardRowSize; i++) {
		memset(arr, 0, sizeof(int)*10);
		for (j=0; j<boardColSize; j++) {
            if (board[i][j]<=0x30) 
                continue;
			if (board[i][j]>0x30 && !arr[board[i][j]-0x30])
				arr[board[i][j]-0x30]++;
			else 
				return false;
		}
	}
	for (i=0; i<boardColSize; i++) {
		memset(arr, 0, sizeof(int)*10);
		for (j=0; j<boardRowSize; j++) {
            if (board[j][i]<=0x30) 
                continue;
			if (board[j][i]>0x30 && !arr[board[j][i]-0x30]) 
				arr[board[j][i]-0x30]--;
			else 
				return false;
		}
	}
	for (round=0; round<9; round++) {
		memset(arr, 0, sizeof(int)*10);
		for (i=0, x=(round/3)*3, y=(round%3)*3; i<3; i++, x++, y-=3) {
			for (j=0; j<3; j++, y++) {
                if (board[x][y]<=0x30) 
                    continue;
				if (board[x][y]>0x30 && !arr[board[x][y]-0x30]) 
					arr[board[x][y]-0x30]--;
				else 
					return false;
			}            
		}
	}	
	return true;
}

