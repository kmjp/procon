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

int A,B,C;
ll mi[2020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>C;
	
	FOR(i,A) mi[i]=1LL<<40;
	mi[0]=0;
	FOR(i,2020) {
		FOR(x,A) if(mi[x]!=1LL<<40) {
			mi[(x+B)%A]=min(mi[(x+B)%A],mi[x]+B);
			mi[(x+C)%A]=min(mi[(x+C)%A],mi[x]+C);
		}
	}
	ll ret=0;
	FOR(i,A) {
		if(mi[i]==1LL<<40) {
			cout<<"INF"<<endl;
			return;
		}
		ret+=mi[i]/A;
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
