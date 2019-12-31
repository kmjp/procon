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

int N,K;
int X1[202],X2[202];
int Y1[202],Y2[202];
int Z1[202],Z2[202];
vector<ll> VX,VY,VZ;


void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>N>>K;
	VX.push_back(0);
	VY.push_back(0);
	VZ.push_back(0);
	VX.push_back(1<<20);
	VY.push_back(1<<20);
	VZ.push_back(1<<20);
	
	FOR(i,N) {
		cin>>X1[i]>>Y1[i]>>Z1[i]>>X2[i]>>Y2[i]>>Z2[i];
		VX.push_back(X2[i]);
		VX.push_back(X1[i]);
		VY.push_back(Y2[i]);
		VY.push_back(Y1[i]);
		VZ.push_back(Z2[i]);
		VZ.push_back(Z1[i]);
	}
	sort(ALL(VX));
	sort(ALL(VY));
	sort(ALL(VZ));
	VX.erase(unique(ALL(VX)),VX.end());
	VY.erase(unique(ALL(VY)),VY.end());
	VZ.erase(unique(ALL(VZ)),VZ.end());
	ll ret=0;
	FOR(x,VX.size()-1) FOR(y,VY.size()-1) FOR(z,VZ.size()-1) {
		int num=0;
		FOR(i,N) {
			if(VX[x+1]<=X2[i] && VY[y+1]<=Y2[i] && VZ[z+1]<=Z2[i]&&
			   X1[i]<VX[x+1] && Y1[i]<VY[y+1] && Z1[i]<VZ[z+1]) {
				num++;
			}
		}
		if(num>=K) {
			ret += (VX[x+1]-VX[x])*(VY[y+1]-VY[y])*(VZ[z+1]-VZ[z]);
		}
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
