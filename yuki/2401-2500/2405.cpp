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


ll mo;
const int MAT=402;
ll A[MAT][MAT];
ll B[MAT][MAT];

ll rev(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

int mat_rank(int r,int c,ll ma_[MAT][MAT]) {
	static ll tmp[MAT][MAT];
	int y,x,step;
	FOR(y,r) FOR(x,c) tmp[y][x]=ma_[y][x];
	int ret=0;
	FOR(step,c) {
		for(y=ret;y<r;y++) if(tmp[y][step]) break;
		if(y==r) continue;
		for(x=step;x<c;x++) swap(tmp[ret][x],tmp[y][x]);
		int re=rev(tmp[ret][step]);
		for(x=step;x<c;x++) tmp[ret][x]=tmp[ret][x]*re%mo;
		
		FOR(y,r) if(y!=ret && tmp[y][step]) {
			re=tmp[y][step];
			for(x=step;x<c;x++) tmp[y][x]=((tmp[y][x]-re*tmp[ret][x])%mo+mo)%mo;
		}
		ret++;
	}
	FOR(y,r) FOR(x,c) ma_[y][x]=tmp[y][x];
	return ret;
	
}

int H,W;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>mo>>H>>W;
	FOR(y,H) FOR(x,W) {
		cin>>A[y][x];
		B[y][x]=A[y][x];
	}
	
	int rank=mat_rank(H,W,B);
	
	
	if(rank==0) rank=1;
	if(H*W<=(H+W)*rank) {
		cout<<1<<endl;
		cout<<H<<" "<<W<<endl;
		FOR(y,H) {
			FOR(x,W) cout<<A[y][x]<<" ";
			cout<<endl;
		}
	}
	else {
		vector<int> V;
		FOR(y,H) {
			FOR(x,W) if(B[y][x]) {
				V.push_back(x);
				break;
			}
		}
		sort(ALL(V));
		V.erase(unique(ALL(V)),V.end());
		if(V.size()<rank) {
			V.push_back(0);
			sort(ALL(V));
			V.erase(unique(ALL(V)),V.end());
		}
		
		cout<<2<<endl;
		cout<<H<<" "<<rank<<endl;
		FOR(y,H) {
			FOR(x,rank) cout<<A[y][V[x]]<<" ";
			cout<<endl;
		}
		cout<<rank<<" "<<W<<endl;
		FOR(y,rank) {
			FOR(x,W) cout<<B[y][x]<<" ";
			cout<<endl;
		}
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
