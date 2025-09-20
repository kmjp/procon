#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

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
int P[2525];
int re[2525];

int Q[2525];
int cnt;

int ask(int a,int b,int c) {
	
	cnt++;
	if(Q[0]||Q[1]) {
		return Q[a]+Q[b]>Q[c];
	}
	else {
		cout<<"? "<<a+1<<" "<<b+1<<" "<<c+1<<endl;
		string s;
		cin>>s;
		return s=="Yes";
	}
}

int more(int a,int b) {
	return ask(a,re[1],b);
}

void ans() {
	cout<<"!";
	int i;
	FOR(i,N) cout<<" "<<P[i];
	cout<<endl;
	cerr<<"$ ";
	FOR(i,N) cerr<<" "<<Q[i];
	cerr<<endl;
	//assert(cnt<25000);
	cerr<<cnt<<endl;
	if(Q[0]||Q[1]) {
		FOR(i,N) assert(P[i]==Q[i]);
	}
	exit(0);
}

vector<int> merge(vector<int> A,vector<int> B) {
	vector<int> R;
	int a=0,b=0;
	while(a<A.size()||b<B.size()) {
		if(a<A.size()&&b<B.size()) {
			if(more(A[a],B[b])) {
				R.push_back(B[b++]);
			}
			else {
				R.push_back(A[a++]);
			}
		}
		else if(a<A.size()) {
			R.push_back(A[a++]);
		}
		else {
			R.push_back(B[b++]);
		}
	}
	return R;
}

void solve() {
	int i,j,k,l,r,x,y; 
	MINUS(re);
	cin>>N;
	
	//FOR(i,N) Q[i]=i+1;
	random_shuffle(Q,Q+N);
	
	//1ÇãÅÇﬂÇÈ
	int f=0;
	for(i=1;i<N;i++) {
		x=ask(i,i,f);
		if(x==0) f=i;
	}
	
	P[f]=1;
	re[1]=f;
	
	queue<vector<int>> Q;
	FOR(i,N) if(i!=f) {
		Q.push({i});
	}
	while(Q.size()>1) {
		auto a=Q.front();
		Q.pop();
		auto b=Q.front();
		Q.pop();
		Q.push(merge(a,b));
	}
	auto v=Q.front();
	FOR(i,N-1) P[v[i]]=i+2;
	
	
	ans();
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
