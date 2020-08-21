#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M,L;
int to[51];
int in[51],vis[51];
int emp=0;

map<pair<vector<int>,vector<int>>,int> memo;

int hoge(vector<int> loop,vector<int> dag);

int dfs(vector<int>& loop,vector<int>& dag,int step,int left) {
	//cout<<"!!"<<loop[1]<<loop[2]<<loop[3]<<" "<<dag[1]<<dag[2]<<dag[3]<<" "<<step<<left<<endl;
	
	if(step==30) {
		if(left==M) return 1<<20;
		int numdag=0;
		int i;
		for(i=1;i<=15;i++) numdag+=dag[i];
		if(numdag>emp) return 1<<20;
		//cout<<"!"<<numdag<<" "<<loop[1]<<loop[2]<<loop[3]<<" "<<dag[1]<<dag[2]<<dag[3]<<endl;
		
		return 10+hoge(loop,dag);
	}
	
	if(step==16) {
		int numdag=0;
		int i;
		for(i=1;i<=15;i++) numdag+=dag[i];
		if(numdag>emp) return 1<<20;
	}
	
	int ret=dfs(loop,dag,step+1,left);
	
	if(step>=1 && step<=15&&dag[step]) {
		int len=step;
		for(int num=1;num<=min(len,left);num++) {
			dag[len]--;
			dag[len-num]++;
			ret=min(ret,dfs(loop,dag,step,left-num));
			dag[len-num]--;
			dag[len]++;
		}
	}
	if(step>=16 && step<=29&&loop[step-14]) {
		int len=step-14;
		// short path
		for(int num=2;num<=min(len,left);num++) {
			loop[len]--;
			loop[len-(num-1)]++;
			ret=min(ret,dfs(loop,dag,step,left-num));
			loop[len-(num-1)]--;
			loop[len]++;
		}
		//open path
		for(int num=1;num<=min(len-1,left);num++) {
			loop[len]--;
			dag[len-(num-1)]++;
			ret=min(ret,dfs(loop,dag,step,left-num));
			dag[len-(num-1)]--;
			loop[len]++;
		}
	}
	return ret;
	
	
}



int hoge(vector<int> loop,vector<int> dag) {
	if(memo.count({loop,dag})) return memo[{loop,dag}];
	
	int sum=0;
	int i;
	for(i=2;i<=15;i++) sum+=loop[i];
	for(i=1;i<=15;i++) sum+=dag[i];
	if(sum==0) return memo[{loop,dag}]=0;
	return memo[{loop,dag}]=dfs(loop,dag,0,M);
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(to);
	cin>>N>>M>>L;
	FOR(i,L) {
		cin>>x>>y;
		to[x-1]=y-1;
		in[y-1]=1;
	}
	emp=N-L;
	vector<int> loop(16),dag(16);
	FOR(i,N) if(in[i]==0&&vis[i]==0) {
		int cur=i;
		int num=0;
		vis[i]=1;
		while(to[cur]!=-1) {
			cur=to[cur];
			in[cur]=0;
			vis[cur]++;
			num++;
		}
		dag[num]++;
	}
	FOR(i,N) if(in[i]) {
		int cur=i;
		int num=1;
		in[cur]=0;
		while(in[to[cur]]) {
			cur=to[cur];
			in[cur]=0;
			num++;
		}
		loop[num]++;
	}
	int ret=hoge(loop,dag);
	if(ret>=1<<20) ret=-1;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
