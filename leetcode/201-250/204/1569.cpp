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



struct Node {
	int val;
	int L,R;
};
const ll mo=1000000007;

ll comb(ll N_, ll C_) {
	const int NUM_=400001;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

Node node[1010];
int nex;
class Solution {
public:
	void dfs(int cur,int v) {
		if(v<node[cur].val) {
			if(node[cur].L==-1) {
				node[cur].L=nex;
				node[nex].val=v;
				node[nex].L=node[nex].R=-1;
				nex++;
			}
			else {
				dfs(node[cur].L,v);
			}
		}
		else {
			if(node[cur].R==-1) {
				node[cur].R=nex;
				node[nex].val=v;
				node[nex].L=node[nex].R=-1;
				nex++;
			}
			else {
				dfs(node[cur].R,v);
			}
		}
	}
	
	pair<ll,ll> dfs2(int cur) {
		if(node[cur].L==-1&&node[cur].R==-1) {
			return {1,1};
		}
		if(node[cur].L==-1) {
			auto p=dfs2(node[cur].R);
			p.first++;
			return p;
		}
		if(node[cur].R==-1) {
			auto p=dfs2(node[cur].L);
			p.first++;
			return p;
		}
		auto p=dfs2(node[cur].L);
		auto q=dfs2(node[cur].R);
		auto r=q;
		r.first=p.first+q.first+1;
		r.second=p.second*q.second%mo*comb(p.first+q.first,p.first)%mo;
		return r;
	}
	
	
	
    int numOfWays(vector<int>& nums) {
		int N;
		int i;
		int first=1;
		FORR(n,nums) {
			if(first) {
				node[0].val=n;
				node[0].L=node[0].R=-1;
				nex=1;
				first=0;
			}
			else {
				dfs(0,n);
			}
		}
		return (dfs2(0).second+mo-1)%mo;
		
        
    }
};
