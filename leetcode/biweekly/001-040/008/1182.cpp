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


int D[505050][3];

class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
		int pre[3]={-100000000,-100000000,-100000000};
		int i,j;
		FOR(i,colors.size()) {
			pre[colors[i]-1]=i;
			FOR(j,3) D[i][j]=i-pre[j];
		}
		FOR(j,3) pre[j]=100000000;
		for(i=colors.size()-1;i>=0;i--) {
			pre[colors[i]-1]=i;
			FOR(j,3) D[i][j]=min(D[i][j],pre[j]-i);
		}
		
		vector<int> R;
		FORR(q,queries) {
			int ret=D[q[0]][q[1]-1];
			if(ret>1<<20) ret=-1;
			R.push_back(ret);
		}
        return R;
    }
};


