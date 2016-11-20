#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int H,W,K;
string C[50];
string B[50];

ll dfs() {
	ll tot=0;
	int y,x,i;
	
	FOR(x,H) {
		char pre='0';
		int num=0;
		FOR(y,W) {
			if(B[y].size()<=x) {
				pre='0';
				num=0;
			}
			else {
				if(B[y][x]!=pre) pre=B[y][x], num=0;
				num++;
				if(num==K) {
					tot+=(pre-'0')*num;
					FOR(i,K) B[y-i][x]='0';
				}
				if(num>K) {
					tot+=(pre-'0');
					B[y][x]='0';
				}
			}
		}
	}
	if(tot==0) return 0;
	
	FOR(y,W) {
		string s;
		FORR(c,B[y]) if(c!='0') s+=c;
		B[y]=s;
	}
	return tot+dfs()*2;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K;
	FOR(y,H) cin>>C[y];
	ll ma=0;
	FOR(y,H) FOR(x,W) {
		int y2,x2;
		FOR(x2,W) {
			B[x2].clear();
			for(y2=H-1;y2>=0;y2--) if(y2!=y || x2!=x) B[x2]+=C[y2][x2];
		}
		ma=max(ma,dfs());
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
