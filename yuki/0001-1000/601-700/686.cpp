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

int N;
const int DI=330;
deque<int> D[DI];
int dif[DI];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,DI) {
		FOR(j,DI) {
			if(i==0 && j==0) D[i].push_back(0);
			else D[i].push_back(1<<20);
		}
	}
	
	cin>>N;
	while(N--) {
		int L,R;
		cin>>L>>R;
		int LS,RS;
		FOR(LS,DI) if(D[LS].back()+dif[LS]>=L) break;
		FOR(RS,DI) if(D[RS].back()+dif[RS]>=R) break;
		if(LS==RS) {
			for(x=DI-1;x>=0;x--) {
				if(x&&D[LS][x-1]+dif[LS]<=R-1) D[LS][x]=min(D[LS][x],max(L-dif[LS],D[LS][x-1]+1));
				if(x==0 && LS && D[LS-1].back()+dif[LS-1]<=R-1) D[LS][x]=min(D[LS][x],max(L-dif[LS],D[LS-1].back()+dif[LS-1]+1-dif[LS]));
			}
			
		}
		else {
			for(x=DI-1;x>=0;x--) {
				if(x&&D[RS][x-1]+dif[RS]<=R-1) D[RS][x]=min(D[RS][x],max(L-dif[RS],D[RS][x-1]+1));
				if(x==0 && RS && D[RS-1].back()+dif[RS-1]<=R-1) D[RS][x]=min(D[RS][x],max(L-dif[RS],D[RS-1].back()+dif[RS-1]+1-dif[RS]));
			}
			for(y=RS-1;y>LS;y--) {
				dif[y]++;
				D[y].pop_back();
				D[y].push_front(D[y-1].back()+dif[y-1]+1-dif[y]);
			}
			for(x=DI-1;x>=0;x--) {
				if(x&&D[LS][x-1]+dif[LS]<=R-1) D[LS][x]=min(D[LS][x],max(L-dif[LS],D[LS][x-1]+1));
				if(x==0 && LS && D[LS-1].back()+dif[LS-1]<=R-1) D[LS][x]=min(D[LS][x],max(L-dif[LS],D[LS-1].back()+dif[LS-1]+1-dif[LS]));
			}
		}
	}
	
	
	int ma=0;
	FOR(i,DI) FOR(j,DI) if(D[i][j]<1<<20) ma=max(ma,i*DI+j);
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
