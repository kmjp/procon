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

int H,W;
int A[2020][2020];
int L[2020][2020],R[2020][2020];
int U[2020][2020],D[2020][2020];
int DL[2020][2020],DR[2020][2020];
int B[2020][2020],C[2020][2020];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	V add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};

ll tot;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>s;
		FOR(x,W) A[y][x]=s[x]=='1';
	}
	
	FOR(y,H) FOR(x,W) if(A[y][x]) {
		L[y][x]=1+(x?L[y][x-1]:0);
		U[y][x]=1+(y?U[y-1][x]:0);
		DL[y][x]=1+((y&&x)?DL[y-1][x-1]:0);
		B[y][x]=min({L[y][x],U[y][x],DL[y][x]});
	}
	for(y=H-1;y>=0;y--) for(x=W-1;x>=0;x--) if(A[y][x]) {
		R[y][x]=1+R[y][x+1];
		D[y][x]=1+D[y+1][x];
		DR[y][x]=1+DR[y+1][x+1];
		C[y][x]=min({R[y][x],D[y][x],DR[y][x]});
	}
	
	for(i=-H-W;i<W;i++) {
		BIT<int,13> bt;
		ZERO(bt.bit);
		vector<int> del[2020];
		FOR(y,H) {
			x=i+y;
			if(x<0||x>=W) continue;
			FORR(e,del[y]) bt.add(e+1,-1);
			if(A[y][x]) {
				bt.add(y+1,1);
				del[y+C[y][x]].push_back(y);
				tot+=bt(y+1)-bt(y+1-B[y][x]);
			}
		}
	}
	cout<<tot<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
