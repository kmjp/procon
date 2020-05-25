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

int N,Q;
ll SX[50],SY[50],SZ[50],R[50],L[50];
ll AX,AY,AZ;
ll BX,BY,BZ;

int hit(double ax,double ay,double az,double tx,double ty,double tz,double r) {
	double sa=ax*ax+ay*ay+az*az;
	double st=tx*tx+ty*ty+tz*tz;
	double at=(ax-tx)*(ax-tx)+(ay-ty)*(ay-ty)+(az-tz)*(az-tz);
	
	if(sa+st<at) return 0;
	if(at+st<sa) return 0;
	
	double dx=tx/sqrt(st);
	double dy=ty/sqrt(st);
	double dz=tz/sqrt(st);
	double dot=ax*dx+ay*dy+az*dz;
	
	
	return sa-dot*dot<=r*r+1e-9;
	
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) {
		cin>>SX[i]>>SY[i]>>SZ[i]>>R[i]>>L[i];
	}
	while(Q--) {
		cin>>AX>>AY>>AZ>>BX>>BY>>BZ;
		ll ret=0;
		FOR(i,N) {
			if(hit(SX[i]-AX,SY[i]-AY,SZ[i]-AZ,BX-AX,BY-AY,BZ-AZ,R[i])) ret+=L[i];
		}
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
