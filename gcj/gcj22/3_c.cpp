#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N;
int L[101010];
int R[101010];
vector<int> in[101010];
string S="ACDEHIJKMORST";
int C[101010];
int cost[101010];

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>N;
	FOR(i,N) {
		in[i].clear();
		C[i]=-1;
		cost[i]=0;
	}
	FOR(i,N) {
		cin>>L[i];
		L[i]--;
		in[L[i]].push_back(i);
	}
	FOR(i,N) {
		cin>>R[i];
		R[i]--;
		in[R[i]].push_back(i);
	}
	
	FOR(i,N) {
		if(L[L[i]]==i) break;
		if(L[R[i]]==i) break;
		if(R[L[i]]==i) break;
		if(R[R[i]]==i) break;
	}
	
	if(i<N) {
		cout<<"Case #"<<_loop<<": IMPOSSIBLE"<<endl;
		return;
	}
	
	FOR(i,N) {
		cost[i]+=6;
		cost[L[i]]++;
		cost[R[i]]++;
		cost[L[L[i]]]++;
		cost[L[R[i]]]++;
		cost[R[L[i]]]++;
		cost[R[R[i]]]++;
	}
	queue<int> Q;
	vector<int> V;
	FOR(i,N) if(cost[i]<=12) {
		C[i]=-2;
		Q.push(i);
	}
	while(Q.size()) {
		int cur=Q.front();
		Q.pop();
		V.push_back(cur);
		vector<int> cand;
		cand.push_back(L[cur]);
		cand.push_back(R[cur]);
		cand.push_back(L[L[cur]]);
		cand.push_back(L[R[cur]]);
		cand.push_back(R[L[cur]]);
		cand.push_back(R[R[cur]]);
		FORR(e,in[cur]) {
			cand.push_back(e);
			FORR(e2,in[e]) cand.push_back(e2);
		}
		FORR(c,cand) {
			cost[c]--;
			if(C[c]==-1&&cost[c]<=12) {
				C[c]=-2;
				Q.push(c);
			}
		}
	}
	reverse(ALL(V));
	FORR(cur,V) {
		int mask=(1<<13)-1;
		vector<int> cand;
		cand.push_back(L[cur]);
		cand.push_back(R[cur]);
		cand.push_back(L[L[cur]]);
		cand.push_back(L[R[cur]]);
		cand.push_back(R[L[cur]]);
		cand.push_back(R[R[cur]]);
		FORR(e,in[cur]) {
			cand.push_back(e);
			FORR(e2,in[e]) cand.push_back(e2);
		}
		FORR(c,cand) {
			if(C[c]>=0 && (mask&(1<<C[c]))) mask^=1<<(C[c]);
		}
		FOR(i,13) if(mask&(1<<i)) C[cur]=i;
	}
	
	
	cout<<"Case #"<<_loop<<": ";
	FOR(i,N) {
		assert(C[i]!=C[L[i]]);
		assert(C[i]!=C[R[i]]);
		assert(C[i]!=C[L[L[i]]]);
		assert(C[i]!=C[L[R[i]]]);
		assert(C[i]!=C[R[L[i]]]);
		assert(C[i]!=C[R[R[i]]]);
		cout<<S[C[i]];
	}
	cout<<endl;
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


