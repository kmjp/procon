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

ll A[3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A[0]>>A[1]>>A[2];
	sort(A,A+3);
	ll ret=0;
	ll a=A[1]-A[0];
	ret+=a;
	A[1]-=a;
	A[2]-=a;
	ll v=A[2]-A[1];
	if(A[1]<v) {
		cout<<-1<<endl;
	}
	else {
		ret+=2*v;
		A[0]-=v;
		A[1]-=v;
		A[2]-=2*v;
		ret+=A[0];
		cout<<ret<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
