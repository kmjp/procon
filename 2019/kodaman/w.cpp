#include <bits/stdc++.h>
using namespace std;
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

static ll const def=-1LL<<60;
template<class V,int NV> class SegTree_3 {
public:
	vector<V> val, ma;
	SegTree_3(){
		int i;
		val.resize(NV*2,0); ma.resize(NV*2,0);
	};
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return ma[k];
		return val[k]+max(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			val[k]+=v;
			ma[k]+=v;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=val[k]+max(ma[k*2],ma[k*2+1]);
		}
	}
};


const int NUMC=26;
class Trie {
public:
	vector<vector<int> > V;
	vector<int> L,R;
	int id;
	int find(string s) {
		int cur=0;
		ITR(it,s) if((cur=V[cur][*it+1])==0) return -1;
		return cur;
	}
	
	void dfs(int cur) {
		L[cur]=id++;
		FORR(c,V[cur]) if(c) dfs(c);
		R[cur]=id;
	}
	void create(vector<string> S) { // 0 is for backtrack
		V.clear();
		V.push_back(vector<int>(NUMC+1));
		sort(S.begin(),S.end());
		ITR(it,S) {
			int cur=0;
			ITR(c,(*it)) {
				if(V[cur][*c+1]==0) V.push_back(vector<int>(NUMC+1)),V[cur][*c+1]=V.size()-1;
				cur=V[cur][*c+1];
			}
		}
		L.resize(V.size());
		R.resize(V.size());
		id=0;
		dfs(0);
	}
};

int N,Q;
vector<string> S;
string base;
ll A[101010];
SegTree_3<ll,1<<20> st;
Trie T;




void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	S.resize(N);
	FOR(i,N) {
		cin>>S[i]>>A[i];
		FORR(c,S[i]) c-='a';
	}
	
	T.create(S);
	st.update(0,(1<<20)-1,-1LL<<60);
	FOR(i,N) {
		x=T.find(S[i]);
		st.update(T.L[x],T.L[x]+1,(1LL<<60)+A[i]);
	}
	
	cin>>base;
	FORR(c,base) c-='a';
	
	
	while(Q--) {
		cin>>i>>x>>y;
		
		int cur=T.find(base.substr(x-1,y-x+1));
		
		if(i==1) {
			ll b;
			cin>>b;
			st.update(T.L[cur],T.R[cur],b);
		}
		else {
			cout<<st.getval(T.L[cur],T.R[cur])<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
