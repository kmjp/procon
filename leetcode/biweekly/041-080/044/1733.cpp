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




int C[505][505];


class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
		int m=languages.size();
		int mi=505;
		int i;
		ZERO(C);
		FOR(i,m) {
			FORR(c,languages[i]) C[i][c-1]=1;
		}
		vector<vector<int>> need;
		FORR(f,friendships) {
			int ok=0;
			FOR(i,n) if(C[f[0]-1][i]&&C[f[1]-1][i]) ok=1;
			if(ok==0) need.push_back({f[0]-1,f[1]-1});
		}
		
		FOR(i,n) {
			set<int> S;
			FORR(f,need) {
				if(C[f[0]][i]==0) S.insert(f[0]);
				if(C[f[1]][i]==0) S.insert(f[1]);
			}
			mi=min(mi,(int)S.size());
		}
        return mi;
    }
};

