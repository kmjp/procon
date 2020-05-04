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
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int> V(1,0);
        FORR(r,mat) {
			vector<int> W;
			FORR(a,r) FORR(b,V) W.push_back(b+a);
			sort(ALL(W));
			if(W.size()>k) W.resize(k);
			swap(V,W);
		}
        return V.back();
    }
};

