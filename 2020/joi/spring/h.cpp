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

int N,M;
ll L,C;
ll A[402020];
ll B[402020];
vector<int> first[202020];
int nex[202020];
ll nd[202020];

int inloop[202020];
ll DT[202020];
int root[202020];
vector<int> RE[202020];
vector<int> E[202020];

int Q;
int V[202020];
ll T[202020];
vector<int> ev[202020];
ll ret[202020];

vector<ll> Ts;
vector<ll> LA[202020];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;


pair<ll,int> dfs(int cur,vector<int>& V) {
	if(root[cur]>=0) return {DT[cur],root[cur]};
	
	inloop[cur]=2;
	
	if(inloop[nex[cur]]==2) {
		int flag=0;
		FORR(v,V) {
			if(v==nex[cur]) flag=1;
			if(flag) E[cur].push_back(v);
			inloop[v]=flag;
		}
		root[cur]=cur;
		inloop[cur]=1;
		FORR(f,first[cur]) Ts.push_back(f);
		return {0,cur};
	}
	
	V.push_back(cur);
	auto r=dfs(nex[cur],V);
	DT[cur]=r.first+nd[cur];
	root[cur]=r.second;
	V.pop_back();
	if(inloop[cur]==2) inloop[cur]=0;
	
	FORR(f,first[cur]) Ts.push_back(f+DT[cur]);
	return {DT[cur],root[cur]};
	
}

void dfs2(int cur) {
	FORR(e,ev[cur]) {
		ll t=T[e]+DT[cur];
		int x=lower_bound(ALL(Ts),t+1)-Ts.begin()-1;
		ret[e]-=bt(x);
	}
	
	FORR(e,RE[cur]) if(DT[e]>DT[cur]) dfs2(e);
	
	FORR(f,first[cur]) {
		int x=lower_bound(ALL(Ts),f+DT[cur])-Ts.begin();
		LA[root[cur]].push_back(f+DT[cur]);
		bt.add(x,1);
	}
	
	FORR(e,ev[cur]) {
		ll t=T[e]+DT[cur];
		int x=lower_bound(ALL(Ts),t+1)-Ts.begin()-1;
		ret[e]+=bt(x);
	}
	
}

void hoge(int cur) {
	ll tl=DT[nex[cur]]+nd[cur];
	vector<ll> m;
	vector<pair<ll,int>> eves;
	m.push_back(0);
	FORR(e,ev[cur]) {
		m.push_back(T[e]%tl);
		eves.push_back({T[e],e});
	}
	FORR(e,LA[cur]) {
		m.push_back(e%tl);
		eves.push_back({e+tl,-1});
	}
	sort(ALL(m));
	m.erase(unique(ALL(m)),m.end());
	
	sort(ALL(eves));
	
	int num=0,x;
	ll bs=0;
	/*
	cout<<"!"<<cur<<"  ";
	FORR(e,eves) cout<<e.first<<":"<<e.second<<" ";
	cout<<endl;
	*/
	FORR(e,eves) {
		if(e.second==-1) {
			x=lower_bound(ALL(m),e.first%tl)-m.begin();
			bt.add(x,1);
			num++;
			bs+=e.first/tl;
		}
		else {
			ll p=e.first/tl;
			ll q=e.first%tl;
			x=lower_bound(ALL(m),q)-m.begin();
			//cout<<e.second<<" "<<p<<" "<<num<<" "<<bs<<" "<<bt(x)<<endl;
			ret[e.second]+=p*num-bs+bt(x);
		}
	}
	
	FORR(e,eves) if(e.second==-1) {
		x=lower_bound(ALL(m),e.first%tl)-m.begin();
		bt.add(x,-1);
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>L>>C;
	FOR(i,N) {
		cin>>A[i];
		A[i+N]=A[i]+L;
	}
	FOR(i,M) {
		cin>>B[i];
		x=lower_bound(A,A+2*N,B[i]+L)-A;
		first[(x-1)%N].push_back(B[i]+L-A[x-1]);
	}
	
	FOR(i,N) {
		x=lower_bound(A,A+2*N,A[i]+L-C%L+1)-A-1;
		nex[i]=x%N;
		RE[x%N].push_back(i);
		ll d=A[i]-A[x%N];
		if(d<0) d+=L;
		if(d<C) d=d+(C-d+L-1)/L*L;
		nd[i]=d;
	}
	
	MINUS(root);
	FOR(i,N) if(root[i]==-1) {
		vector<int> v;
		dfs(i,v);
	}
	
	Ts.push_back(-1);
	Ts.push_back(1LL<<60);
	sort(ALL(Ts));
	Ts.erase(unique(ALL(Ts)),Ts.end());
	
	cin>>Q;
	FOR(i,Q) {
		cin>>V[i]>>T[i];
		V[i]--;
		ev[V[i]].push_back(i);
	}
	
	FOR(i,N) if(root[i]==i) dfs2(i);
	FOR(i,Q) if(root[V[i]]!=V[i] && inloop[V[i]]) {
		T[i]+=DT[V[i]];
		ev[root[V[i]]].push_back(i);
	}
	ZERO(bt.bit);
	FOR(i,N) if(root[i]==i && ev[i].size()) hoge(i);
	//FOR(i,N) cout<<i<<" "<<inloop[i]<<" "<<nex[i]<<" "<<nd[i]<<" "<<DT[i]<<" "<<root[i]<<endl;
	
	FOR(i,Q) cout<<ret[i]<<endl;

}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
