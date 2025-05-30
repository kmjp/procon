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

int N,T;
ll A[4040404];
int K;
int ok[4040404];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>T;
	FOR(i,N-1) cin>>A[i];
	cin>>K;
	FOR(i,K) {
		cin>>x;
		ok[x-1]++;
	}
	ll cur=T;
	int lef=0;
	int used=0;
	FOR(i,N-1) {
		if(ok[i]) lef++;
		while(cur<=A[i]&&lef) {
			lef--;
			used++;
			cur+=10;
		}
		if(cur<=A[i]) {
			cout<<-1<<endl;
			return;
		}
		cur-=A[i];
	}
	cout<<used<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
