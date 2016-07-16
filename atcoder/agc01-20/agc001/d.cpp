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

int N,M,NE;
vector<int> O;
vector<int> E;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x;
		if(x%2==1) O.push_back(x);
		else E.push_back(x);
	}
	
	if(O.size()>2) return _P("Impossible\n");
	NE=E.size();
	sort(ALL(E));
	reverse(ALL(E));
	
	if(O.size()==2) {
		_P("%d",O[0]);
		FOR(i,NE) _P(" %d",E[i]);
		_P(" %d\n",O[1]);
		
		x = NE+1+2;
		if(O[0]==1) x--;
		if(O[1]==1) x--;
		
		_P("%d\n",x);
		if(O[0]>1) _P("%d ",O[0]-1);
		_P("2 ");
		FOR(i,NE) _P("%d ",E[i]);
		if(O[1]>1) _P(" %d",O[1]-1);
		_P("\n");
	}
	else if(O.size()==1) {
		_P("%d",O[0]);
		FOR(i,NE) _P(" %d",E[i]);
		_P("\n");
		
		
		x = NE+1+1;
		if(O[0]==1) x--;
		
		_P("%d\n",x);
		if(O[0]>1) _P("%d ",O[0]-1);
		
		if(NE) {
			_P("2");
			FOR(i,NE-1) _P(" %d",E[i]);
			
			_P(" %d\n",E[NE-1]-1);
		}
		else {
			_P("1\n");
		}
		
	}
	else {
		FOR(i,NE) _P("%d%c",E[i],(i==NE-1)?'\n':' ');
		_P("%d\n",NE+1);
		_P("1");
		FOR(i,NE-1) _P(" %d",E[i]);
		_P(" %d\n",E[NE-1]-1);
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
