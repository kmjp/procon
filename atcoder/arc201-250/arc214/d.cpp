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

int N;
int A[14][14];
int L[14][14],R[14][14];
const ll mo=998244353;
ll comb(ll N_, ll C_) {
	const int NUM_=400001;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	for(k=1;k<=2*N-1;k++) {
		FOR(y,N) {
			x=k-y;
			if(x>=0&&x<N) {
				if(y==0) {
					L[y][x]=L[y][x-1];
					R[y][x]=R[y][x-1];
				}
				else {
					if(x==0) {
						L[y][x]=L[y-1][x];
						R[y][x]=R[y-1][x];
					}
					else {
						L[y][x]=L[y-1][x];
						assert(R[y-1][x]+1==L[y][x-1]);
						R[y][x]=R[y][x-1];
					}
					A[y][x]=R[y-1][x+1]+1-L[y][x];
					L[y][x]+=A[y][x];
					R[y][x]+=A[y][x];
				}
			}
		}
	}
	
	FOR(y,N) {
		FOR(x,N) cout<<A[y][x]<<" ";
		cout<<endl;
	}
	vector<int> V;
	int mask;
	FOR(mask,1<<(2*(N-1))) if(__builtin_popcount(mask)==N-1) {
		x=y=0;
		int sum=A[0][0];
		FOR(i,2*(N-1)) {
			if(mask&(1<<i)) x++;
			else y++;
			sum+=A[y][x];
		}
		V.push_back(sum);
	}
	sort(ALL(V));
	int cur=V.size();
	V.erase(unique(ALL(V)),V.end());
	//cout<<V.size()<<" "<<cur<<endl;
	assert(V.size()==cur);
	assert(V.back()<=6000000);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
