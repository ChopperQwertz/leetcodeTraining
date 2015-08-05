#include <stdio.h>
#include <stdlib.h>

// There are two sorted arrays nums1 and nums2 of size m and n respectively. 
// Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    double output=0;
    
    return output;
}






int main() {
	
	int s1[] = {1,7,9,11,15,18,20};
	int s2[] = {2,6,8,10,17,19};
    double output;
    output = findMedianSortedArrays(s1,sizeof(s1)/4,s2,sizeof(s2)/4);
	
	printf("%f\n", output);
	
	system("pause");
	
	return 0;	
}

