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

ll N;
__int128 S[1<<20];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	vector<array<ll,3>> ret;
	cin>>N;
	
	// E=1
	for(ll w=1;w*w<=2*N;w++) if(2*N%w==0&&w<2*N/w&&w%2!=2*N/w%2) ret.push_back({1LL,(2*N/w-w)/2+1,(2*N/w-w)/2+w});
	
	for(int e=2;e<=40;e++) {
		map<__int128,int> M;
		M[0]=0;
		for(ll a=1;a<=1<<20;a++) {
			__int128 v=1;
			FOR(i,e) v*=a;
			if(v>N) break;
			S[a]=S[a-1]+v;
			if(M.count(S[a]-N)) ret.push_back({e,M[S[a]-N]+1,a});
			M[S[a]]=a;
		}
	}
	
	
	sort(ALL(ret));
	cout<<ret.size()<<endl;
	FORR(r,ret) cout<<r[0]<<" "<<r[1]<<" "<<r[2]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
