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
string X,S[1010];
int n[1010],c[1010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X;
	FOR(i,N) {
		string S;
		cin>>S;
		x=y=0;
		FOR(j,26) {
			k=min(3,(int)count(ALL(X),'A'+j))+min(2,(int)count(ALL(S),'A'+j));
			if(k>y) y=k,x=j;
		}
		n[i]=y;
		c[i]=x;
	}
	
	FOR(i,N) {
		FOR(j,N) if(i!=j) {
			if(n[i]<n[j]) break;
			if(n[i]>n[j]) continue;
			if(c[i]<c[j]) continue;
			if(c[i]>c[j]) break;
			if(j<i) break;
		}
		if(j==N) cout<<i+1<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
