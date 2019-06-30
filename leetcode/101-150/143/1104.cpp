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
    vector<int> pathInZigZagTree(int label) {
		vector<int> V[22];
		int x,y;
		int a,b;
		FOR(x,21) {
			int st=1<<x;
			FOR(y,1<<x) {
				V[x].push_back(st);
				st++;
			}
			if(x%2) reverse(ALL(V[x]));
			FOR(y,1<<x) if(V[x][y]==label) a=x,b=y;
		}
		
		vector<int> R;
		while(a>=0) {
			R.push_back(V[a][b]);
			b/=2;
			a--;
		}
		reverse(ALL(R));
		return R;
        
    }};

