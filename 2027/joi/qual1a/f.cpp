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

int N,X,Y;
int A[202020],B[202020];
vector<int> P,Q;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X>>Y;
	FOR(i,N) cin>>A[i];
	FOR(i,N) cin>>B[i];
	
	ll ret=0;
	FOR(i,N) {
		ret+=min(A[i],B[i]);
		if(A[i]>B[i]) {
			P.push_back(A[i]-B[i]);
		}
		else {
			Q.push_back(B[i]-A[i]);
		}
	}
	sort(ALL(P));
	sort(ALL(Q));
	reverse(ALL(P));
	reverse(ALL(Q));
	FOR(i,min(X,(int)P.size())) ret+=P[i];
	FOR(i,min(Y,(int)Q.size())) ret+=Q[i];
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
