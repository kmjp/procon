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


ll X,Y,Z;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X>>Y>>Z;
	if(Z==0) return _P("ccW\n");
	if(X==0 && Y==0) return _P("mourennaihasimasenn\n");
	
	if(Y && Z%Y==0 && 2*(Z/Y)-1<=10000) {
		x = Z/Y;
		cout<<string(x,'w')<<string(x-1,'C')<<endl;
		return;
	}
	if(X && Z%X==0 && 2*(Z/X)-1<=10000) {
		x = Z/X;
		cout<<string(x,'c')<<string(x-1,'C')<<endl;
		return;
	}
	if(X==0 || Y==0) return _P("mourennaihasimasenn\n");
	
	for(i=-10000;i<=10000;i++) {
		ll B=Z-X*i;
		if(B%Y) continue;
		ll C=B/Y;
		if((abs(i)+abs(C))*2-1>10000) continue;
		if(i>0 && C>0) {
			cout<<string(i,'c')<<string(C,'w')<<string(i+C-1,'C')<<endl;
			return;
		}
		else if(i<0) {
			cout<<string(abs(i),'c')<<string(abs(i)-1,'C')<<string(C,'w')<<string(abs(C)-1,'C')<<"W"<<endl;
			return;
		}
		else if(C<0) {
			cout<<string(abs(C),'w')<<string(abs(C)-1,'C')<<string(abs(i),'c')<<string(abs(i)-1,'C')<<"W"<<endl;
			return;
		}
	}
	
	_P("mourennaihasimasenn\n");
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
