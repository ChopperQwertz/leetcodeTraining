void merge(int* nums1, int m, int* nums2, int n) {
    int *array, i=0, j=0, k=0;
	if (n == 0)
		return;
	if (m == 0) {
		for (i=0; i<n; i++) 
			nums1[i] = nums2[i];
		return;
	}
	
	array = (int *)calloc(m+n, sizeof(int));
	while (i<m && j<n) {
		if (nums1[i] <= nums2[j]) 
			array[k++] = nums1[i++];
		else 
			array[k++] = nums2[j++];	
	}
	for (; i<m; ) 
		array[k++] = nums1[i++];	
	for (; j<n; ) 
		array[k++] = nums2[j++];	
	for (i=0; i<m+n; i++) 
		nums1[i] = array[i];	
}

