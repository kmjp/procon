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

int N,M;
int A[202020],B[202020];
int ma[404040];
vector<int> cand[404040];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	vector<int> Xs;
	FOR(i,M) {
		cin>>A[i]>>B[i];
		Xs.push_back(A[i]);
		Xs.push_back(B[i]);
	}
	Xs.push_back(1);
	Xs.push_back(N);
	sort(ALL(Xs));
	Xs.erase(unique(ALL(Xs)),Xs.end());
	FOR(i,M) {
		x=lower_bound(ALL(Xs),A[i])-Xs.begin();
		y=lower_bound(ALL(Xs),B[i])-Xs.begin();
		cand[y].push_back(x);
	}
	int ret=0;
	FOR(i,Xs.size()) if(i) {
		ma[i]=max(ma[i],ma[i-1]);
		FORR(e,cand[i]) ma[i]=max(ma[i],ma[e]+1);
		ret=max(ret,ma[i]);
	}
	cout<<2*N-2-ret<<endl;
		
		
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
