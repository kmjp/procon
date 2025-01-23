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

int N,Q;
int A[505050],B[505050];
ll C[505050],D[505050];

int ret[505050];

int P[808][808];
ll S[808][808];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) cin>>A[i];
	FOR(i,N) cin>>B[i];
	FOR(i,N) cin>>C[i];
	FOR(i,Q) cin>>D[i];
	
	vector<int> Ds[2],Ps[2];
	map<int,int> Dm[2];
	for(x=1;x*x<=A[0];x++) if(A[0]%x==0) {
		Ds[0].push_back(x);
		if(x*x!=A[0]) Ds[0].push_back(A[0]/x);
	}
	for(x=1;x*x<=B[0];x++) if(B[0]%x==0) {
		Ds[1].push_back(x);
		if(x*x!=B[0]) Ds[1].push_back(B[0]/x);
	}
	
	x=A[0];
	for(i=2;i*i<=x;i++) if(x%i==0) {
		Ps[0].push_back(i);
		while(x%i==0) x/=i;
	}
	if(x>1) Ps[0].push_back(x);
	x=B[0];
	for(i=2;i*i<=x;i++) if(x%i==0) {
		Ps[1].push_back(i);
		while(x%i==0) x/=i;
	}
	if(x>1) Ps[1].push_back(x);

	sort(ALL(Ds[0]));
	sort(ALL(Ds[1]));
	sort(ALL(Ps[0]));
	sort(ALL(Ps[1]));
	FOR(i,Ds[0].size()) Dm[0][Ds[0][i]]=i;
	FOR(i,Ds[1].size()) Dm[1][Ds[1][i]]=i;
	
	FOR(k,2) {
		ZERO(P);
		ZERO(S);
		FOR(i,N) {
			if(i==0) {
				P[Dm[0].size()-1][Dm[1].size()-1]++;
				if(k==1) {
					S[Dm[0].size()-1][Dm[1].size()-1]+=C[0];
				}
			}
			else {
				P[Dm[0][__gcd(A[0],A[i])]][Dm[1][__gcd(B[0],B[i])]]++;
				P[Dm[0][__gcd(A[0],B[i])]][Dm[1][__gcd(B[0],A[i])]]++;
				S[Dm[0][__gcd(A[0],B[i])]][Dm[1][__gcd(B[0],A[i])]]+=C[i];
				P[Dm[0][__gcd(__gcd(A[0],B[i]),A[i])]][Dm[1][__gcd(__gcd(B[0],A[i]),B[i])]]--;
				S[Dm[0][__gcd(__gcd(A[0],B[i]),A[i])]][Dm[1][__gcd(__gcd(B[0],A[i]),B[i])]]-=C[i];
			}
		}
		vector<pair<int,ll>> cand;
		FORR(p,Ps[0]) {
			for(x=Ds[0].size()-1;x>=0;x--) if(Dm[0].count(Ds[0][x]*p)) for(y=Ds[1].size()-1;y>=0;y--) {
				P[x][y]+=P[Dm[0][Ds[0][x]*p]][y];
				S[x][y]+=S[Dm[0][Ds[0][x]*p]][y];
			}
		}
		FORR(p,Ps[1]) {
			for(y=Ds[1].size()-1;y>=0;y--) if(Dm[1].count(Ds[1][y]*p))  for(x=Ds[0].size()-1;x>=0;x--) {
				P[x][y]+=P[x][Dm[1][Ds[1][y]*p]];
				S[x][y]+=S[x][Dm[1][Ds[1][y]*p]];
			}
		}
		
		FOR(x,Ds[0].size()) FOR(y,Ds[1].size()) {
			if(P[x][y]==N) {
				cand.push_back({Ds[0][x]+Ds[1][y],S[x][y]});
			}
		}
		sort(ALL(cand));
		vector<pair<ll,int>> R;
		FORR2(a,b,cand) {
			while(R.size()&&R.back().first>=b) R.pop_back();
			R.push_back({b,a});
		}
		
		FOR(i,Q) {
			x=lower_bound(ALL(R),make_pair(D[i]+1,0))-R.begin();
			if(x) ret[i]=max(ret[i],R[x-1].second);
		}
		
		
		swap(Ds[0],Ds[1]);
		swap(Dm[0],Dm[1]);
		swap(Ps[0],Ps[1]);
		swap(A[0],B[0]);
	}
	FOR(i,Q) cout<<ret[i]<<" ";
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
