#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,18> bt;

int N,K,Q;
int A[151515],M[151515],C[151515];
int P[151515],X[151515];
int L[151515],R[151515],D[151515],U[151515];

const int DI=400;
vector<pair<int,int>> ev[DI];
ll ret[151515];

void setv(int i,int v) {
	if(v!=C[i]) {
		bt.add(i,v-C[i]);
		C[i]=v;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>Q;
	FOR(i,N) {
		cin>>A[i];
		setv(i,A[i]);
	}
	FOR(i,K) {
		cin>>P[i]>>X[i];
		P[i]--;
	}
	FOR(i,Q) {
		cin>>L[i]>>R[i]>>D[i]>>U[i];
		L[i]--,D[i]--;
		if(R[i]-L[i]<DI+10) {
			for(j=L[i];j<R[i];j++) {
				if(X[j]>C[P[j]]) setv(P[j],X[j]);
				ret[i]=bt(U[i]-1)-bt(D[i]-1);
			}
			for(j=L[i];j<R[i];j++) setv(P[j],A[P[j]]);
		}
		else {
			ev[L[i]/DI].push_back({R[i],i});
		}
	}
	FOR(i,DI) {
		FOR(j,N) {
			M[j]=A[j];
			setv(j,M[j]);
		}
		sort(ALL(ev[i]));
		int CR=(i+1)*DI;
		FORR2(r,x,ev[i]) {
			int TR=R[x];
			while(CR<TR) {
				if(X[CR]>M[P[CR]]) {
					M[P[CR]]=X[CR];
					setv(P[CR],X[CR]);
				}
				CR++;
			}
			for(j=L[x];j<(i+1)*DI;j++) {
				if(X[j]>C[P[j]]) setv(P[j],X[j]);
			}
			ret[x]=bt(U[x]-1)-bt(D[x]-1);
			for(j=L[x];j<(i+1)*DI;j++) setv(P[j],M[P[j]]);
			
		}
		
	}
	FOR(i,Q) cout<<ret[i]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
