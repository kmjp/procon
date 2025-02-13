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
ll S;
ll A[6];
ll M[1<<6];
set<pair<ll,int>> C[1<<6];

void hoge(int v) {
	int first=1;
	int i;
	FOR(i,N) if(v&(1<<i)) {
		if(first==0) cout<<"x";
		cout<<A[i];
		first=0;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	FOR(i,N) cin>>A[i];
	C[0].insert({0,0});
	
	int mask;
	FOR(mask,1<<N) {
		M[mask]=1;
		FOR(i,N) if(mask&(1<<i)) M[mask]*=A[i];
	}
	
	FOR(mask,1<<N) {
		int mask2;
		FOR(mask2,1<<N) if(mask2&&(mask&mask2)==0) {
			FORR(a,C[mask]) C[mask|mask2].insert({a.first+M[mask2],mask2});
		}
	}
	
	
	FORR2(a,b,C[(1<<N)-1]) if(a==S) {
		cout<<"Yes"<<endl;
		hoge(b);
		mask=((1<<N)-1)^b;
		S-=M[b];
		while(mask) {
			cout<<"+";
			FORR2(a,b,C[mask]) if(a==S) {
				hoge(b);
				mask^=b;
				S-=M[b];
				break;
			}
			
		}
		cout<<endl;
		return;
	}
	cout<<"No"<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
