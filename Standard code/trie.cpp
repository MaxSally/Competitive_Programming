struct node {
	struct node *child[N];
	int weight;
	int endW;
};

struct node *addNode() {
	struct node *Node = new struct node;
	Node->endW = 0;
	Node->weight = 0;
	for (int i = 0; i < N; i++) {
		Node->child[i] = NULL;
	}
	return Node;

};

void addWord(struct node *root, string s) {
	int ch;
	struct node *temp = root;
	for (int i = 0; i < s.length(); i++) {
		ch = s[i] - '0';
		if (temp->child[ch] == NULL) {
			temp->child[ch] = addNode();
		}
		temp = temp->child[ch];
		temp->weight += 1;
	}
	temp->endW = 1;
}

int findWord(struct node *root, string s) {
	int ch;
	struct node *temp = root;
	int cnt = 0;
	int ans = 0;
	for (int i = 0; i<s.length(); i++) {
		ch = s[i] - '0';
		if (temp->child[ch] == NULL) {
			return -1;
		}
		temp = temp->child[ch];
		cnt++;
		int temp1 = temp->weight;
		ans = max(ans, cnt*temp1);
	}
	return max(temp->weight*cnt, ans);

}

void deletenode(struct node *temp) {
	for (int i = 0; i < N; i++) {
		if (temp->child[i]) {
			deletenode(temp->child[i]);
			delete temp->child[i];
		}
	}
}
