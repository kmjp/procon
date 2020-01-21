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

int W;
ll A[55],B[55],C[55];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>W;
	FOR(i,W) cin>>A[i]>>B[i]>>C[i];
	
	vector<pair<ll,ll>> cand[2];
	int mask;
	FOR(mask,1<<25) if((mask&(mask>>1))==0) {
		
		if(mask%2==0) {
			ll m=-C[26],s=B[26];
			for(i=27;i<52;i++) {
				if(mask&(1<<(i-26))) {
					i++;
					m-=C[i];
					s+=B[i];
				}
				else {
					m+=A[i];
				}
			}
			cand[1].push_back({m,s});
		}
		ll m=0,s=0;
		for(i=26;i<52;i++) {
			if(mask&(1<<(i-26))) {
				i++;
				m-=C[i];
				s+=B[i];
			}
			else {
				m+=A[i];
			}
		}
		cand[0].push_back({m,s});
	}
	FOR(i,2) {
		sort(ALL(cand[i]));
		vector<pair<ll,ll>> CC;
		FORR(c,cand[i]) {
			while(CC.size() && CC.back().second<=c.second) CC.pop_back();
			CC.push_back(c);
		}
		cand[i]=CC;
		//cout<<i<<endl;
		//FORR(c,CC) cout<<c.first<<" "<<c.second<<endl;
	}
	ll ret=0;
	FOR(mask,1<<26) if((mask&(mask>>1))==0) {
		ll m=0,s=0;
		FOR(i,26) {
			if(mask&(1<<i)) {
				if(i==25) break;
				i++;
				m-=C[i];
				s+=B[i];
			}
			else {
				m+=A[i];
			}
		}
		i=26-i;
		x=lower_bound(ALL(cand[i]),make_pair(-m,0LL))-cand[i].begin();
		if(x<cand[i].size()) ret=max(ret,s+cand[i][x].second);
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
