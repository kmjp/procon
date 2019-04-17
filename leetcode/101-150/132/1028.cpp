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



class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
        vector<int> V;
        FORR(c,S) {
			if(c=='-') {
				if(V.back()>=0) V.push_back(-1);
				else V.back()--;
			}
			else {
				if(V.empty() || V.back()<0) V.push_back(c-'0');
				else V.back()=V.back()*10+c-'0';
			}
		}
		vector<TreeNode*> ST;
		ST.push_back(new TreeNode(V[0]));
		for(int i=1;i<V.size();i+=2) {
			int d=-V[i];
			int v=V[i+1];
			while(ST.size()>d) ST.pop_back();
			if(ST.back()->left==NULL) {
				ST.back()->left=new TreeNode(v);
				ST.push_back(ST.back()->left);
			}
			else {
				ST.back()->right=new TreeNode(v);
				ST.push_back(ST.back()->right);
			}
		}
		return ST[0];
        
    }
};

