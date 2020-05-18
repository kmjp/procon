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

ll A,B,C,N;
map<pair<int,int>,set<int>> XY,XZ,YZ;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>C>>N;
	ll ret=2*(A*B+B*C+C*A);
	FOR(i,N) {
		int x,y,z;
		cin>>x>>y>>z;
		XY[{x,y}].insert(-1);
		XY[{x,y}].insert(C);
		XZ[{x,z}].insert(-1);
		XZ[{x,z}].insert(B);
		YZ[{y,z}].insert(-1);
		YZ[{y,z}].insert(A);
		XY[{x,y}].insert(z);
		XZ[{x,z}].insert(y);
		YZ[{y,z}].insert(x);
		
		ret+=6;
		auto it=XY[{x,y}].lower_bound(z);
		
		if(*prev(it)==z-1) ret-=2;
		if(*next(it)==z+1) ret-=2;
		it=XZ[{x,z}].lower_bound(y);
		if(*prev(it)==y-1) ret-=2;
		if(*next(it)==y+1) ret-=2;
		it=YZ[{y,z}].lower_bound(x);
		if(*prev(it)==x-1) ret-=2;
		if(*next(it)==x+1) ret-=2;
		
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
