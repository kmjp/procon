#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int U;
vector<string> S;

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>U;
	S.clear();
	set<int> DS;
	int C[26]={};
	FOR(i,10000) {
		string s;
		cin>>s;
		cin>>s;
		FORR(c,s) DS.insert(c);
		if(s.size()==U) {
			C[s[0]-'A']++;
		}
	}
	
	vector<pair<int,int>> V;
	FORR(c,DS) V.push_back({-C[c-'A'],c});
	sort(ALL(V));
	string T;
	T+=V.back().second;
	V.pop_back();
	FORR(v,V) T+=v.second;
	
	_P("Case #%d: %s\n",_loop,T.c_str());
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


