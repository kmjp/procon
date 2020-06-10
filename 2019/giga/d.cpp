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
ll K,V;
ll S[130][130];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K>>V;
	FOR(y,H) {
		FOR(x,W) {
			cin>>r;
			S[y+1][x]=S[y][x]+r;
		}
	}
	
	int ma=0;
	int y1,y2;
	FOR(y1,H) for(y2=y1+1;y2<=H;y2++) {
		ll sum=0;
		int L=0,R=0;
		for(L=0;L<W;L++) {
			while(R<W&&sum+(S[y2][R]-S[y1][R])+K*(y2-y1) <= V) {
				sum+=(S[y2][R]-S[y1][R])+K*(y2-y1);
				R++;
			}
			ma=max(ma,(y2-y1)*(R-L));
			sum-=S[y2][L]-S[y1][L];
			sum-=K*(y2-y1);
		}
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
