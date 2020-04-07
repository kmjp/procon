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

int A,B,C,N;
vector<ll> Xs;
int P[101010],Q[101010],R[101010],S[101010],T[101010];

template<int um> class UF {
	public:
	vector<int> par,rank,cnt;
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit() {int i; FOR(i,um) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
UF<505050> uf;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>C;
	Xs.push_back(0);
	Xs.push_back(A);
	Xs.push_back(A+1);
	Xs.push_back(A+B+1);
	
	cin>>N;
	vector<pair<ll,int>> ev;
	FOR(i,N) {
		cin>>P[i]>>Q[i]>>R[i]>>S[i]>>T[i];
		P[i]--;
		R[i]+=A;
		S[i]+=A+1;
		
		Xs.push_back(P[i]);
		Xs.push_back(Q[i]);
		Xs.push_back(R[i]);
		Xs.push_back(S[i]);
		ev.push_back({T[i],i});
	}
	sort(ALL(Xs));
	Xs.erase(unique(ALL(Xs)),Xs.end());
	set<int> alive,yet;
	alive.insert(Xs.size());
	yet.insert(Xs.size());
	FOR(i,Xs.size()) {
		alive.insert(i);
		yet.insert(i);
	}
	sort(ALL(ev));
	reverse(ALL(ev));
	ll ret=0;
	FORR(e,ev) {
		x=e.second;
		P[x]=lower_bound(ALL(Xs),P[x])-Xs.begin();
		Q[x]=lower_bound(ALL(Xs),Q[x])-Xs.begin();
		R[x]=lower_bound(ALL(Xs),R[x])-Xs.begin();
		S[x]=lower_bound(ALL(Xs),S[x])-Xs.begin();
		auto it=yet.lower_bound(P[x]);
		while(*it<Q[x]) {
			ret+=e.first*(Xs[*it+1]-Xs[*it]-1);
			it=yet.erase(it);
		}
		it=yet.lower_bound(R[x]);
		while(*it<S[x]) {
			ret+=e.first*(Xs[*it+1]-Xs[*it]-1);
			it=yet.erase(it);
		}
		auto it2=alive.lower_bound(P[x]);
		if(*it2>P[x]) it2--;
		y=*it2;
		it2=alive.lower_bound(y+1);
		while(*it2<Q[x]) {
			if(uf[y]!=uf[*it2]) {
				uf(y,*it2);
				ret+=e.first;
			}
			it2=alive.erase(it2);
		}
		it2=alive.lower_bound(R[x]);
		if(*it2>R[x]) it2--;
		r=*it2;
		it2=alive.lower_bound(r+1);
		while(*it2<S[x]) {
			if(uf[r]!=uf[*it2]) {
				uf(r,*it2);
				ret+=e.first;
			}
			it2=alive.erase(it2);
		}
		if(uf[r]!=uf[y]) {
			uf(r,y);
			ret+=e.first;
		}
	}
	int num=0;
	FOR(i,Xs.size()) if(uf[i]==i) num++;
	if(num==3) cout<<ret<<endl;
	else cout<<-1<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
