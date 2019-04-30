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

int W;
ll R[7];
ll V;
ll X[7],D;

map<pair<ll,ll>,vector<int>> M;

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	M.clear();
	
	cout<<210<<endl;
	cin>>V;
	
	R[6]=(V>>35)%128;
	R[5]=(V>>42)%128;
	R[4]=(V>>52)%128;
	
	cout<<40<<endl;
	cin>>V;
	
	V-=R[6]<<6;
	V-=R[5]<<8;
	V-=R[4]<<10;
	R[3]=(V>>13)%128;
	R[2]=(V>>20)%128;
	R[1]=(V>>40)%128;
	
	cout<<R[1]<<" "<<R[2]<<" "<<R[3]<<" "<<R[4]<<" "<<R[5]<<" "<<R[6]<<endl;
	cin>>x;
	assert(x==1);
	
}

void init() {
	cin>>W;
	/*
	int i,j;
	for(i=1;i<=500;i++) {
		cout<<i<<" ";
		for(j=1;j<=6;j++) {
			cout<<(i/j)<<" ";
		}
		cout<<endl;
	}
	*/
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


