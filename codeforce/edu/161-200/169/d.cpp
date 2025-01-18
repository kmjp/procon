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
int N,Q;
int C[202020];
int L[16][202020];
int R[16][202020];
int pre[16];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>Q;
		FOR(j,16) pre[j]=-1<<20;
		FOR(i,N) {
			cin>>s;
			C[i]=0;
			x=y=0;
			if(s[0]=='G') x+=1;
			if(s[0]=='B') x+=2;
			if(s[0]=='Y') x+=3;
			if(s[1]=='G') y+=1;
			if(s[1]=='B') y+=2;
			if(s[1]=='Y') y+=3;
			C[i]=(1<<x)|(1<<y);
			FOR(j,16) L[j][i]=pre[j];
			pre[C[i]]=i;
		}
		FOR(j,16) pre[j]=1<<20;
		for(i=N-1;i>=0;i--) {
			FOR(j,16) R[j][i]=pre[j];
			pre[C[i]]=i;
		}
		while(Q--) {
			int a,b;
			cin>>a>>b;
			a--,b--;
			if(a>b) swap(a,b);
			int ma=C[a],mb=C[b];
			
			int ret=1<<20;
			if(ma&mb) ret=b-a;
			else {
				int mask;
				FOR(mask,16) if(__builtin_popcount(mask)==2&&(mask&ma)&&(mask&mb)) {
					if(L[mask][b]>=a) ret=b-a;
					ret=min(ret,2*R[mask][b]-a-b);
					ret=min(ret,a+b-2*L[mask][a]);
				}
			}
			if(ret>2*N) ret=-1;
			cout<<ret<<endl;
			
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
