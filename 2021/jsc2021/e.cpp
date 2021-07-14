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

int K;
string S;

int C[101][27];
vector<string> cand;
void hoge(int L,int R,int K) {
	if(L+1==R) {
		if(K!=1) {
			_P("impossible\n");
			exit(0);
		}
		C[K][S[L]-'a']++;
		C[K][26]++;
		return;
	}
	
	if((R-L)%2==1) {
		C[K][S[(L+R)/2]-'a']++;
		C[K][26]++;
	}
	int hl=(R-L)/2;
	if(K==1) {
		cand.push_back(S.substr(L,hl));
		cand.push_back(S.substr(R-hl,hl));
		reverse(ALL(cand.back()));
	}
	else {
		hoge(L,L+hl,K-1);
		hoge(R-hl,R,K-1);
	}
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K>>S;
	
	if(K>100) return _P("impossible\n");
	if(K==0) {
		if(S.size()==1) {
			return _P("impossible\n");
		}
		int ok=1;
		FOR(i,S.size()/2) if(S[i]!=S[S.size()-1-i]) ok=0;
		cout<<ok<<endl;
		return;
	}
	
	hoge(0,S.size(),K);
	
	if(cand.size()&&cand[0].size()==1) return _P("impossible\n");
	int ret=0;
	for(i=1;i<=K;i++) {
		int mi=C[i][26];
		FOR(j,26) mi=min(mi,C[i][26]-C[i][j]);
		ret+=mi;
	}
	if(cand.size()&&cand[0].size()) {
		int same=0, dif=1<<30;
		FOR(i,cand[0].size()/2) {
			int C[2][27]={};
			FORR(c,cand) {
				C[0][c[i]-'a']++;
				C[1][c[c.size()-1-i]-'a']++;
			}
			int sm=1<<30,di=1<<30;
			FOR(x,26) FOR(y,26) {
				if(x==y) sm=min(sm,(int)cand.size()*2-C[0][x]-C[1][y]);
				else di=min(di,(int)cand.size()*2-C[0][x]-C[1][y]);
			}
			x=same+sm;
			y=min({same+di,dif+sm,dif+di});
			same=x;
			dif=y;
		}
		ret+=dif;
		if(cand[0].size()%2==1) {
			int C[26]={};
			FORR(c,cand) C[c[cand[0].size()/2]-'a']++;
			ret+=cand.size()-*max_element(C,C+26);
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
