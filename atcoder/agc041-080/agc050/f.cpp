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
vector<int> OE[303];
int OC[303];
vector<int> E[303];
int C[303];

int comb[303][303];
int odd[303],np[303];
int hoge(int cur,int pre) {
	int no=0;
	np[cur]=0;
	FORR(e,E[cur]) if(e!=pre) {
		if(hoge(e,cur)==0) return 0;
		if(comb[np[cur]+np[e]][np[e]]==0) return 0;
		np[cur]+=np[e];
		no+=odd[e];
	}
	
	if(pre==-1) {
		return no==0;
	}
	else {
		if(no>1) return 0;
		if(no==1) {
			odd[cur]=0;
			np[cur]++;
		}
		else {
			odd[cur]=1;
		}
		return 1;
	}
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,302) {
		comb[i][0]=comb[i][i]=1;
		for(j=1;j<i;j++) comb[i][j]=comb[i-1][j-1]^comb[i-1][j];
	}
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		OE[x-1].push_back(y-1);
		OE[y-1].push_back(x-1);
	}
	FOR(i,N) cin>>OC[i];
	
	int ret=0;
	if(N%2==1) {
		FOR(i,N) {
			C[i]=OC[i];
			E[i]=OE[i];
		}
		FOR(i,N) if(C[i]) ret^=hoge(i,-1);
	}
	else {
		FOR(i,N) FORR(e,OE[i]) if(i<e) {
			FOR(j,N) {
				if(j!=i&&j!=e) {
					C[j]=OC[j];
					E[j]=OE[j];
					FORR(a,E[j]) if(a==e) a=i;
				}
			}
			C[i]=!(OC[i]&OC[e]);
			E[i].clear();
			FORR(a,OE[i]) if(a!=e) E[i].push_back(a);
			FORR(a,OE[e]) if(a!=i) E[i].push_back(a);
			FOR(j,N) if(j!=e&&C[j]) ret^=hoge(j,-1);
		}
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
