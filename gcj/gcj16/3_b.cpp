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

int N;
int A[101];
string E;
int M;
string C[5];
vector<int> R[101],ST;

string S;

unordered_set<string> U;

string concat(string a,string b) {
	vector<int> v(a.size(),0);
	FORR(r,b) v.push_back(1);
	random_shuffle(v.begin(),v.end());
	string c=a+b;
	int ai=0, bi=0,i;
	FOR(i,v.size()) c[i]=(v[i]==0)?a[ai++]:b[bi++];
	return c;
	
}

string hoge(int cur) {
	string ret="";
	
	FORR(r,R[cur]) {
		string rr=hoge(r);
		ret=concat(ret,rr);
	}
	
	ret = (char)cur + ret;
	return ret;
}


void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>N;
	FOR(i,N+1) R[i].clear();
	FOR(i,N) {
		cin>>A[i+1];
		R[A[i+1]].push_back(i+1);
	}
	cin>>E;
	cin>>M;
	FOR(i,M) cin>>C[i];
	
	U.clear();
	struct timeval start,end,ts;
	int hit[6]={};
	int tot=0,nl=0;
	gettimeofday(&start,NULL);
	srand(start.tv_usec);
	while(1) {
		FOR(i,100) {
			string ret=hoge(0);
			nl++;
			if(U.count(ret)) continue;
			U.insert(ret);
			string RC="";
			FORR(r,ret) if(r) RC+=E[r-1];
			
			FOR(j,M) if(RC.find(C[j])!=string::npos) hit[j]++;
			tot++;
		}
		gettimeofday(&end,NULL);
		long long span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
		if(span>1500000) break;
	}
	
	
	_P("Case #%d:",_loop);
	FOR(i,M) _P(" %.3lf",hit[i]*1.0/tot);
	//_P("  :%d/%d",tot,nl);
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


