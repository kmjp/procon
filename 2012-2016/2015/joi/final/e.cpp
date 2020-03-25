#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int H,W,ML,P;
int S[4040][4040];
int R[4040][4040];
int D[4040][4040];
int L[4040][4040];
int U[4040][4040];
int RD[4040][4040];
int LU[4040][4040];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,12> bt;
vector<int> add[4040];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>ML>>P;
	FOR(i,P) {
		cin>>y>>x;
		S[y-1][x-1]=1;
	}
	FOR(y,H) {
		for(x=W-1;x>=0;x--) if(S[y][x]==0) R[y][x]=1+R[y][x+1];
		FOR(x,W) if(S[y][x]==0) L[y][x]=1+(x?L[y][x-1]:0);
	}
	FOR(x,W) {
		for(y=H-1;y>=0;y--) if(S[y][x]==0) D[y][x]=1+D[y+1][x];
		FOR(y,H) if(S[y][x]==0) U[y][x]=1+(y?U[y-1][x]:0);
	}
	FOR(y,H) FOR(x,W) {
		RD[y][x]=min(R[y][x],D[y][x]);
		LU[y][x]=min(L[y][x],U[y][x]);
	}
	
	ll ret=0;
	FOR(y,H) {
		x=0;
		ZERO(bt.bit);
		FOR(i,4040) add[i].clear();
		FOR(i,4040) {
			int cy=y+i;
			int cx=x+i;
			if(cy<H&&cx<W&&LU[cy][cx]) add[i-LU[cy][cx]+1].push_back(i);
		}
		FOR(i,4040) {
			int cy=y+i;
			int cx=x+i;
			if(cy>=H||cx>=W) break;
			FORR(e,add[i]) bt.add(e,1);
			if(RD[cy][cx]) {
				
				if(RD[cy][cx]>=ML) ret+=bt(i+RD[cy][cx]-1)-bt(i+ML-2);
				bt.add(i,-1);
			}
		}
	}
	FOR(x,W) if(x) {
		y=0;
		ZERO(bt.bit);
		FOR(i,4040) add[i].clear();
		FOR(i,4040) {
			int cy=y+i;
			int cx=x+i;
			if(cy<H&&cx<W&&LU[cy][cx]) add[i-LU[cy][cx]+1].push_back(i);
		}
		FOR(i,4040) {
			int cy=y+i;
			int cx=x+i;
			if(cy>=H||cx>=W) break;
			FORR(e,add[i]) bt.add(e,1);
			if(RD[cy][cx]) {
				
				if(RD[cy][cx]>=ML) ret+=bt(i+RD[cy][cx]-1)-bt(i+ML-2);
				bt.add(i,-1);
			}
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
