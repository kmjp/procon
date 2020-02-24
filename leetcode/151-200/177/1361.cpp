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
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int in[10101]={};
        int i;
        FOR(i,n) {
			if(leftChild[i]!=-1) in[leftChild[i]]++;
			if(rightChild[i]!=-1) in[rightChild[i]]++;
		}
		return count(in,in+n,1)==n-1 && count(in,in+n,0)==1;
    }
};


