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

int T;
ll A,B,V,M;

ll hoge2(ll L,ll R,ll H,ll W) {
	
	if(L==0) return 0;
	
	ll ma=W/H;
	ll okL=(L+H-1)/H;
	ll okR=R/H;
	if(okL<=okR) {
		return okL;
	}
	else {
		ll p=hoge2((H-R%H)%H,(H-L%H)%H,W%H,H);
		return (L+p*W+H-1)/H;
	}
	
}

ll hoge(ll A,ll B,ll V,ll M) {
	if(V%B>=M-A+1) return 0;
	ll L=M-A+1-V%B;
	ll R=B-1-V%B;
	if(L>R) return 0;
	
	ll k=hoge2(L,R,A,B);
	return k+(k*A+V)/B;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>T;
	while(T--) {
		cin>>A>>B>>V>>M;
		if(A+B-1<=M) {
			cout<<(M+1)<<endl;
			continue;
		}
		ll ret=1;
		ret+=hoge(A,B,V,M);
		ret+=hoge(A,B,M-V,M);
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

