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

int N,Q;
int A[101010];
int X[101010],Y[101010];
vector<pair<int,int>> ev[4030];
ll ret[101010];
vector<ll> VA;

int cnt[101010];
multiset<ll> sc;

const int DI=300;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) {
		cin>>A[i];
		VA.push_back(A[i]);
	}
	sort(ALL(VA));
	VA.erase(unique(ALL(VA)),VA.end());
	FOR(i,N) {
		A[i]=lower_bound(ALL(VA),A[i])-VA.begin();
	}
	FOR(i,Q) {
		cin>>X[i]>>Y[i];
		X[i]--;
		if(Y[i]-X[i]<=DI+2) {
			for(j=X[i];j<Y[i];j++) {
				cnt[A[j]]++;
				ret[i]=max(ret[i],cnt[A[j]]*VA[A[j]]);
			}
			for(j=X[i];j<Y[i];j++) {
				cnt[A[j]]--;
			}
		}
		else {
			ev[X[i]/DI].push_back({Y[i],i});
		}
	}
	
	FOR(i,3500) if(ev[i].size()) {
		ZERO(cnt);
		int L,R;
		L=DI*(i+1);
		R=L;
		
		ll ma=0;
		sort(ALL(ev[i]));
		
		FORR(e,ev[i]) {
			while(R<e.first) {
				x=A[R++];
				cnt[x]++;
				ma=max(ma,VA[x]*cnt[x]);
			}
			ret[e.second]=ma;
			for(j=X[e.second];j<L;j++) {
				cnt[A[j]]++;
				ret[e.second]=max(ret[e.second],cnt[A[j]]*VA[A[j]]);
			}
			for(j=X[e.second];j<L;j++) {
				cnt[A[j]]--;
			}
			
		}
	}
	
	
	FOR(i,Q) cout<<ret[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
