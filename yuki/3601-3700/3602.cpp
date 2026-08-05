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

int H,W,Q;
ll A[20][20];

const int MAT=400;
ll ma[MAT][MAT],pat[MAT][MAT];
ll V[404];
vector<int> cand[20];

// bitsetÇ≈Ç†ÇÈAÇì∆óßbit vectorÇ…Ç∑ÇÈç€ÅAåãâ ÇBÇ…é¶Ç∑
template<typename C> int gf2_rank(C A[MAT][MAT],C B[MAT][MAT],int H,int W) { /* input */
	int i,j,k;
	FOR(i,H) FOR(j,H) B[i][j]=(i==j);
	
	FOR(i,H) {
		int be=i,mi=W+1;
		for(j=i;j<H;j++) {
			FOR(k,W) if(A[j][k]) break;
			if(k<mi) be=j,mi=k;
		}
		if(mi>=W) break;
		FOR(j,W) swap(A[i][j],A[be][j]);
		FOR(j,H) swap(B[i][j],B[be][j]);
		
		FOR(j,H) if(i!=j&&A[j][mi]) {
			FOR(k,W) A[j][k] ^= A[i][k];
			FOR(k,H) B[j][k] ^= B[i][k];
		}
	}
	return i;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	
	FOR(y,H) {
		FOR(x,W) {
			cin>>A[y][x];
			FOR(i,60) if(A[y][x]&(1LL<<i)) ma[y*W+x][i]=1;
		}
	}
	int rank=gf2_rank(ma,pat,H*W,60);
	FOR(i,rank) {
		FOR(j,60) if(ma[i][j]) V[i]|=1LL<<j;
	}
	cin>>Q;
	while(Q--) {
		ll X;
		cin>>X;
		if(X==0) {
			cout<<3<<endl;
			cout<<"1 1"<<endl;
			cout<<"1 2"<<endl;
			cout<<"1 1"<<endl;
			cout<<"1 2"<<endl;
			continue;
		}
		int B[404]={};
		FOR(i,rank) {
			if(X&V[i]) {
				X^=V[i];
				FOR(j,H*W) B[j]^=pat[i][j];
			}
		}
		if(X) {
			cout<<-1<<endl;
			continue;
		}
		int pre=-1;
		vector<pair<int,int>> ret;
		FOR(y,H) {
			cand[y].clear();
			FOR(x,W) if(B[y*W+x]) cand[y].push_back(x);
			if(cand[y].empty()) continue;
			if(pre!=-1) {
				if(count(ALL(cand[y]),pre)) {
					cand[y].erase(remove(ALL(cand[y]), pre), cand[y].end());
					cand[y].insert(cand[y].begin(),pre);
				}
				else {
					cand[y].insert(cand[y].begin(),pre);
					cand[y].push_back(pre);
				}
			}
			pre=cand[y].back();
			FORR(a,cand[y]) ret.push_back({y,a});
		}
		
		cout<<ret.size()-1<<endl;
		FORR2(y,x,ret) cout<<y+1<<" "<<x+1<<endl;
	}
	
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
