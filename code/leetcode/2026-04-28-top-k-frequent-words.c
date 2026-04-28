/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct Node{
	char word[11];
	int count;
}node;

int cmp1(const void *a, const void *b) 
{
	const node *na = (const node*)a;
	const node *nb = (const node*)b;
	return (nb->count - na->count);
}

int cmp2(const void *a, const void *b)
{
	const node *na = (const node*)a;
	const node *nb = (const node*)b;
	return (strcmp(na->word, nb->word));
}

char** topKFrequent(char** words, int wordsSize, int k, int* returnSize)
{
	node *node_w = calloc(wordsSize, sizeof(node));
	char **ret = calloc(wordsSize, sizeof(char*));
	int node_len = 0;

	for (int i = 0; i < wordsSize; i++) {
		int flag = 1;

		for (int j = 0; j < node_len; j++) {
			if (strcmp(node_w[j].word, words[i]) == 0) {
				node_w[j].count++;
				flag = 0;
				break;
			}
		}

		if (flag == 1) {
			strcpy(node_w[node_len].word, words[i]);
			node_w[node_len].count++;
			node_len++;
		}
	}

	qsort(node_w, node_len, sizeof(node), cmp2);
	qsort(node_w, node_len, sizeof(node), cmp1);

	for (int i = 0; i < k; i++) {
		ret[i] = node_w[i].word;
	}

	*returnSize = k;
	return ret;
}