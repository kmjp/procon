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

class SCC_BI {
public:
	static const int MV = 210000;
	int NV,time;
	vector<vector<int> > E;
	vector<int> ord,llink,inin;
	stack<int> roots,S;
	vector<int> M; //point to group
	vector<int> ART; // out
	vector<vector<int> > SC; // out
	vector<pair<int,int> > BR; // out
	
	void init(int NV=MV) { this->NV=NV; E.clear(); E.resize(NV);}
	void add_edge(int x,int y) { assert(NV);E[x].push_back(y); E[y].push_back(x); }
	void dfs(int cur,int pre) {
		int art=0,conn=0,i,se=0;
		ord[cur]=llink[cur]=++time;
		S.push(cur); inin[cur]=1; roots.push(cur);
		FOR(i,E[cur].size()) {
			int tar=E[cur][i];
			if(ord[tar]==0) {
				conn++; dfs(tar,cur);
				llink[cur]=min(llink[cur],llink[tar]);
				art += (pre!=-1 && ord[cur]<=llink[tar]);
				if(ord[cur]<llink[tar]) BR.push_back(make_pair(min(cur,tar),max(cur,tar)));
			}
			else if(tar!=pre || se) {
				llink[cur]=min(llink[cur],ord[tar]);
				while(inin[tar]&&ord[roots.top()]>ord[tar]) roots.pop();
			}
			else se++; // double edge
		}
		
		if(cur==roots.top()) {
			SC.push_back(vector<int>());
			while(1) {
				i=S.top(); S.pop(); inin[i]=0;
				SC.back().push_back(i);
				M[i]=SC.size()-1;
				if(i==cur) break;
			}
			sort(SC.back().begin(),SC.back().end());
			roots.pop();
		}
		if(art || (pre==-1&&conn>1)) ART.push_back(cur);
	}
	void scc() {
		SC.clear(),BR.clear(),ART.clear(),M.resize(NV);
		ord.clear(),llink.clear(),inin.clear(),time=0;
		ord.resize(NV);llink.resize(NV);inin.resize(NV);
		for(int i=0;i<NV;i++) if(!ord[i]) dfs(i,-1);
		sort(BR.begin(),BR.end()); sort(ART.begin(),ART.end());
	}
};

template<class V> struct RollingHash {
	static const ll mo0=1000000007,mo1=1000000009;
	static ll mul0,mul1;
	static const ll add0=1000010007, add1=1003333331;
	static vector<ll> pmo[2];
	V s; int l; vector<ll> hash_[2];
	void init(V s) {
		this->s=s; l=s.size(); int i,j;
		hash_[0]=hash_[1]=vector<ll>(1,0);
		if(!mul0) mul0=10009+(((ll)&mul0)>>5)%259,mul1=10007+(((ll)&mul1)>>5)%257;
		if(pmo[0].empty()) pmo[0].push_back(1),pmo[1].push_back(1);
		FOR(i,l) hash_[0].push_back((hash_[0].back()*mul0+add0+s[i])%mo0);
		FOR(i,l) hash_[1].push_back((hash_[1].back()*mul1+add1+s[i])%mo1);
	}
	pair<ll,ll> hash(int l,int r) { // s[l..r]
		if(l>r) return make_pair(0,0);
		while(pmo[0].size()<r+2)
			pmo[0].push_back(pmo[0].back()*mul0%mo0), pmo[1].push_back(pmo[1].back()*mul1%mo1);
		return make_pair((hash_[0][r+1]+(mo0-hash_[0][l]*pmo[0][r+1-l]%mo0))%mo0,
			             (hash_[1][r+1]+(mo1-hash_[1][l]*pmo[1][r+1-l]%mo1))%mo1);
	}
	pair<ll,ll> hash(V s) { init(s); return hash(0,s.size()-1); }
	static pair<ll,ll> concat(pair<ll,ll> L,pair<ll,ll> R,int RL) { // hash(L+R) RL=len-of-R
		while(pmo[0].size()<RL+2) pmo[0].push_back(pmo[0].back()*mul0%mo0), pmo[1].push_back(pmo[1].back()*mul1%mo1);
		return make_pair((R.first + L.first*pmo[0][RL])%mo0,(R.second + L.second*pmo[1][RL])%mo1);
	}
};
template<typename V> vector<ll> RollingHash<V>::pmo[2];
template<typename V> ll RollingHash<V>::mul0;
template<typename V> ll RollingHash<V>::mul1;

ll mo=1000000007;
int N,K;
vector<int> E[101010];
int inloop[101010];
SCC_BI bi;
vector<int> L;
ll H[101010],D[101010],RD[101010],RH[101010];
int phi[101010];

ll modpow(ll a, ll n=mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll comb(int P_,int Q_) {
	if(P_<0 || Q_<0 || Q_>P_) return 0;
	ll ret=1;
	Q_=min(Q_,P_-Q_);
	for(int i=1;i<=Q_;i++) ret=ret*(P_+1-i)%mo*modpow(i,mo-2)%mo;
	return ret;
}
ll hcomb(int P_,int Q_) { return (P_==0&&Q_==0)?1:comb(P_+Q_-1,Q_);};

void dfs2(int cur,int pre) {
	ll momo[2]={1000000007,1000000009};
	vector<ll> prim = {100291,100297,100313,100333,100343,100357,100361,100363,100379,100391};
	vector<pair<ll,ll>> V;
	
	FORR(r,E[cur]) if(r!=pre) {
		dfs2(r,cur);
		V.push_back({H[r],D[r]});
	}
	sort(ALL(V));
	
	int id=0,id2=1;
	ll a=1,b=1;
	FORR(r,V) {
		ll h=r.first>>32, l=r.first-(h<<32);
		(a+=h*prim[(id++)%prim.size()])%=momo[0];
		(b+=l*prim[(id2++)%prim.size()])%=momo[1];
	}
	H[cur]=(a<<32)+b;
	
	D[cur]=K;
	for(int i=0,num=1;i<V.size();i+=num) {
		num=1;
		while(i+num<V.size() && V[i+num-1]==V[i+num]) num++;
		D[cur] = D[cur] * hcomb(V[i].second,num) % mo;
	}
	
	return;
}

void dfs(int cur) {
	inloop[cur]=2;
	L.push_back(cur);
	int i;
	FOR(i,E[cur].size()) if(inloop[E[cur][i]]) {
		if(inloop[E[cur][i]]==1) dfs(E[cur][i]);
		E[cur].erase(E[cur].begin()+i);
		i--;
	}
	dfs2(cur,-1);
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	bi.init(N);
	FOR(i,N) {
		cin>>x;
		E[i].push_back(x-1);
		E[x-1].push_back(i);
		bi.add_edge(i,x-1);
	}
	bi.scc();
	FOR(i,bi.SC.size()) FORR(r,bi.SC[i]) inloop[r]=bi.SC[i].size()>1;
	FOR(i,N) if(inloop[i]) {
		dfs(i);
		break;
	}
	int minper=L.size();
	for(i=1;i<=L.size();i++) if(L.size()%i==0) {
		int ng=0;
		FOR(j,L.size()-i) if(H[L[j]]!=H[L[j+i]] || D[L[j]]!=D[L[j+i]]) ng=1;
		if(ng==0) {
			minper=i;
			break;
		}
	}
	
	ll ret=0;
	
	N=L.size();
	FOR(j,N) RD[j]=D[L[j]], RH[j]=H[L[j]];
	vector<ll> hv,hr;
	FOR(j,2*N) hv.push_back((RD[j%N]*2+RH[j%N])%mo);
	hr=hv;
	reverse(ALL(hr));
	RollingHash<vector<ll>> rhv,rhr;
	rhv.init(hv);
	rhr.init(hr);
	int sym=0;
	FOR(i,N) if(rhv.hash(i,i+N-1)==rhr.hash(N-1-i,N-1-i+N-1)) {
		sym=1;
		rotate(RH,RH+i,RH+N);
		rotate(RD,RD+i,RD+N);
		break;
	}
	
	for(i=1;i<=N/minper;i++) phi[__gcd(i,N/minper)]++;
	// non-symmetrix
	for(i=1;i<=N;i++) if(phi[i]) {
		ll DD=phi[i];
		FOR(j,i*minper) DD=DD*RD[j]%mo;
		ret += DD;
		
		if(sym==1) {
			ll DD=phi[i];
			FOR(j,N) {
				x = (2*N-j+(i-1)*minper)%N;
				if(j<=x) DD=DD*RD[j]%mo;
			}
			ret += DD;
		}
	}
	cout<<ret%mo*modpow((sym+1)*N/minper)%mo<<endl;
	

}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
