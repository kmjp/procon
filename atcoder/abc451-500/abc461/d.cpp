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

int H,W,K;
string S[505];
int V[505][505];
int M[505*505];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) V[y][x+1]=V[y][x]+(S[y][x]=='1');
	}
	ll ret=0;
	for(int L=0;L<W;L++) for(int R=L+1;R<=W;R++) {
		int cur=0;
		M[cur]++;
		FOR(y,H) {
			cur+=V[y][R]-V[y][L];
			if(cur>=K) ret+=M[cur-K];
			M[cur]++;
		}
		cur=0;
		M[cur]=0;
		FOR(y,H) {
			cur+=V[y][R]-V[y][L];
			M[cur]=0;
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
