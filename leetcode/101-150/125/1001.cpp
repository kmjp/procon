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

map<int,int> Y,X,YmX,YpX;
set<pair<int,int>> S;

class Solution {
public:
	void add(int y,int x) {
		S.insert({y,x});
		Y[y]++;
		X[x]++;
		YmX[y-x]++;
		YpX[y+x]++;
	}
	void del(int y,int x) {
		if(S.count({y,x})==0) return;
		S.erase({y,x});
		Y[y]--;
		X[x]--;
		YmX[y-x]--;
		YpX[y+x]--;
	}

    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
		S.clear();
		Y.clear();
		X.clear();
		YmX.clear();
		YpX.clear();
        
        FORR(a,lamps) add(a[1],a[0]);
        
        vector<int> R;
        FORR(q,queries) {
			int ok=Y[q[1]]+X[q[0]]+YmX[q[1]-q[0]]+YpX[q[1]+q[0]];
			R.push_back(ok>0);
			for(int y=q[1]-1;y<=q[1]+1;y++) for(int x=q[0]-1;x<=q[0]+1;x++) del(y,x);
		}
		return R;
    }
};
