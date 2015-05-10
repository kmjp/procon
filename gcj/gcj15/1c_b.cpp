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

int K,L,S;
string KS,LS;

int stt[1024][26];
const char base='A';
void CreateSTT(string& pat) {
	int x,y,z,l=pat.size();
	ZERO(stt);
	FOR(x,l+1) {
		FOR(y,26) {
			string pre=pat.substr(0,x)+(char)(base+y);
			for(z=1;z<=x;z++) if(pre.substr(pre.size()-z) == pat.substr(0,z)) stt[x][y]=z;
		}
		if(x!=l) stt[x][pat[x]-base]=x+1;
	}
}

int getmax() {
	int num=0;
	int cur=0;
	int i,y;
	
	FOR(i,S) {
		int ma=-1;
		FORR(c,KS) ma=max(ma,stt[cur][c-'A']);
		cur=ma;
		if(cur==L) num++;
	}
	return num;
}

double getexp() {
	double ret=0;
	double prob[101][101];
	int i,x,y;
	
	ZERO(prob);
	prob[0][0]=1;
	FOR(i,S) {
		FOR(x,L+1) if(prob[i][x]) {
			FORR(c,KS) {
				int ne=stt[x][c-'A'];
				if(ne==L) ret += prob[i][x]/K;
				prob[i+1][ne] += prob[i][x]/K;
			}
		}
	}
	
	return ret;
}

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>K>>L>>S;
	cin>>KS>>LS;
	
	CreateSTT(LS);
	_P("Case #%d: %.12lf\n",_loop,getmax()-getexp());
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


