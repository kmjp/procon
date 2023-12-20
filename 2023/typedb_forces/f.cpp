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
int vis[202020];
vector<int> C[202020];
vector<int> cand[202020];
vector<int> merge(vector<int>& A,vector<int>& B) {
	vector<int> R;
	int i;
	FOR(i,A.size()) {
		R.push_back(A[i]);
		R.push_back(B[i]);
	}
	return R;
}
int ret[202020];

ll modpow(ll a, ll n, ll mo) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

vector<int> gorev(vector<int> C,int r) {
	int N=C.size();
	if(N%2==0) return C;
	int cand=0;
	int i;
	for(i=1;i<N;i++) {
		ll a=i*modpow(2,r,N)%N;
		if(a==1) cand=i;
	}
	vector<int> R;
	FOR(i,N) R.push_back(C[1LL*i*cand%N]);
	return R;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		FOR(i,N) {
			cin>>A[i];
			A[i]--;
			vis[i]=0;
			C[i].clear();
			cand[i+1].clear();
		}
		FOR(i,N) if(vis[i]==0) {
			x=i;
			while(vis[x]==0) {
				vis[x]=1;
				C[i].push_back(x);
				x=A[x];
			}
			cand[C[i].size()].push_back(i);
		}
		int ok=0;
		k=min(K,20);
		for(i=1;i<=N;i++) if(cand[i].size()&&(i%2==0)) {
			if(cand[i].size()%(1<<k)) break;
		}
		if(i<=N) {
			cout<<"NO"<<endl;
			continue;
		}
		for(i=1;i<=N;i++) if(cand[i].size()) {
			int cur=0;
			while(cur<cand[i].size()) {
				k=0;
				while(k<K&&cur+(1<<(k+1))<=cand[i].size()) k++;
				vector<int> CC;
				FOR(j,1<<k) {
					x=cand[i][cur+j];
					C[x]=gorev(C[x],K-k);
					CC.push_back(cand[i][cur+j]);
				}
				while(CC.size()>1) {
					vector<int> nex;
					for(j=0;j<CC.size();j+=2) {
						C[CC[j]]=merge(C[CC[j]],C[CC[j+1]]);
						nex.push_back(CC[j]);
					}
					CC=nex;
				}
				x=CC[0];
				FOR(y,C[x].size()) ret[C[x][y]]=C[x][(y+1)%C[x].size()]+1;
				cur+=1<<k;
			}
			
		}
		cout<<"YES"<<endl;
		FOR(i,N) cout<<ret[i]<<" ";
		cout<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
