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
    vector<int> findOriginalArray(vector<int>& changed) {
		map<int,int> M;
		FORR(a,changed) M[a]++;
		vector<int> V,V2;
		while(M.size()) {
			int cur=M.rbegin()->first;
			if(cur%2) {
				return V2;
			}
			cur/=2;
			M[cur*2]--;
			if(M[cur]==0) return V2;
			M[cur]--;
			if(M[cur]==0) M.erase(cur);
			if(M[cur*2]==0) M.erase(cur*2);
			V.push_back(cur);
		}
        return V;
    }
};
