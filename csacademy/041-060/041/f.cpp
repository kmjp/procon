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

int N;
int L[2020],R[2020];
pair<int,int> P[4040];
int mo=1000000007;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {V s=0;e++;while(e) (s+=bit[e-1])%=mo,e-=e&-e; return s;}
	V add(int e,V v) { e++; while(e<=1<<ME) (bit[e-1]+=v)%=mo,e+=e&-e;}
};
BIT<int,13> bt[4040];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>P[i].first>>P[i].second;
	
	sort(P,P+N);
	FOR(i,N) {
		L[i]=P[i].first, R[i]=P[i].second;
		
		for(y=L[i];y<=4000;y++) {
			int sum=bt[y](L[i]-1);
			if(sum) {
				if(y<=R[i]) bt[R[i]].add(y,sum);
				else bt[y].add(R[i],sum);
			}
		}
		bt[R[i]].add(L[i]-1,1);
	}
	
	ll ret=0;
	FOR(x,4010) ret+=bt[x](4010);
	cout<<ret%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
