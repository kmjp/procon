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
int A[402020];
int nex[30][402020];
ll ret[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	int sq=0;
	while(T--) {
		cin>>N>>Q;
		FOR(i,N) {
			cin>>A[i];
			A[i+N]=A[i];
		}
		FOR(j,30) {
			x=2*N;
			for(i=2*N-1;i>=0;i--) {
				nex[j][i]=x;
				if(A[i]&(1<<j)) x=i;
			}
		}
		
		vector<pair<int,ll>> C;
		FOR(i,N) {
			int cur=A[i];
			C.push_back({cur,i});
			vector<int> S;
			FOR(j,30) if((cur&(1<<j))==0&&nex[j][i]<2*N) S.push_back(nex[j][i]);
			sort(ALL(S));
			FORR(ne,S) {
				cur|=A[ne];
				ll tar=i+1LL*(ne-i)*N;
				if(ne>=N+1) tar-=N;
				C.push_back({cur,tar});
			}
		}
		sort(ALL(C));
		
		vector<pair<int,int>> Qs;
		FOR(i,Q) {
			cin>>x;
			Qs.push_back({-(x+1),i});
		}
		sort(ALL(Qs));
		ll re=1LL<<60;
		MINUS(ret);
		FORR2(v,i,Qs) {
			v=-v;
			while(C.size()&&C.back().first>=v) re=min(re,C.back().second+1), C.pop_back();
			if(re<1LL<<60) ret[i]=re;
		}
		
		FOR(i,Q) cout<<ret[i]<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
