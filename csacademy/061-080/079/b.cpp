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

int N,M;
ll AX[2020],AY[2020];
ll BX[2020],BY[2020];
int cnt[2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>BX[i]>>BY[i];
	FOR(i,M) cin>>AX[i]>>AY[i];
	FOR(i,M) {
		int tar=0;
		ll mi=1LL<<30;
		FOR(j,N) if((AX[i]-BX[j])*(AX[i]-BX[j])+(AY[i]-BY[j])*(AY[i]-BY[j])<mi) {
			tar=j;
			mi=(AX[i]-BX[j])*(AX[i]-BX[j])+(AY[i]-BY[j])*(AY[i]-BY[j]);
		}
		cnt[tar]++;
	}
	cout<<count(cnt,cnt+N,1)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
