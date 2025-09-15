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

int N;
int A[202020];
vector<int> P,M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		if(A[i]>=0) P.push_back(A[i]);
		else M.push_back(-A[i]);
	}
	sort(ALL(P));
	sort(ALL(M));
	
	ll ret=0;
	if(M.empty()) {
		ret=P.back()-P[0];
	}
	else if(P.empty()) {
		FORR(a,M) ret+=2*a;
		ret-=M[N-1]+M[N-2];
	}
	else {
		ll a=0,b=0;
		//P‚ª‹´
		a=P.back();
		FORR(v,M) ret+=2*v;
		a=a+ret-M.back();
		if(M.size()==1) {
			b=1LL<<60;
		}
		else {
			FORR(v,M) b+=2*v;
			b+=2*P.back();
			b-=M.back();
			b-=M[M.size()-2];
		}
		ret=min(a,b);
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
