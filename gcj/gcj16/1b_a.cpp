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

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	string S;
	int cnt[256]={};
	int ret[10]={};
	cin>>S;
	FORR(r,S) cnt[r]++;
	
	_P("Case #%d: ",_loop);
	
	while(cnt['Z']) ret[0]++, cnt['Z']--,cnt['E']--,cnt['R']--,cnt['O']--;
	while(cnt['G']) ret[8]++, cnt['E']--,cnt['I']--,cnt['G']--,cnt['H']--,cnt['T']--;
	while(cnt['H']) ret[3]++, cnt['T']--,cnt['H']--,cnt['R']--,cnt['E']--,cnt['E']--;
	while(cnt['W']) ret[2]++, cnt['T']--,cnt['W']--,cnt['O']--;
	while(cnt['R']) ret[4]++, cnt['F']--,cnt['O']--,cnt['U']--,cnt['R']--;
	while(cnt['X']) ret[6]++, cnt['S']--,cnt['I']--,cnt['X']--;
	while(cnt['S']) ret[7]++, cnt['S']--,cnt['E']--,cnt['V']--,cnt['E']--,cnt['N']--;
	while(cnt['F']) ret[5]++, cnt['F']--,cnt['I']--,cnt['V']--,cnt['E']--;
	while(cnt['I']) ret[9]++, cnt['N']--,cnt['I']--,cnt['N']--,cnt['E']--;
	while(cnt['O']) ret[1]++, cnt['O']--,cnt['N']--,cnt['E']--;
	
	FOR(i,10) while(ret[i]--) _P("%d",i);
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


