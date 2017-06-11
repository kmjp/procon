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

ll p10[11];
int N;
string S;
map<string,vector<string>> pre[10];

int T;
int fact[10];

string getdecay(string A) {
	int N=A.size();
	string B(N,'0');
	FORR(c,A) if(c!='0') B[c-'1']++;
	return B;
}

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	int ret=0;
	cin>>S;
	
	N=S.size();
	queue<string> Q;
	set<string> did;
	
	Q.push(S);
	did.insert(S);
	while(Q.size()) {
		S=Q.front();
		Q.pop();
		ret++;
		
		x=y=0;
		FOR(i,N) x+=(S[i]-'0');
		FOR(i,N) y+=(i+1)*(S[i]-'0');
		if(y<=N) {
			FORR(e,pre[N][S]) if(did.count(e)==0) {
				did.insert(e);
				Q.push(e);
			}
		}
		else {
			int tot=fact[N];
			int left=N;
			FORR(c,S) tot /= fact[c-'0'], left-=c-'0';
			if(left>=0) ret+=tot/fact[left];
		}
	}
	
	_P("Case #%d: %d\n",_loop,ret);
	
}

void dfs(string S,int D,int T) {
	if(S.size()==D) {
		string T=getdecay(S);
		if(S!=T) pre[D][T].push_back(S);
		return;
	}
	int i;
	for(i=0;T+i<=D;i++) {
		S.push_back((char)('0'+i));
		dfs(S,D,T+i);
		S.pop_back();
	}
}

void init() {
	int f,i,j,k,l,x,y;
	p10[0]=1;
	FOR(i,9) p10[i+1]=p10[i]*10;
	fact[0]=1;
	for(i=1;i<=9;i++) fact[i]=fact[i-1]*i;
	for(i=1;i<=9;i++) dfs("",i,0);
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


