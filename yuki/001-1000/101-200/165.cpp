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

int N;
ll B;
map<int,int> MX,MY;
int X[500],Y[500],P[500];
vector<pair<int,int> > D[500];
int ma=0;

void solve() {
	int i,j,k,l,r,x1,x2,y1,y2; string s;
	
	cin>>N>>B;
	FOR(i,N) cin>>X[i]>>Y[i]>>P[i], MX[X[i]]=MY[Y[i]]=0;
	MX[-1000000001]=MY[-1000000001]=0;
	MX[1000000001]=MY[1000000001]=0;
	x1=y1=0;
	ITR(it,MX) it->second=x1++;
	ITR(it,MY) it->second=y1++;
	FOR(i,N) D[MY[Y[i]]].push_back(make_pair(MX[X[i]],P[i]));
	
	FOR(x2,MX.size()) FOR(x1,x2+1) {
		int num=0;
		ll tot=0;
		y1=0;
		FOR(y2,MY.size()) {
			ITR(it,D[y2]) if(it->first>=x1 && it->first<=x2) num++, tot+=it->second;
			while(tot>B) {
				ITR(it,D[y1]) if(it->first>=x1 && it->first<=x2) num--, tot-=it->second;
				y1++;
			}
			ma=max(ma,num);
		}
	}
	
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
