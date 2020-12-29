// Lab12.10.cpp
// Михайлов Олександр
// Дерева
// Варіант 24

#include <iostream>
#include <Windows.h>
#include <time.h>
#include <cmath>

using namespace std;

typedef int Info;
struct Node {
	Node* left,
		* right;
	Info info;
};

void EnterValues(const int playersAmount, int*& value) {
	for (int i = 0; i < playersAmount; i++) {
		do {
			cout << " Введіть значення інформаційного поля гравця №" << i + 1 << " (значення від 0 до 9): "; cin >> value[i];
			if (value[i] < 0 || value[i] > 9) {
				cout << " Ви ввели недопустиме значення!" << endl;
			}
		} while (value[i] < 0 || value[i] > 9);
	}
}

Node* CreateTree(int nodeCount) {
	if (nodeCount == 0) {
		return NULL;
	}
	else
	{
		Node* newNode = new Node;

		int leftCount = nodeCount / 2;
		int rightCount = nodeCount - leftCount - 1;
		newNode->left = CreateTree(leftCount);
		newNode->right = CreateTree(rightCount);
		
		return newNode;
	}
}

int Max(int l, int r) {
	int max = 0;
	if (l > r) {
		max = l;
	}
	else if (l <= r) {
		max = r;
	}
	return max;
}

void FindWinner(Node*& root, int playersAmount, int* v) {
	if (playersAmount == 2) {
		root->left->info = v[0];
		root->right->info = v[1];
		root->info = Max(v[0], v[1]);

		cout << "   " << root->info << endl;
		cout << " " << v[0] << "   " << v[1] << endl << endl;
	}
	else if (playersAmount == 4) {
		root->left->left->info = v[0];
		root->left->right->info = v[1];
		root->right->left->info = v[2];
		root->right->right->info = v[3];
		root->left->info = Max(v[0], v[1]);
		root->right->info = Max(v[2], v[3]);
		root->info = Max(Max(v[0], v[1]), Max(v[2], v[3]));

		cout << "       " << root->info << endl;
		cout << "   " << root->left->info << "       " << root->right->info << endl;
		cout << " " << v[0] << "   " << v[1] << "   " << v[2] << "   " << v[3] << endl << endl;
	}
	else if (playersAmount == 8) {
		root->left->left->left->info = v[0];
		root->left->left->right->info = v[1];
		root->left->right->left->info = v[2];
		root->left->right->right->info = v[3];
		root->right->left->left->info = v[4];
		root->right->left->right->info = v[5];
		root->right->right->left->info = v[6];
		root->right->right->right->info = v[7];
		root->left->left->info = Max(v[0], v[1]);
		root->left->right->info = Max(v[2], v[3]);
		root->left->info = Max(Max(v[0], v[1]), Max(v[2], v[3]));
		root->right->left->info = Max(v[4], v[5]);
		root->right->right->info = Max(v[6], v[7]);
		root->right->info = Max(Max(v[4], v[5]), Max(v[6], v[7]));
		root->info = Max(root->left->info, root->right->info);

		cout << "               " << root->info << endl;
		cout << "       " << root->left->info << "               " << root->right->info << endl;
		cout << "   " << root->left->left->info << "       " << root->left->right->info << "       "
			<< root->right->left->info << "       " << root->right->right->info << endl;
		cout << " " << v[0] << "   " << v[1] << "   " << v[2] << "   " << v[3] << "   " << v[4] << "   " << v[5] << "   " << v[6] << "   " << v[7] << endl << endl;
	}
	else if (playersAmount == 16) {
		root->left->left->left->left->info = v[0];
		root->left->left->left->right->info = v[1];
		root->left->left->right->left->info = v[2];
		root->left->left->right->right->info = v[3];
		root->left->right->left->left->info = v[4];
		root->left->right->left->right->info = v[5];
		root->left->right->right->left->info = v[6];
		root->left->right->right->right->info = v[7];
		root->right->left->left->left->info = v[8];
		root->right->left->left->right->info = v[9];
		root->right->left->right->left->info = v[10];
		root->right->left->right->right->info = v[11];
		root->right->right->left->left->info = v[12];
		root->right->right->left->right->info = v[13];
		root->right->right->right->left->info = v[14];
		root->right->right->right->right->info = v[15];
		root->left->left->left->info = Max(v[0], v[1]);
		root->left->left->right->info = Max(v[2], v[3]);
		root->left->left->info = Max(Max(v[0], v[1]), Max(v[2], v[3]));
		root->left->right->left->info = Max(v[4], v[5]);
		root->left->right->right->info = Max(v[6], v[7]);
		root->left->right->info = Max(Max(v[4], v[5]), Max(v[6], v[7]));
		root->left->info = Max(root->left->left->info, root->left->right->info);
		root->right->left->left->info = Max(v[8], v[9]);
		root->right->left->right->info = Max(v[10], v[11]);
		root->right->left->info = Max(Max(v[8], v[9]), Max(v[10], v[11]));
		root->right->right->left->info = Max(v[12], v[13]);
		root->right->right->right->info = Max(v[14], v[15]);
		root->right->right->info = Max(Max(v[12], v[13]), Max(v[14], v[15]));
		root->right->info = Max(root->right->left->info, root->right->right->info);
		root->info = Max(root->left->info, root->right->info);

		cout << "                               " << root->info << endl;
		cout << "               " << root->left->info << "                               " << root->right->info << endl;
		cout << "       " << root->left->left->info << "               "
			<< root->left->right->info << "               "
			<< root->right->left->info << "               "
			<< root->right->right->info << endl;
		cout << "   " << root->left->left->left->info << "       "
			<< root->left->left->right->info << "       "
			<< root->left->right->left->info << "       "
			<< root->left->right->right->info << "       "
			<< root->right->left->left->info << "       "
			<< root->right->left->right->info << "       "
			<< root->right->right->left->info << "       "
			<< root->right->right->right->info << "       " << endl;
		cout << " "
			<< v[0] << "   " << v[1] << "   " << v[2] << "   " << v[3] << "   "
			<< v[4] << "   " << v[5] << "   " << v[6] << "   " << v[7] << "   "
			<< v[8] << "   " << v[9] << "   " << v[10] << "   " << v[11] << "   "
			<< v[12] << "   " << v[13] << "   " << v[14] << "   " << v[15] << "   " << endl << endl;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int roundsNum;
	do {
		cout << " Введіть кількість кіл турніру(мінімум 1, максимум 4): "; cin >> roundsNum;
		if (roundsNum < 1 || roundsNum > 4) {
			cout << endl << " Кількість кіл має бути від 1 до 4!" << endl << endl;
		}
	} while (roundsNum < 1 || roundsNum > 4);

	int playersAmount = pow(2, roundsNum);
	cout << endl << " Кількість учасників буде становити " << playersAmount;
	if (playersAmount == 2 || playersAmount == 4) {
		cout << " гравця" << endl;
	}
	else {
		cout << " гравців" << endl;
	}
	int* values = new int[playersAmount];
	EnterValues(playersAmount, values);

	int NodeNum;
	switch (playersAmount) {
	case 2:
		NodeNum = 3;
	case 4:
		NodeNum = 7;
	case 8:
		NodeNum = 15;
	case 16:
		NodeNum = 31;
	}

	Node* root = CreateTree(NodeNum);
	FindWinner(root, playersAmount, values);

	delete[] values;
	return 0;
}
