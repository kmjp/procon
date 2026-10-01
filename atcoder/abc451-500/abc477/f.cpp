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

int H,W,Q;
int L[202020],R[202020];
int RU[202020],RD[202020],RL[202020],RR[202020];
ll ret[202020];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> sum,nofix;

vector<int> ev[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>Q;
	FOR(i,H) {
		cin>>L[i]>>R[i];
		L[i]--;
	}
	FOR(i,Q) {
		cin>>RU[i]>>RD[i]>>RL[i]>>RR[i];
		RU[i]--;
		RL[i]--;
	}
	// min(R,D);
	
	FOR(i,H) {
		nofix.add(i+1,1);
		ev[R[i]].push_back(i+1);
	}
	FOR(i,Q) {
		ev[RR[i]].push_back(1000000+i);
	}
	FOR(i,W+1) {
		FORR(e,ev[i]) {
			if(e<1000000) {
				nofix.add(e,-1);
				sum.add(e,i);
			}
			else {
				e-=1000000;
				ll cs=sum(RD[e])-sum(RU[e]);
				ll cn=nofix(RD[e])-nofix(RU[e]);
				ret[e]+=cs+cn*i;
			}
		}
		ev[i].clear();
	}
	
	// min(R,C);
	FOR(i,H) {
		sum.add(i+1,-sum(i+1));
		nofix.add(i+1,1);
		ev[R[i]].push_back(i+1);
	}
	FOR(i,Q) {
		ev[RL[i]].push_back(1000000+i);
	}
	FOR(i,W+1) {
		FORR(e,ev[i]) {
			if(e<1000000) {
				nofix.add(e,-1);
				sum.add(e,i);
			}
			else {
				e-=1000000;
				ll cs=sum(RD[e])-sum(RU[e]);
				ll cn=nofix(RD[e])-nofix(RU[e]);
				ret[e]-=cs+cn*i;
			}
		}
		ev[i].clear();
	}
	
	// min(R,D);
	
	FOR(i,H) {
		sum.add(i+1,-sum(i+1));
		nofix.add(i+1,1);
		ev[L[i]].push_back(i+1);
	}
	FOR(i,Q) {
		ev[RR[i]].push_back(1000000+i);
	}
	FOR(i,W+1) {
		FORR(e,ev[i]) {
			if(e<1000000) {
				nofix.add(e,-1);
				sum.add(e,i);
			}
			else {
				e-=1000000;
				ll cs=sum(RD[e])-sum(RU[e]);
				ll cn=nofix(RD[e])-nofix(RU[e]);
				ret[e]-=cs+cn*i;
			}
		}
		ev[i].clear();
	}
	
	// min(R,C);
	FOR(i,H) {
		sum.add(i+1,-sum(i+1));
		nofix.add(i+1,1);
		ev[L[i]].push_back(i+1);
	}
	FOR(i,Q) {
		ev[RL[i]].push_back(1000000+i);
	}
	FOR(i,W+1) {
		FORR(e,ev[i]) {
			if(e<1000000) {
				nofix.add(e,-1);
				sum.add(e,i);
			}
			else {
				e-=1000000;
				ll cs=sum(RD[e])-sum(RU[e]);
				ll cn=nofix(RD[e])-nofix(RU[e]);
				ret[e]+=cs+cn*i;
			}
		}
		ev[i].clear();
	}
	FOR(i,Q) cout<<ret[i]<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
