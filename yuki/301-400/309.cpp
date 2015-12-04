#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int H,W;
double P[101][101];
int S[101][101];

int memomask[1<<22];
int failmask[1<<11];
double dp[13][1<<11];

double fast() {
	int i,j,k,l,r,x,y,mask,cur,up;
	
	FOR(mask,1<<(2*W)) {
		int& stand=memomask[mask];
		FOR(j,2) FOR(i,W) {
			x=(j)?i:(W-1-i);
			if(((stand>>(x))&1) + ((stand>>(x+2))&1) >= ((mask>>(2*x))&3)) stand |= 1<<(1+x);
		}
		stand>>=1;
	}
	FOR(mask,1<<W) FOR(x,W) if((mask&(1<<x))==0) failmask[mask] |= 3<<(2*x);
	
	double ret=0;
	dp[0][0]=1;
	FOR(y,H) {
		double p[1<<11];
		
		FOR(cur,1<<W) {
			double pat=1;
			FOR(x,W) {
				if(cur&(1<<x)) pat *= P[y][x];
				else pat *= 1-P[y][x];
			}
			p[cur]=pat;
		}
		FOR(up,1<<W) if(dp[y][up]>1e-12) {
			int curmask=0;
			FOR(x,W) {
				r = 4-S[y][x]+((up>>x)&1);
				r = max(0,min(4-r,3));
				curmask |= r<<(2*x);
			}
			FOR(cur,1<<W) {
				int nmask = memomask[curmask | failmask[cur]];
				ret += p[cur]*dp[y][up]*__builtin_popcount(nmask);
				dp[y+1][nmask] += p[cur]*dp[y][up];
				
			}
		}
	}
	return ret;
}

double slow() {
	int i,j,k,l,r,x,y; string s;
	ZERO(dp);
	double ret=0;
	dp[0][0]=1;
	FOR(y,H) {
		for(int cur=0;cur<1<<W;cur++) {
			double pat=1;
			int hand=0;
			FOR(x,W) {
				if(cur&(1<<x)) {
					pat *= P[y][x];
					if(S[y][x]==0) hand |= 1<<(x+1);
				}
				else pat *= 1-P[y][x];
			}
			for(int up=0;up<1<<W;up++) if(dp[y][up]>1e-12) {
				int hand2=hand;
				FOR(j,2) FOR(i,W) {
					x=(j)?i:(W-1-i);
					if(cur&(1<<x)) {
						int p=4-S[y][x];
						if(hand2&(1<<x)) p++;
						if(hand2&(1<<(x+2))) p++;
						if(up&(1<<x)) p++;
						if(p>=4) hand2 |= 1<<(x+1);
					}
				}
				
				hand2 >>=1;
				ret += pat*dp[y][up]*__builtin_popcount(hand2);
				dp[y+1][hand2] += pat*dp[y][up];
			}
		}
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) FOR(x,W) cin>>r, P[y][x] = r/100.0;
	FOR(y,H) FOR(x,W) cin>>S[y][x];
	
	_P("%.12lf\n",fast());
	//_P("%.12lf\n",slow());
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
