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
ll X[201010],Y[201010];

ll area(int a,int b,int c) {
	ll A=(X[b]-X[a])*(Y[c]-Y[a])-(Y[b]-Y[a])*(X[c]-X[a]);
	
	return 4*abs(A);
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		X[N+i]=X[i];
		Y[N+i]=Y[i];
	}
	ll S=0;
	for(i=2;i<N;i++) S+=area(0,i-1,i);
	ll T=S/4;
	ll ret=S;
	
	ll cur=0;
	int L,R;
	for(L=0,R=0;L<N;L++) {
		while(cur<T) {
			ret=min(ret,abs(cur-T));
			cur+=area(L,R,R+1);
			R++;
		}
		ret=min(ret,abs(cur-T));
		cur-=area(L,L+1,R);
	}
	cout<<ret<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
