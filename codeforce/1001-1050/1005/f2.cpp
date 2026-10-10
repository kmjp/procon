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

int T,N,K;
int A[202020];
vector<int> P[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		K-=2;
		FOR(i,N) P[i].clear();
		FOR(i,N) {
			cin>>A[i];
			A[i]--;
			P[A[i]].push_back(i);
		}
		set<int> lessX={-1,N},moreY={-1,N};
		ll ret=0;
		for(x=0;x<N;x++) {
			y=K-x;
			int pos=0;
			vector<ll> cand,S={0};
			if(y<N) {
				FOR(i,P[y].size()) {
					cand.push_back(min(((i+1==P[y].size())?N:P[y][i+1]),*moreY.lower_bound(P[y][i]+1))-P[y][i]);
					S.push_back(S.back()+cand.back());
				}
			}
			FORR(a,P[x]) {
				if(y<N) {
					int le=*lessX.lower_bound(a+1);
					int mo=(le<N)?*moreY.lower_bound(le):N;
					k=lower_bound(ALL(P[y]),mo)-P[y].begin();
					int lef=*prev(lessX.lower_bound(a));
					int po=lower_bound(ALL(P[y]),a+1)-P[y].begin();
					ret+=1LL*(a-lef)*(S[k]-S[po]);
				}
				lessX.insert(a);
			}
			
			if(y<N) {
				FORR(a,P[y]) moreY.insert(a);
			}
		}
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
