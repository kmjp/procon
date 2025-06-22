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
int N,M;
int L[202020],R[202020];
int X[202020],V[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M>>x;
		FOR(i,N) cin>>L[i]>>R[i];
		FOR(i,M) cin>>X[i]>>V[i];
		ll cur=0;
		int num=0;
		int pos=0;
		priority_queue<int> Q;
		FOR(i,N) {
			while(pos<M&&X[pos]<L[i]) {
				Q.push(V[pos]);
				pos++;
			}
			while(cur<=R[i]-L[i]&&Q.size()) {
				num++;
				cur+=Q.top();
				Q.pop();
			}
			if(cur<=R[i]-L[i]) break;
		}
		if(i<N) cout<<-1<<endl;
		else cout<<num<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
