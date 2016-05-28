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

int N,R,P,S;
vector<int> memo[5][50];

vector<int> win(int cur,int level) {
	vector<int>& v= memo[cur][level];
	if(v.empty()) {
		if(level==0) {
			v.push_back(cur);
		}
		else {
			vector<int> a,b;
			if(cur==0) a=win(0,level-1),b=win(1,level-1);
			if(cur==1) a=win(1,level-1),b=win(2,level-1);
			if(cur==2) a=win(2,level-1),b=win(0,level-1);
			FORR(r,a) v.push_back(r);
			FORR(r,b) v.push_back(r);
		}
	}
	return v;
}
string sortsort(string S) {
	if(S.size()==1) return S;
	
	string a=sortsort(S.substr(0,S.size()/2));
	string b=sortsort(S.substr(S.size()/2));
	return min(a,b)+max(a,b);
	
}

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	char SS[4]="PRS";
	cin>>N>>R>>P>>S;
	
	vector<int> V[3];
	V[0]=win(0,N);
	V[1]=win(1,N);
	V[2]=win(2,N);
	string Ret="";
	FOR(i,3) {
		int num[3]={};
		FORR(r,V[i]) num[r]++;
		if(num[0]!=P) continue;
		if(num[1]!=R) continue;
		if(num[2]!=S) continue;
		string s;
		FORR(r,V[i]) s+=SS[r];
		s=sortsort(s);
		if(Ret.empty() || s<Ret) Ret=s;
	}
	
	
	if(Ret.empty()) {
		_P("Case #%d: IMPOSSIBLE\n",_loop);
	}
	else {
		_P("Case #%d: %s\n",_loop,Ret.c_str());
	}
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


