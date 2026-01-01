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

int N,M;
ll A[202020],B[202020];
ll K;
const ll mo=998244353;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> X,Y;

ll hoge(vector<ll> A,vector<ll> B,ll K) {
	ll N=A.size(),M=B.size();
	ll loop=1LL*N*M;
	vector<pair<ll,ll>> V;
	int i;
	FOR(i,N) V.push_back({A[i],i});
	FOR(i,M) V.push_back({B[i],N+i});
	ll H=N,W=M;
	ll ret=0;
	sort(ALL(V));
	FORR2(a,b,V) {
		if(b<N) {
			(ret+=a*W)%=mo;
			H--;
		}
		else {
			(ret+=a*H)%=mo;
			W--;
		}
	}
	(ret*=K/loop%mo)%=mo;
	K%=loop;
	
	H=N,W=M;
	
	int RW,RH;
	for(i=1;i<W;i++) if(i*H%W==1) RW=i;
	for(i=1;i<H;i++) if(i*W%H==1) RH=i;
	FOR(i,2*W) X.add(i,1);
	FOR(i,2*H) Y.add(i,1);
	
	FORR2(a,b,V) {
		if(b<H) {
			ll num=K/H+(b<K%H);
			int start=b*RW%W;
			int len=X(start+num-1)-X(start-1);
			(ret+=1LL*a*len)%=mo;
			
			Y.add(b*RH%H,-1);
			Y.add(b*RH%H+H,-1);
		}
		else {
			b-=H;
			ll num=K/W+(b<K%W);
			int start=b*RH%H;
			int len=Y(start+num-1)-Y(start-1);
			(ret+=1LL*a*len)%=mo;

			X.add(b*RW%W,-1);
			X.add(b*RW%W+W,-1);
		}
	}
	
	
	return ret;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,N) cin>>A[i];
	FOR(i,M) cin>>B[i];
	int g=__gcd(N,M);
	ll ret=0;
	FOR(i,g) {
		vector<ll> As,Bs;
		FOR(j,N/g) As.push_back(A[j*g+i]);
		FOR(j,M/g) Bs.push_back(B[j*g+i]);
		ret+=hoge(As,Bs,K/g+(i<K%g));
	}
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
