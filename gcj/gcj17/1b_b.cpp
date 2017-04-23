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

int N,A,B,C,AB,BC,AC;

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>N>>A>>AB>>B>>BC>>C>>AC;
	
	_P("Case #%d: ",_loop);
	if(A==BC && A+BC==N) {
		FOR(i,N/2) _P("RG");
	}
	else if(B==AC && B+AC==N) {
		FOR(i,N/2) _P("YV");
	}
	else if(C==AB && C+AB==N) {
		FOR(i,N/2) _P("BO");
	}
	else {
		if(BC && A<BC+1) return _P("IMPOSSIBLE\n");
		A-=BC;
		if(AC && B<AC+1) return _P("IMPOSSIBLE\n");
		B-=AC;
		if(AB && C<AB+1) return _P("IMPOSSIBLE\n");
		C-=AB;
		
		pair<int,string> P[3];
		P[0]={A,string(A,'R')};
		P[1]={B,string(B,'Y')};
		P[2]={C,string(C,'B')};
		sort(P,P+3);
		string T=P[2].second+P[1].second+P[0].second;
		if(P[2].first>T.size()/2) return _P("IMPOSSIBLE\n");
		
		string S(A+B+C,' ');
		x=0;
		FOR(i,S.size()) {
			S[x]=T[i];
			x+=2 ;
			if(x>=S.size()) x=1;
		}
		FOR(i,S.size()) if(S[i]=='R') while(BC) BC--,S=S.substr(0,i)+"RG"+S.substr(i);
		FOR(i,S.size()) if(S[i]=='Y') while(AC) AC--,S=S.substr(0,i)+"YV"+S.substr(i);
		FOR(i,S.size()) if(S[i]=='B') while(AB) AB--,S=S.substr(0,i)+"BO"+S.substr(i);
		_P("%s",S.c_str());
	}
	
	_P("\n");
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


