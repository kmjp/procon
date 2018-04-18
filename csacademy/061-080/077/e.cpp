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

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};

int H,W,K,Q;
int X[101010],Y[101010];
vector<int> RR[303030];
vector<int> RC[303030];
int U[303030],L[303030],D[303030],R[303030];
const int DI=200;
vector<pair<int,int>> evUD[200], evLR[200];
int NC[303030],NR[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K>>Q;
	FOR(i,K) {
		cin>>Y[i]>>X[i];
		RR[Y[i]].push_back(X[i]);
		RC[X[i]].push_back(Y[i]);
	}
	FOR(i,Q) {
		cin>>U[i]>>L[i]>>D[i]>>R[i];
		D[i]++;
		R[i]++;
		evUD[U[i]/DI].push_back({D[i],i});
		evLR[L[i]/DI].push_back({R[i],i});
	}
	FOR(i,200) if(evUD[i].size()) {
		BIT<int,16> bt;
		ZERO(bt.bit);
		sort(ALL(evUD[i]));
		int cnt[30303]={};
		
		int UU=i*DI,DD=i*DI;
		FORR(e,evUD[i]) {
			while(DD<e.first) {
				FORR(r,RR[DD]) if(++cnt[r]==1) bt.add(r,1);
				DD++;
			}
			while(UU<U[e.second]) {
				FORR(r,RR[UU]) if(--cnt[r]==0) bt.add(r,-1);
				UU++;
			}
			while(U[e.second]<UU) {
				UU--;
				FORR(r,RR[UU]) if(++cnt[r]==1) bt.add(r,1);
			}
			NC[e.second]=bt(R[e.second]-1)-bt(L[e.second]-1);
		}
	}
	FOR(i,200) if(evLR[i].size()) {
		BIT<int,16> bt;
		ZERO(bt.bit);
		sort(ALL(evLR[i]));
		int cnt[30303]={};
		
		int LL=i*DI,RR=i*DI;
		FORR(e,evLR[i]) {
			while(RR<e.first) {
				FORR(r,RC[RR]) if(++cnt[r]==1) bt.add(r,1);
				RR++;
			}
			while(LL<L[e.second]) {
				FORR(r,RC[LL]) if(--cnt[r]==0) bt.add(r,-1);
				LL++;
			}
			while(L[e.second]<LL) {
				LL--;
				FORR(r,RC[LL]) if(++cnt[r]==1) bt.add(r,1);
			}
			NR[e.second]=bt(D[e.second]-1)-bt(U[e.second]-1);
		}
	}
	
	FOR(i,Q) {
		cout<<(R[i]-L[i])*(D[i]-U[i])-(R[i]-L[i]-NC[i])*(D[i]-U[i]-NR[i])<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
