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
int H,W;
vector<int> A[202020],B[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W;
		FOR(y,H) {
			A[y].resize(W);
			FOR(x,W) cin>>A[y][x];
		}
		FOR(y,H) {
			B[y].resize(W);
			FOR(x,W) cin>>B[y][x];
		}
		//1Çç∂è„Ç…
		FOR(y,H) FOR(x,W) if(A[y][x]==1) {
			FOR(k,W) swap(A[y][k],A[0][k]);
			FOR(k,H) swap(A[k][x],A[k][0]);
		}
		FOR(y,H) FOR(x,W) if(B[y][x]==1) {
			FOR(k,W) swap(B[y][k],B[0][k]);
			FOR(k,H) swap(B[k][x],B[k][0]);
		}
		vector<pair<int,int>> AY,AX,BY,BX;
		FOR(y,H) {
			AY.push_back({A[y][0],y});
			BY.push_back({B[y][0],y});
		}
		FOR(x,W) {
			AX.push_back({A[0][x],x});
			BX.push_back({B[0][x],x});
		}
		sort(ALL(AY));
		sort(ALL(AX));
		sort(ALL(BY));
		sort(ALL(BX));
		int ng=0;
		FOR(y,H) FOR(x,W) if(A[AY[y].second][AX[x].second]!=B[BY[y].second][BX[x].second]) ng++;
		if(ng==0) {
			cout<<"YES"<<endl;
		}
		else {
			cout<<"NO"<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
