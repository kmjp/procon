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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K;
	ll ret=0;
	FOR(i,2) {
		for(int s=0;s<=H-2;s++) {
			int R=2*K+__gcd(s,W)-2;
			ll pat=0;
			for(x=1;x<W;x++) {
				int R2=R-s*x;
				if(R2<0) break;
				
				int Ymi=min(H-s-2,R2/W-1);
				if(Ymi>0) pat+=Ymi;
				for(y=max(1,Ymi+1);y<=Ymi+2 && y+s<H;y++) {
					ll v=1LL*W*y-__gcd(x,y)-__gcd(W-x,y+s);
					if(v<=R2) pat++;
				}
				
			}
			ret+=((s==0)?1:2)*pat;
		}
		swap(H,W);
	}
	cout<<2*ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
