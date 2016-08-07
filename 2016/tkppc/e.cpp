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
ll X[101010],V[101010];
int Q;
ll T[101010],L[101010],R[101010];

vector<ll> C[2020];
int SS[202][102020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>X[i]>>V[i];
		if(abs(V[i])>100) {
			FOR(j,3030) {
				ll a=X[i]+V[i]*j;
				if(a<0 || a>100000) break;
				C[j].push_back(a);
			}
			
		}
		else {
			SS[V[i]+100][X[i]+1]++;
		}
	}
	FOR(i,2020) sort(ALL(C[i]));
	FOR(i,202) FOR(x,101010) SS[i][x+1]+=SS[i][x];
	cin>>Q;
	FOR(i,Q) {
		cin>>T[i]>>L[i]>>R[i];
		ll ret=0;
		for(x=-100;x<=100;x++) {
			ll LL=min(max(0LL,L[i]-x*T[i]),100001LL);
			ll RR=min(max(0LL,R[i]-x*T[i]+1),100001LL);
			ret += SS[x+100][RR]-SS[x+100][LL];
		}
		if(T[i]<=2000) ret += lower_bound(ALL(C[T[i]]),R[i]+1)-lower_bound(ALL(C[T[i]]),L[i]);
		cout<<ret<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
