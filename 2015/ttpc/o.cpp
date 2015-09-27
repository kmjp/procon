#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

#include <limits>
template<class CC> vector<vector<int>> LIS_ext(vector<CC>& v) {
	int i,N=v.size();
	if(v.empty()) return vector<vector<int>>();
	vector<CC> dp(N,(numeric_limits<CC>::max)()),id(N),dp2(N,(numeric_limits<CC>::min)());
	FOR(i,N) dp[id[i]=lower_bound(dp.begin(),dp.end(),v[i]) - dp.begin()] = v[i];
	int nl = *max_element(id.begin(),id.end());
	vector<vector<int>> ret(nl+1);
	for(i=N-1;i>=0;i--) ret[id[i]].push_back(i), dp2[id[i]]=max(dp2[id[i]],v[i]);
	return ret;
}

ll mo;

template<class V, int ME> class BIT_mod {
public:
	V bit[1<<ME];
	void clear(){ZERO(bit);};
	V operator()(int e) {V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s%mo;}
	V add(int e,V v) { e++; while(e<=1<<ME) { bit[e-1]+=v; bit[e-1] -= (bit[e-1]>=mo)?mo:0; e+=e&-e;}}
};
BIT_mod<int,20> bt;

int N;
vector<int> A[2],V[2];
int rev[2][101010]; //rev A
int lrank[2][101010]; //lis rank

int order[2][101010]; //lis order order->id
int order_r[2][101010]; //lis order id->order
int orders[2][101010]; //lis order per rank
ll dp[2][2][101010];
BIT_mod<ll,20> bit;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	A[0].push_back(0);
	A[1].push_back(0);
	FOR(i,N) cin>>x, A[0].push_back(x), A[1].push_back(N+1-x);
	A[0].push_back(N+1);
	A[1].push_back(N+1);
	N+=2;
	
	int ma=-1;
	FOR(i,2) {
		FOR(j,N) rev[i][A[i][j]]=j;
		auto VL=LIS_ext(A[i]);
		ma+=VL.size()-2;
		int cur=0;
		FOR(j,VL.size()) {
			vector<int> v;
			FORR(r,VL[j]) v.push_back(A[i][r]), lrank[i][r]=j;
			sort(ALL(v));
			FOR(x,v.size()) order[i][orders[i][j]+x]=rev[i][v[x]], order_r[i][rev[i][v[x]]] = orders[i][j]+x, V[i].push_back(v[x]);
			orders[i][j+1]=orders[i][j+2]=orders[i][j]+VL[j].size();
		}
	}
	
	ll momo[]={1000000007,1000000009,1000000021};
	FORR(r,momo) {
		mo = r;
		FOR(i,2) {
			
			// normal order
			bit.clear();
			dp[i][0][0]=1;
			bit.add(1,1);
			for(x=1;x<N;x++) {
				int ra=lrank[i][x];
				int L=orders[i][ra-1];
				int R=lower_bound(V[i].begin()+L,V[i].begin()+orders[i][ra],A[i][x])-V[i].begin();
				dp[i][0][x]=(bit(R)+mo-bit(L))%mo;
				bit.add(1+order_r[i][x],dp[i][0][x]);
			}
			// rev order
			bit.clear();
			dp[i][1][N-1]=1;
			bit.add(N,1);
			for(x=N-2;x>=0;x--) {
				int ra=lrank[i][x];
				int R=orders[i][ra+2];
				int L=lower_bound(V[i].begin()+orders[i][ra+1],V[i].begin()+R,A[i][x])-V[i].begin();
				dp[i][1][x]=(bit(R)+mo-bit(L))%mo;
				bit.add(1+order_r[i][x],dp[i][1][x]);
			}
		}
		
		ll tot=dp[0][0][N-1]*dp[1][0][N-1]%mo;
		ll tot2=0;
		for(x=1;x<N-1;x++) (tot2 += dp[0][0][x]*dp[0][1][x]%mo*dp[1][0][x]%mo*dp[1][1][x])%=mo;
		
		if(tot!=tot2) {
			ma++;
			break;
		}
	}
	
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
