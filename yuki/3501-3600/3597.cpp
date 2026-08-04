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

int H,W,SX,SY,N;

ll MX[2<<20],MY[2<<20],MYpX[2<<20],MYmX[2<<20];

void update(map<ll,ll>& M,ll a,ll b) {
	if(M.count(a)) M[a]=max(M[a],b);
	else M[a]=b;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	FOR(i,2<<20) {
		MX[i]=MY[i]=MYpX[i]=MYmX[i]=-1LL<<60;
	}
	
	cin>>H>>W>>SX>>SY>>N;
	MX[SX]=0;
	MY[SY]=0;
	MYpX[SX+SY]=0;
	MYmX[SY-SX+(1<<20)]=0;
	ll ret=0;
	ll p1=0;
	ll p2=-1LL<<60;
	FOR(i,N) {
		cin>>x>>y>>k;
		ll cand=max(-1LL<<60,p2);
		cand=max(cand,MX[x]);
		cand=max(cand,MY[y]);
		cand=max(cand,MYpX[y+x]);
		cand=max(cand,MYmX[y-x+(1<<20)]);
		cand+=k;
		p2=max(p2,p1);
		p1=max(p1,cand);
		ret=max(ret,cand);
		chmax(MX[x],cand);
		chmax(MY[y],cand);
		chmax(MYpX[y+x],cand);
		chmax(MYmX[y-x+(1<<20)],cand);
		
		
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
