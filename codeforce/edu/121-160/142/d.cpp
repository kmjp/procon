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
int H,W;
int A[55555][11];

set<ll> M;
int num[5100000];
ll p12[15];



void add(int y,int val) {
	ll v=0;
	int i;
	int R[11];
	FOR(i,W) R[A[y][i]]=i;
	FOR(i,W) {
		v+=(i+1)*p12[R[i]];
		M.insert(v);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p12[0]=1;
	FOR(i,12) p12[i+1]=p12[i]*11;
	
	cin>>T;
	while(T--) {
		cin>>H>>W;
		M.clear();
		FOR(y,H) {
			FOR(x,W) {
				cin>>A[y][x];
				A[y][x]--;
			}
			add(y,1);
		}
		FOR(y,H) {
			int ma=0;
			ll v=0;
			FOR(i,W) {
				v+=(i+1)*p12[A[y][i]];
				if(M.count(v)) ma=i+1;
			}
			
			cout<<ma<<" ";
		}
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
