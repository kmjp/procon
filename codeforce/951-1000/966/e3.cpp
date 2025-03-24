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
int H,W,K;
int A[202020];
ll num[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W>>K;
		FOR(y,H) FOR(x,W) {
			int miy=max(0,y-(K-1));
			int may=min(y,H-K);
			int mix=max(0,x-(K-1));
			int maax=min(x,W-K);
			num[y*W+x]=1LL*(may+1-miy)*(maax+1-mix);
		}
		sort(num,num+H*W);
		reverse(num,num+H*W);
		int w;
		cin>>w;
		FOR(i,w) {
			cin>>A[i];
		}
		sort(A,A+w);
		reverse(A,A+w);
		ll ret=0;
		FOR(i,w) ret+=A[i]*num[i];
		cout<<ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
