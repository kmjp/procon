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

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};


class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
		BIT<int,18> bt;
		ZERO(bt.bit);
		vector<int> C(n);
		vector<int> E[n];
		FORR(e,edges) {
			C[e[0]-1]++,C[e[1]-1]++;
			E[e[0]-1].push_back(e[1]-1);
			E[e[1]-1].push_back(e[0]-1);
		}
		vector<int> R(queries.size());
		int i,j;
		ll ret=0;
		FOR(i,n) {
			FORR(t,E[i]) if(t<i) {
				bt.add(C[t],-1);
				C[t]--;
				bt.add(C[t],1);
			}
			FOR(j,queries.size()) {
				R[j]+=bt(1<<17)-bt(queries[j]-C[i]);
			}
			
			FORR(t,E[i]) if(t<i) {
				bt.add(C[t],-1);
				C[t]++;
				bt.add(C[t],1);
			}
			bt.add(C[i],1);
			
		}
		return R;
        
    }
};
