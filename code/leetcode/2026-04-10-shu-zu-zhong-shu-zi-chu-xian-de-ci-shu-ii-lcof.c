int trainingPlan(int* actions, int actionsSize)
{
	int res = 0;

	for (int i = 0; i < 32; i++) {
		int tmp = 0;
		for (int j = 0; j < actionsSize; j++) {
			tmp += (actions[j] >> i) & 1;
		}

		if (tmp % 3 != 0) {
			res += 1 << i;
		}
	}

	return res;
}