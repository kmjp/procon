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
    vector<int> processQueries(vector<int>& queries, int m) {
		vector<int> V,R;
		int i;
		FOR(i,m) V.push_back(i+1);
		FORR(q,queries) {
			FOR(i,m) if(V[i]==q) {
				R.push_back(i);
				rotate(V.begin(),V.begin()+i,V.begin()+i+1);
				break;
			}
		}
			
		return R;
        
    }
};
