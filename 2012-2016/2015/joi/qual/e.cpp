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

int H,W;
string S[1010];
int A[1010][1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	set<int> Q;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) {
			A[y][x]=(S[y][x]=='.')?0:(S[y][x]-'0');
			if(y>0 && y<H-1 && x>0 && x<W-1) Q.insert(y*1000+x);
		}
	}
	
	int ret=0;
	while(1) {
		set<int> nex;
		
		while(Q.size()) {
			y=*Q.begin()/1000;
			x=*Q.begin()%1000;
			Q.erase(Q.begin());
			
			for(int y2=max(1,y-1);y2<=min(H-2,y+1);y2++) {
				for(int x2=max(1,x-1);x2<=min(W-2,x+1);x2++) if(A[y2][x2]) {
					int num=A[y2][x2];
					for(int y3=y2-1;y3<=y2+1;y3++) {
						for(int x3=x2-1;x3<=x2+1;x3++) {
							num-=A[y3][x3]==0;
						}
					}
					if(num<=0) nex.insert(y2*1000+x2);
				}
			}
			
		}
		
		if(nex.empty()) break;
		
		FORR(x,nex) A[x/1000][x%1000]=0;
		Q=nex;
		ret++;
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
