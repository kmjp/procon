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

int N;
ll AX[202020],AY[202020];
ll BX[202020],BY[202020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>AX[i]>>AY[i];
	FOR(i,N) cin>>BX[i]>>BY[i];
	
	set<pair<int,int>> S;
	FOR(i,N) S.insert({AX[i],AY[i]});
	FOR(i,N) S.erase({BX[i],BY[i]});
	if(S.empty()) {
		cout<<"Yes"<<endl;
		return;
	}
	FOR(k,2) {
		map<int,vector<int>> A;
		map<int,vector<int>> B;
		FOR(i,N) A[AX[i]].push_back(AY[i]);
		FOR(i,N) B[BX[i]].push_back(BY[i]);
		
		ll cand=-1LL<<60;
		int ng=0;
		FORR2(a,b,A) {
			vector<int> X=b;
			vector<int> Y=B[a];
			if(X.size()!=Y.size()) {
				ng=1;
				break;
			}
			sort(ALL(X));
			sort(ALL(Y));
			reverse(ALL(Y));
			FOR(i,X.size()) {
				ll v=X[i]+Y[i];
				if(cand==-1LL<<60) cand=v;
				if(v!=cand) ng=1;
			}
			
		}
		
		if(ng==0) {
			cout<<"Yes"<<endl;
			return;
		}
		
		FOR(i,N) swap(AX[i],AY[i]),swap(BX[i],BY[i]);
	}
	cout<<"No"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
