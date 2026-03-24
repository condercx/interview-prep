#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifdef _WIN32
#include <windows.h>
#endif

// ==================== 数据结构定义 ====================
// 二叉树节点结构
typedef struct TreeNode {
	int data;
	struct TreeNode *left;
	struct TreeNode *right;
} TreeNode;

// 栈节点结构（链式栈）
typedef struct StackNode {
	TreeNode *treeNode;
	struct StackNode *next;
} StackNode;

// 栈结构
typedef struct Stack {
	StackNode *top;
	int size;
} Stack;

// ==================== 栈操作函数 ====================
/**
 * 创建栈
 */
Stack* createStack()
{
	Stack *stack = (Stack*)malloc(sizeof(Stack));
	stack->top = NULL;
	stack->size = 0;

	return stack;
}

/**
 * 判断栈是否为空
 */
bool isEmpty(Stack *stack)
{
	return stack->top == NULL;
}

/**
 * 入栈
 */
void push(Stack *stack, TreeNode *node)
{
	if (node == NULL) return;

	StackNode *stackNode = (StackNode*)malloc(sizeof(StackNode));
	stackNode->treeNode = node;
	stackNode->next = stack->top;
	stack->top = stackNode;
	stack->size++;
}

/**
 * 出栈
 */
TreeNode* pop(Stack *stack)
{
	if(isEmpty(stack)) return NULL;

	StackNode *temp = stack->top;
	TreeNode *node = temp->treeNode;
	stack->top = stack->top->next;
	free(temp);
	stack->size--;
	return node;
}

/**
 * 销毁栈
 */
void destroyStack(Stack *stack)
{
	while(isEmpty(stack)) {
		pop(stack);
	}
	free(stack);
}
// ==================== 方法1：递归实现 ====================
/**
 * 先序遍历 - 递归实现
 * 时间复杂度：O(n)
 * 空间复杂度：O(h)，h为树高
 * 
 * @param root 二叉树根节点
 */

void preorderRecursive(TreeNode *root)
{
	if (root == NULL) {
		return;
	}

	printf("%d ", root->data);

	preorderRecursive(root->left);
	preorderRecursive(root->right);
}

// ==================== 方法2：非递归（链式栈）====================
/**
 * 先序遍历 - 非递归实现（使用链式栈）
 * 时间复杂度：O(n)
 * 空间复杂度：O(h)
 * 
 * @param root 二叉树根节点
 */
void preorderIterativeStack(TreeNode *root)
{
	if (root == NULL) return;

	Stack *stack = createStack();
	push(stack, root);

	while(!isEmpty(stack)) {
		TreeNode *node = pop(stack);
		printf("%d ", node->data);

		if(node->right != NULL) {
			push(stack, node->right);
		}

		if(node->left != NULL) {
			push(stack, node->left);
		}
	}

	destroyStack(stack);
}


// ==================== 辅助函数 ====================

/**
 * 创建新节点
 */

TreeNode* createNode(int data)
{
	TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

/**
 * 释放二叉树内存
 */
void freeTree(TreeNode *root)
{
	if (root == NULL) {
		return;
	}

	freeTree(root->left);
	freeTree(root->right);
	free(root);
}

/**
 * 打印分隔线
 */
void printSeparator(const char *title) {
	printf("\n========== %s ==========\n", title);
}
// ==================== 主函数 ====================

int main() 
{
#ifdef _WIN32
	// 设置控制台为 UTF-8 编码
	SetConsoleOutputCP(65001);
#endif

	// 构建测试二叉树
	//         1
	//        / \
	//       2   3
	//      / \   \
	//     4   5   6
	//    /
	//   7
	
	TreeNode *root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	root->right->right = createNode(6);
	root->left->left->left = createNode(7);
	
	printf("二叉树结构：\n");
	printf("        1\n");
	printf("       / \\\n");
	printf("      2   3\n");
	printf("     / \\   \\\n");
	printf("    4   5   6\n");
	printf("   /\n");
	printf("  7\n");
	
	// 测试所有遍历方法
	printSeparator("方法1: 递归实现");
	printf("结果: ");
	preorderRecursive(root);
	printf("\n");

	printSeparator("方法2: 非递归（链式栈）");
    printf("结果: ");
    preorderIterativeStack(root);
    printf("\n");

}