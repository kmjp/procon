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
int A[202020],C[202020];
pair<int,int> P[202020];
map<int,ll> cand;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	cand[N]=0;
	FOR(i,M) {
		cin>>A[i]>>C[i];
		P[i]={C[i],A[i]};
	}
	sort(P,P+M);
	FOR(i,M) {
		int A=P[i].second;
		ll C=P[i].first;
		FORR2(a,b,cand) {
			int n=__gcd(a,A);
			if(n<a) {
				ll d=1LL*(a-n);
				if(cand.count(n)==0) cand[n]=1LL<<60;
				cand[n]=min(cand[n],b+d*C);
			}
		}
	}

	if(cand.count(1)) cout<<cand[1]<<endl;
	else cout<<-1<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
