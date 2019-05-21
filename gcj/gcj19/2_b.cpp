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


int num[201];

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	ZERO(num);
	int add=0;
	int nex=1,tar;
	priority_queue<pair<int,int>> PQ;
	int border=60;
	for(i=1;i<=99;i++) {
		cin>>x;
		assert(x==i);
		if(i<=border) {
			cout<<(i%10)+11<<" "<<100<<endl;
		}
		else if(i<=border+10) {
			cout<<(i-border)<<" "<<0<<endl;
			cin>>x;
			num[i-border]=x;
			FOR(j,x) cin>>y;
			
			
			if(i==border+10) {
				tar=1;
				for(j=2;j<=10;j++) if(num[j] <= num[tar]) tar=j;
				for(j=1;j<=10;j++) if(j!=tar) PQ.push({-num[j],j});
			}
			
		}
		else {
			x=PQ.top().second;
			
			PQ.pop();
			cout<<x<<" "<<100<<endl;
			num[x]++;
			PQ.push({-num[x],x});
			
		}
		
		
	}
	
	cin>>x;
	assert(x==100);
	cout<<tar<<" 100"<<endl;
	
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


