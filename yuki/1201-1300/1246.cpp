#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,T;
int A[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>T;
	
	map<int,ll> M;
	M[T]=0;
	FOR(i,N) {
		cin>>x;
		map<int,ll> P;
		FORR(m,M) {
			P[m.first|x]=max(P[m.first|x], m.second+((m.first|x)-m.first));
			P[m.first&x]=max(P[m.first&x], m.second+(m.first-(m.first&x)));
		}
		swap(M,P);
	}
	ll ma=-1;
	FORR(m,M) ma=max(ma,m.second);
	cout<<ma<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
