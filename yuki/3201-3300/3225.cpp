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

ll A1,B1,C1,D1;
ll A2,B2,C2,D2;

array<ll,4> hoge(array<ll,4> L,array<ll,4> R) {
	array<ll,4> M;
	M[0]=L[0]*R[0]+L[1]*R[2];
	M[1]=L[0]*R[1]+L[1]*R[3];
	M[2]=L[2]*R[0]+L[3]*R[2];
	M[3]=L[2]*R[1]+L[3]*R[3];
	return M;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A1>>B1>>C1>>D1;
	cin>>A2>>B2>>C2>>D2;
	
	array<ll,4> P;
	FOR(P[0],67) FOR(P[1],67) FOR(P[2],67) FOR(P[3],67) {
		if((P[0]*P[3]-P[1]*P[2])%67==0) continue;
		auto c=hoge(P,{A1,B1,C1,D1});
		auto d=hoge({A2,B2,C2,D2},P);
		FOR(i,4) if(c[i]%67!=d[i]%67) break;
		if(i==4) {
			cout<<"Yes"<<endl;
			return;
		}
	}
	cout<<"No"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
