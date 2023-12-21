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

int T,N,P[202020],re[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) {
			cin>>P[i];
			P[i]--;
			re[P[i]]=i;
		}
		deque<int> D;
		int L,R;
		if(N%2) {
			D.push_back(re[i/2]);
			L=i/2-1;
			R=i/2+1;
		}
		else {
			L=i/2-1;
			R=i/2;
		}
		for(;L>=0;L--,R++) {
			if(re[L]>re[R]) break;
			if(D.size()&&D.front()<re[L]) break;
			if(D.size()&&D.back()>re[R]) break;
			D.push_back(re[R]);
			D.push_front(re[L]);
		}
		cout<<(N-D.size())/2<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
