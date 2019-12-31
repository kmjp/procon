#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

string A,B;
string C,D,E;
int aa[6];

void solve() {
	int f,i,j,k,l,x,y;
	
	cin>>A>>B;
	if(A.size()>6) {
		FOR(i,A.size()) {
			if(A[i]!=B[i]) C+=A[i],D+=B[i];
			else E+='A';
		}
		if(C.size()>6) return _P("NO\n");
		C+=E;
		D+=E;
		if(C.size()>6) C=C.substr(0,6),D=D.substr(0,6);
	}
	else {
		C=A,D=B;
	}
	
	FOR(aa[0],C.size()) FOR(aa[1],C.size()) FOR(aa[2],C.size()) FOR(aa[3],C.size()) FOR(aa[4],C.size()) FOR(aa[5],C.size()) {
		if(aa[0]==aa[1]) continue;
		if(aa[2]==aa[3]) continue;
		if(aa[4]==aa[5]) continue;
		string C2=C;
		swap(C2[aa[0]],C2[aa[1]]);
		swap(C2[aa[2]],C2[aa[3]]);
		swap(C2[aa[4]],C2[aa[5]]);
		if(C2==D) return _P("YES\n");
	}
	_P("NO\n");
	
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


