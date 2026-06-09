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
int N,K;
int A[202020],B;
const ll mo=998244353LL*1000000007;


template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;

mt19937 _rnd(time(0));
ll myrand(){return (ll)(_rnd())<<31|(ll)(_rnd());}


ll V[202020];
__int128 dp[202020];
__int128 pat[202020];
int la[202020];
int NC;
int C[202020];
unordered_map<ll,ll> M;

void clear() {
	int i;
	FOR(i,N) C[i]=0;
	NC=0;
}
int inc(int v) {
	if(C[v]++==0) NC++;
	return C[v];
}
int dec(int v) {
	if(--C[v]==0) NC--;
	return C[v];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	srand(time(NULL));
	FOR(i,202020) pat[i]=myrand()%mo;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		FOR(i,N) {
			cin>>A[i];
			A[i]--;
		}
		while(K--) {
			cin>>B;
			ll S=0;
			FOR(j,B-1) {
				V[j]=myrand()%mo;
				(S+=V[j])%=mo;
			}
			V[B-1]=(mo-S%mo)%mo;
			
			{
				clear();
				__int128 cur=0;
				dp[0]=0;
				FOR(i,N) {
					(cur+=V[(C[A[i]])%B]*pat[A[i]])%=mo;
					dp[i+1]=cur;
					inc(A[i]);
				}
				clear();
				M.clear();
				M[0]=1;
				ll ret=0;
				for(int R=1,L=0;R<=N;R++) {
					inc(A[R-1]);
					while(C[A[R-1]]>B) {
						M[dp[L]]--;
						dec(A[L]);
						L++;
					}
					ret+=M[dp[R]]++;
				}
				cout<<ret<<" ";
			}
			{
				FOR(i,N) dp[i+1]=(dp[i]+pat[A[i]])%mo;
				FOR(i,N+1) la[i]=0;
				
				ll ret=0;
				__int128 H=0;
				clear();
				M.clear();
				
				for(int R=1,L=0,L2=0;R<=N;R++) {
					int up=0;
					bt.add(la[A[R-1]],1);
					bt.add(R,-1);
					la[A[R-1]]=R;
					if(inc(A[R-1])==1) (H+=pat[A[R-1]])%=mo;
						
					while(NC>B) {
						assert(L<L2);
						if(dec(A[L])==0) (H+=mo-pat[A[L]])%=mo;
						M[dp[L]]--;
						L++;
					}
					
					while(bt(L2)==B) {
						dp[L2]=(dp[L2]*B+mo-H*L2%mo)%mo;
						M[dp[L2]]++;
						L2++;
					}
					if(NC==B) {
						ll v=(dp[R]*B+mo-H*R%mo)%mo;
						ret+=M[v];
					}
				}
				cout<<ret<<"\n";
			}
			clear();
			FOR(i,N+1) bt.add(i,-bt(i));
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
