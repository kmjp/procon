typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------



int NG;
class Solution {
public:

	pair<int,int> hoge(TreeNode* root) {
		if(root->left==NULL && root->right==NULL) {
			return {0,0};
		}
		else if(root->right==NULL) {
			auto p=hoge(root->left);
			p.first++;
			p.second++;
			if(p.first>1) NG=1;
			return {p.first,0};
		}
		else if(root->left==NULL) {
			NG=1;
			return {0,0};
		}
		else {
			auto p=hoge(root->left);
			auto q=hoge(root->right);
			p.first++;
			p.second++;
			q.first++;
			q.second++;
			if(q.first>p.second) NG=1;
			if(q.second!=p.first&&q.second+1!=p.first) NG=1;
			return {p.first,q.second};
		}
		
		
	}
    bool isCompleteTree(TreeNode* root) {
		NG=0;
		auto p=hoge(root);
        return NG==0;
    }
};
