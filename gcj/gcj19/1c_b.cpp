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

int F;

vector<int> V[6][6];

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	string s;
	FOR(x,6) FOR(y,6) V[x][y].clear();
	vector<int> C;
	FOR(i,119) C.push_back(i);
	string R;
	
	int mask=(1<<5)-1;
	FOR(i,4) {
		FORR(c,C) {
			cout<<(c*5+i+1)<<endl;
			cin>>s;
			V[i][s[0]-'A'].push_back(c);
		}
		x=-1;
		FOR(j,5) if((mask&(1<<j)) && (x==-1 || V[i][j].size()<V[i][x].size())) x=j;
		R.push_back('A'+x);
		C=V[i][x];
		mask ^= 1<<x;
	}
	
	FOR(i,5) {
		if(count(ALL(R),'A'+i)==0) R.push_back('A'+i);
	}
	cout<<R<<endl;
	cin>>s;
	assert(s=="Y");
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


