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

int N,A[101010];

ll D[101010];

int nexv(int d,int x) {
	if(x<=d) return 1<<20;
	int v=(x+d-1)/d-1;
	
	int nv=x/v;
	while((x+nv-1)/nv==(x+d-1)/d) nv++;
	return nv;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int ma=0;
	FOR(i,N) {
		cin>>A[i+1];
		ma=max(ma,A[i+1]);
	}
	
	FOR(i,N) if(A[i]<A[i+1]) {
		x=A[i];
		y=A[i+1];
		int d=1;
		int pd=y-x;
		D[d]+=pd;
		while(d<=ma) {
			int nex=nexv(d,x);
			int ney=nexv(d,y);
			d=min(nex,ney);
			if(d>ma) break;
			D[d]-=pd;
			pd=(y+d-1)/d-(x+d-1)/d;
			D[d]+=pd;
			
		}
	}
	
	for(i=1;i<=ma;i++) {
		D[i]+=D[i-1];
		cout<<D[i]<<" ";
	}
	cout<<endl;
	
	
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
