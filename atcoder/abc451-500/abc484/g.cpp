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

int N,A,B;
string S,X,Y;
map<pair<int,int>,ll> F,T;
const ll mo=998244353;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>X>>Y;
	N=S.size();
	A=X.size();
	B=Y.size();
	F[{1<<(A-1),0}]=1;
	
	int oka0=0,oka1=0,okb0=0,okb1=0;
	FOR(i,A) {
		if(X[i]=='0'||X[i]=='?') oka0|=1<<i;
		if(X[i]=='1'||X[i]=='?') oka1|=1<<i;
	}
	FOR(i,B) {
		if(Y[i]=='0'||Y[i]=='?') okb0|=1<<i;
		if(Y[i]=='1'||Y[i]=='?') okb1|=1<<i;
	}
		
	
	
	FORR(c,S) {
		T.clear();
		FORR2(m,v,F) {
			int ma=m.first;
			int mb=m.second;
			if(c=='0'||c=='?') {
				int nma=(ma<<1)&oka0;
				int nmb=(mb<<1)&okb0;
				if(((ma&(1<<(A-1)))||(mb&(1<<(B-1))))&&(oka0&1)) nma|=1;
				if(((ma&(1<<(A-1)))||(0))&&(okb0&1)) nmb|=1;
				if(nma||nmb) (T[{nma,nmb}]+=v)%=mo;
				
			}
			if(c=='1'||c=='?') {
				int nma=(ma<<1)&oka1;
				int nmb=(mb<<1)&okb1;
				if(((ma&(1<<(A-1)))||(mb&(1<<(B-1))))&&(oka1&1)) nma|=1;
				if(((ma&(1<<(A-1)))||(0))&&(okb1&1)) nmb|=1;
				if(nma||nmb) (T[{nma,nmb}]+=v)%=mo;
			}
		}
		swap(F,T);
	}
	ll ret=0;
	FORR2(m,v,F) {
		int ma=m.first;
		int mb=m.second;
		if(((ma&(1<<(A-1)))||(mb&(1<<(B-1))))) ret+=v;
	}
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
