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

int T,N,C[404040];
const ll mo=998244353;
ll R[202020];

std::random_device rnd;
std::mt19937 mt(rnd());
std::uniform_int_distribution<ll> dist(1, 1<<20);
vector<int> V[402020];
ll S[404040];
int ng[404040];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,202020) {
		R[i]=(dist(mt)<<20)+dist(mt);
	}
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,2*N+1) V[i].clear(),ng[i]=0;
		FOR(i,2*N) {
			cin>>C[i];
			C[i]--;
			V[C[i]].push_back(i);
			S[i+1]=S[i]^R[C[i]];
		}
		
		int gr=0;
		int cur=0,num=0;
		ll ret=1;
		map<ll,int> M;
		M[0]=0;
		int start=0;
		FOR(i,2*N) {
			if(V[C[i]][0]!=i) {
				if(S[i+1]==0) {
					gr++;
					int num=0;
					for(x=start;x<=i;x++) {
						if(x) ng[x]+=ng[x-1];
						if(ng[x]==0) num++;
					}
					ret=ret*num%mo;
					start=i+1;
					M.clear();
				}
				else if(M.count(S[i+1])) {
					ng[M[S[i+1]]]++;
					ng[i+1]--;
				}
			}
			M[S[i+1]]=i+1;
		}
		cout<<gr<<" "<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
