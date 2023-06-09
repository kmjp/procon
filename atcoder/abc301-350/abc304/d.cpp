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

int W,H,N,A,B;
int X[202020],Y[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>W>>H>>N;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
	}
	vector<int> Xs,Ys;
	
	cin>>A;
	Xs.push_back(0);
	FOR(i,A) {
		cin>>x;
		Xs.push_back(x);
	}
	cin>>B;
	Ys.push_back(0);
	FOR(i,B) {
		cin>>y;
		Ys.push_back(y);
	}
	map<pair<int,int>,int> M;
	int ma=0,mi=0;
	FOR(i,N) {
		x=lower_bound(ALL(Xs),X[i])-Xs.begin()-1;
		y=lower_bound(ALL(Ys),Y[i])-Ys.begin()-1;
		M[{x,y}]++;
		ma=max(ma,M[{x,y}]);
	}
	ll num=1LL*(A+1)*(B+1);
	if(num==M.size()) {
		mi=1<<30;
		FORR2(a,b,M) {
			mi=min(mi,b);
		}
	}
	
	cout<<mi<<" "<<ma<<endl;
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
