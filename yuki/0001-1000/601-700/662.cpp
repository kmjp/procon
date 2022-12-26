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

string S[5];
ll C[5];

vector<int> A[3];
ll cnt[3][6];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,5) {
		cin>>S[i]>>C[i];
	}
	FOR(i,3) {
		cin>>x;
		FOR(j,x) {
			cin>>s;
			cnt[i][5]++;
			FOR(y,5) if(s==S[y]) {
				A[i].push_back(y);
				cnt[i][y]++;
			}
		}
	}
	
	double ret=0;
	ll R[5]={};
	FOR(i,5) {
		ret+=5.0*C[i]*cnt[0][i]*cnt[1][i]*cnt[2][i]/cnt[0][5]/cnt[1][5]/cnt[2][5];
		R[i]=5LL*cnt[0][i]*cnt[1][i]*cnt[2][i];
	}
	_P("%.12lf\n",ret);
	FOR(i,5) _P("%lld\n",R[i]);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
