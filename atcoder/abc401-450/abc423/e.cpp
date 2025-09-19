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

int N,Q;
ll A[303030];

ll S[303030];
ll SA[303030];
ll SB[303030];

int L[303030],R[303030];
const int DI=600;
vector<pair<int,int>> ev[DI];
ll ret[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) {
		cin>>A[i];
		S[i+1]=S[i]+A[i];
		SA[i+1]=SA[i]+(i+1)*A[i];
	}
	FOR(i,Q) {
		cin>>L[i]>>R[i];
		L[i]--;
		ev[L[i]/DI].push_back({R[i],i});
	}
	
	FOR(j,DI) if(ev[j].size()) {
		sort(ALL(ev[j]));
		ll sum=0;
		int CL=DI*j,CR=CL;
		FORR2(RR,i,ev[j]) {
			int LL=L[i];
			
			while(CR<RR) {
				sum+=(SA[CR+1]-SA[CL])-(S[CR+1]-S[CL])*CL;
				CR++;
			}
			while(CL>LL) {
				CL--;
				sum+=(S[CR]-S[CL])*(CR+1)-(SA[CR]-SA[CL]);
			}
			while(CL<LL) {
				sum-=(S[CR]-S[CL])*(CR+1)-(SA[CR]-SA[CL]);
				CL++;
			}
			
			ret[i]=sum;
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
