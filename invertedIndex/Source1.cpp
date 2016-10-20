#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int freq[26];
struct TreeNode {
	char c;
	int f;
	TreeNode*left;
	TreeNode*right;
	TreeNode() {}
	TreeNode(int ff, TreeNode*l, TreeNode*r) :f(ff), left(NULL), right(NULL) {}
	bool operator <(const TreeNode& t) const
	{
		return f >= t.f;
	}

};
vector<TreeNode*> tree;
int build(string s)
{
	for (int i = 0; i < s.size(); ++i)
		freq[s[i] - 'a']++;
	for(int i = 0; i < 26; ++i)
		if (freq[i]) {
			TreeNode *t = new TreeNode(freq[i], NULL, NULL);
			t->c = i + 'a';
			tree.push_back(t);
		}		
	while (tree.size() > 1)
	{
		sort(tree.begin(), tree.end());
		TreeNode *p, *q;
		p = tree.back();
		tree.pop_back();
		q = tree.back();
		tree.pop_back();
		int comp = p->f + q->f;
		TreeNode *com = new TreeNode(comp ,p, q);
		tree.push_back(com);
	}
}

