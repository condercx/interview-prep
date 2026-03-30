void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	int index1 = m - 1;
	int index2 = n - 1;
	for (int i = nums1Size - 1; i >= 0; i--) {
		if (index1 < 0) {
			nums1[i] = nums2[index2];
			index2--;
		} else if (index2 < 0) {
			nums1[i] = nums1[index1];
			index1--;
		} else if (nums1[index1] <= nums2[index2]) {
			nums1[i] = nums2[index2];
			index2--;
		} else {
			nums1[i] = nums1[index1];
			index1--;
		}
	}
}


void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	int index1 = m - 1;
	int index2 = n - 1;

	for (int i = nums1Size - 1; i >= 0; i--) {
		// 合并条件：index1越界 或 nums1当前值小于nums2
		if (index1 < 0 || (index2 >= 0 && nums1[index1] <= nums2[index2])) {
			nums1[i] = nums2[index2--];
		} else {
			nums1[i] = nums1[index1--];
		}
	}
}