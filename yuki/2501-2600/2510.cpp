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

ll X;
unordered_map<int,int> C;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X;
	int a,b,c,d,e,f;
	for(d=0;d<=300;d++) {
		for(e=d;e<=300;e++) for(f=e;f<=300;f++) {
			int v=d*d*d+e*e*e+f*f*f;
			if(v*2>=X&&v<=X) C[v]++;
		}
	}
	ll ret=0;
	for(c=0;c<=300;c++) {
		for(b=c;b>=0;b--) for(a=b;a>=0;a--) {
			if(C.count(X-c*c*c-b*b*b-a*a*a)) ret+=C[X-c*c*c-b*b*b-a*a*a];
		}
		d=c;
		for(e=d;e<=300;e++) for(f=e;f<=300;f++) {
			int v=d*d*d+e*e*e+f*f*f;
			if(v*2>=X&&v<=X) C[v]--;
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
