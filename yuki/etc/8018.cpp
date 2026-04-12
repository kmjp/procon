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
vector<pair<int,int>> V[1010];
int S[1010];
double F[1000],T[1000];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) F[i]=10;
	FOR(i,M) {
		cin>>x>>y>>k;
		V[x].push_back({y,k});
		S[x]+=k;
	}
	FOR(i,100) {
		ZERO(T);
		FOR(j,N) {
			if(S[j]==0) {
				T[j]+=F[j];
			}
			else {
				double v=F[j]/S[j];
				FORR2(a,b,V[j]) T[a]+=b*v;
			}
		}
		swap(F,T);
		
	}
	FOR(i,N) _P("%.12lf\n",F[i]);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
