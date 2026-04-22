bool validMountainArray(int* arr, int arrSize)
{
	if (arrSize < 3) {
		return false;
	}

	int mou1, mou2;
	for (int i = 1; i < arrSize; i++) {
		if (arr[i] == arr[i - 1]) return false;

		if (arr[i] < arr[i - 1]) {
			mou1 = i - 1;
			break;
		}
	}

	for (int j = arrSize - 2; j >= 0; j--) {
		if (arr[j] == arr[j + 1]) return false;

		if (arr[j] < arr[j + 1]) {
			mou2 = j + 1;
			break;
		}
	}

	if (mou1 == mou2) {
		return true;
	} else {
		return false;
	}
}