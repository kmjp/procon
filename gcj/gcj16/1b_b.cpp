#include <bits/stdc++.h>
#include <sys/time.h>
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

int L;
string C,J;
string AC,AJ;
ll CC,JJ;

void comp(string A,string B) {
	ll ta=atoll(A.c_str());
	ll tb=atoll(B.c_str());
	if(abs(CC-JJ)>abs(ta-tb) || (abs(CC-JJ)==abs(ta-tb) && ta<CC) || 
		(abs(CC-JJ)==abs(ta-tb) && ta==CC && tb<JJ)) {
		AC=A;
		AJ=B;
		CC=ta;
		JJ=tb;
	}
}
void small(string A,string B) {
	FORR(r,A) if(r=='?') r='9';
	FORR(r,B) if(r=='?') r='0';
	comp(A,B);
}
void large(string A,string B) {
	FORR(r,A) if(r=='?') r='0';
	FORR(r,B) if(r=='?') r='9';
	comp(A,B);
}


void dfs(int d,string A,string B) {
	if(d==L) {
		comp(A,B);
		return;
	}
	
	int i;
	// same
	if(A[d]==B[d] || A[d]=='?' || B[d]=='?') {
		string A2=A, B2=B;
		if(A2[d]=='?' && B2[d]=='?') A2[d]=B2[d]='0';
		else if(A2[d]=='?') A2[d]=B2[d];
		else if(B2[d]=='?') B2[d]=A2[d];
		dfs(d+1,A2,B2);
	}
	// A<B
	if(A[d]!='?' && B[d]!='?' && A[d]<B[d])  { string A2=A, B2=B; small(A2,B2);}
	if(A[d]=='?' && (B[d]!='?' && B[d]>'0')) { string A2=A, B2=B; A2[d]=B2[d]-1; small(A2,B2);}
	if((A[d]!='?' && A[d]<'9') && B[d]=='?') { string A2=A, B2=B; B2[d]=A2[d]+1; small(A2,B2);}
	if(A[d]=='?' && B[d]=='?')               { string A2=A, B2=B; A2[d]='0'; B2[d]='1'; small(A2,B2);}
	// A>B
	if(A[d]!='?' && B[d]!='?' && A[d]>B[d])  { string A2=A, B2=B; large(A2,B2);}
	if(A[d]=='?' && (B[d]!='?' && B[d]<'9')) { string A2=A, B2=B; A2[d]=B2[d]+1; large(A2,B2);}
	if((A[d]!='?' && A[d]>'0') && B[d]=='?') { string A2=A, B2=B; B2[d]=A2[d]-1; large(A2,B2);}
	if(A[d]=='?' && B[d]=='?')               { string A2=A, B2=B; A2[d]='1'; B2[d]='0'; large(A2,B2);}
}

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>C>>J;
	L=C.size();
	CC=0,JJ=1LL<<60;
	dfs(0,C,J);
	
	_P("Case #%d: %s %s\n",_loop,AC.c_str(),AJ.c_str());
}

void init() {
}

int main(int argc,char** argv){
	int loop,loops;
	long long span;
	char tmpline[1000];
	struct timeval start,end,ts;
	
	if(argc>1) freopen(argv[1], "r", stdin);
	gettimeofday(&ts,NULL);
	cin>>loops;
	init();
	
	for(loop=1;loop<=loops;loop++) {
		gettimeofday(&start,NULL); solve(loop); gettimeofday(&end,NULL);
		span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
		fprintf(stderr,"Case : %d                                     time: %lld ms\n",loop,span/1000);
	}
	
	start = ts;
	span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
	fprintf(stderr,"**Total time: %lld ms\n",span/1000);
	
	return 0;
}


