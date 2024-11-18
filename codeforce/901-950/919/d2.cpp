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

int T;
int N,Q;

vector<int> C[202020];
__int128 mul[202020];
__int128 len[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>Q;
		FOR(i,N+2) C[i].clear(),mul[i]=1,len[i]=0;
		int cur=0;
		FOR(i,N) {
			cin>>x>>y;
			if(len[cur]>=1LL<<60) continue;
			if(x==1) {
				C[cur].push_back(y);
				len[cur]++;
			}
			else {
				y++;
				mul[cur]*=y;
				len[cur]*=y;
				cur++;
				mul[cur]=1;
				len[cur]=len[cur-1];
			}
		}
		while(Q--) {
			ll K;
			cin>>K;
			K--;
			for(i=cur;i>=0;i--) {
				__int128 s=len[i]/mul[i];
				K%=s;
				if(K>=s-C[i].size()) {
					cout<<C[i][K-(s-C[i].size())]<<" ";
					break;
				}
			}
		}
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
