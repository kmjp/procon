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

int N,K;

int did[505050];
vector<ll> lef,cand;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	vector<pair<int,int>> V;
	FOR(i,N) {
		cin>>x>>y;
		V.push_back({y,x});
	}
	sort(ALL(V));
	reverse(ALL(V));
	
	ll cur=0;
	int num=0;
	FOR(i,N) {
		if(i<K) {
			cur+=V[i].first;
			if(did[V[i].second]==0) {
				num++;
				did[V[i].second]=1;
			}
			else {
				lef.push_back(V[i].first);
			}
		}
		else {
			if(did[V[i].second]==0) {
				cand.push_back(V[i].first);
				did[V[i].second]=1;
			}
		}
	}
	
	sort(ALL(lef));
	sort(ALL(cand));
	reverse(ALL(cand));
	x=min(lef.size(),cand.size());
	lef.resize(x);
	cand.resize(x);
	
	
	ll ret=cur+1LL*num*num;
	FOR(i,x) {
		if(i) {
			lef[i]+=lef[i-1];
			cand[i]+=cand[i-1];
		}
		ret=max(ret,cur-lef[i]+cand[i]+1LL*(num+i+1)*(num+i+1));
	}
	cout<<ret<<endl;
	
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
