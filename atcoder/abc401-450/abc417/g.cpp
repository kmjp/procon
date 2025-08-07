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

int Q;
int L[505050],R[505050];
ll X[505050];
ll len[505050];
ll dif[505050];
set<pair<ll,int>> S[505050];
int ret[505050];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	len[0]=len[1]=1;
	FOR(i,Q) {
		cin>>L[i+2]>>R[i+2]>>X[i+2];
		len[i+2]=min(len[L[i+2]]+len[R[i+2]],1LL<<60);
		S[i+2].insert({X[i+2],i});
	}
	
	for(i=Q+1;i>=2;i--) {
		if(len[L[i]]>len[i]-len[L[i]]) {
			while(S[i].size()&&S[i].rbegin()->first-dif[i]>len[L[i]]) {
				auto p=*S[i].rbegin();
				S[i].erase(--S[i].end());
				S[R[i]].insert({p.first-dif[i]-len[L[i]]+dif[R[i]],p.second});
			}
			if(S[L[i]].size()<S[i].size()) {
				swap(S[i],S[L[i]]);
				swap(dif[i],dif[L[i]]);
			}
			FORR2(l,j,S[i]) S[L[i]].insert({l-dif[i]+dif[L[i]],j});
			
		}
		else {
			while(S[i].size()&&S[i].begin()->first-dif[i]<=len[L[i]]) {
				auto p=*S[i].begin();
				S[i].erase(S[i].begin());
				S[L[i]].insert({p.first-dif[i]+dif[L[i]],p.second});
			}
			dif[i]+=len[L[i]];
			if(S[R[i]].size()<S[i].size()) {
				swap(S[i],S[R[i]]);
				swap(dif[i],dif[R[i]]);
			}
			FORR2(l,j,S[i]) S[R[i]].insert({l-dif[i]+dif[R[i]],j});
		}
	}
	FOR(i,2) FORR2(a,b,S[i]) ret[b]=i;
	FOR(i,Q) cout<<ret[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
