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

int L[202][202];
int R[202][202];

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& G) {
        int H=G.size();
        int W=G[0].size();
        ZERO(L);
        ZERO(R);
        int y,x;
        for(y=1;y<=H;y++) {
	        for(x=0;x<=W+1;x++) {
				if(x) R[y][x]+=R[y-1][x-1];
				L[y][x]+=L[y-1][x+1];
				if(x-1>=0&&x-1<W) L[y][x]+=G[y-1][x-1],R[y][x]+=G[y-1][x-1];
			}
		}
		
		vector<int> ret;
		FOR(y,H) FOR(x,W) {
			int i;
			for(i=0;;i++) {
				if(y+2*i>=H) break;
				if(x+i>=W) break;
				if(x-i<0) break;
				int sum=R[y+1+i][x+1+i]-R[y][x];
				sum+=L[y+1+i][x+1-i]-L[y+1][x+1];
				sum+=R[y+1+2*i][x+1]-R[y+1+2*i-i][x+1-i];
				sum+=L[y+1+2*i][x+1]-L[y+1+2*i-i][x+1+i];
				if(i) sum-=G[y+2*i][x];
				ret.push_back(sum);
			}
		}
		sort(ALL(ret));
		reverse(ALL(ret));
		ret.erase(unique(ALL(ret)),ret.end());
        if(ret.size()>3) ret.resize(3);
        return ret;
    }
};

