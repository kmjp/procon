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

int N,B,F;

string C[5];
string R[5];
string cand[1<<16][4];
int num[1024/16];
int rmask[1024/16];

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>N>>B>>F;
	FOR(i,5) {
		cout<<C[i].substr(0,N)<<endl;
		cin>>R[i];
		R[i]+=C[i].substr(N);
	}
	ZERO(num);
	
	int cur=-1;
	int p=-1;
	FORR(r,R[4]) {
		if(r!=p) cur++;
		p=r;
		num[cur]++;
	}
	
	cur=0;
	FOR(i,1024/16) {
		rmask[i]=-1;
		for(int mask=0;mask<1<<16;mask++) if(__builtin_popcount(mask)==num[i]) {
			int ok=1;
			FOR(j,4) if(cand[mask][j]!=R[j].substr(cur,num[i])) ok=0;
			if(ok) rmask[i]=mask;
		}
		assert(rmask[i]!=-1);
		
		cur+=num[i];
	}
	
	vector<int> ret;
	
	FOR(i,N) {
		if((rmask[i/16]&(1<<(i%16)))==0) ret.push_back(i);
	}
	FOR(i,ret.size()) {
		cout<<ret[i];
		if(i==ret.size()-1) cout<<endl;
		else cout<<" ";
	}
	
	cin>>x;
	assert(x==1);
	
	
}

void init() {
	int i,j,mask;
	FOR(i,5) {
		FOR(j,1024) C[i].push_back('0'+(j/(1<<i))%2);
	}
	FOR(mask,1<<16) {
		FOR(j,16) if(mask&(1<<j)) {
			FOR(i,4) {
				cand[mask][i].push_back('0'+(j/(1<<i))%2);
			}
		}
	}
	
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
	}
	
	start = ts;
	span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
	fprintf(stderr,"**Total time: %lld ms\n",span/1000);
	
	return 0;
}


