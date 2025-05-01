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

ll Q,X,Y,Z;

const int DI=1200;
deque<int> M[DI+2];
ll S[DI+2][2];

void addX(int id,int v) {
	M[id].push_back(v);
	sort(ALL(M[id]));
	S[id][0]=S[id][1]=0;
	int step=0;
	FORR(a,M[id]) {
		S[id][step]+=a;
		step^=1;
	}
}
void addL(int id,int v) {
	M[id].push_front(v);
	swap(S[id][0],S[id][1]);
	S[id][0]+=v;
}
void addR(int id,int v) {
	M[id].push_back(v);
	S[id][(M[id].size()%2)^1]+=v;
}
void delL(int id) {
	S[id][0]-=M[id][0];
	M[id].pop_front();
	swap(S[id][0],S[id][1]);
}
void delR(int id) {
	S[id][(M[id].size()%2)^1]-=M[id].back();
	M[id].pop_back();
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	ll ret=0;
	cin>>Q;
	FOR(j,Q) {
		cin>>Y;
		X=(Y+ret)%1000000000+1;
		
		int cur=-1,tar=j%DI;
		FOR(i,DI) {
			if(M[i].empty()||X<=M[i].back()) {
				cur=i;
				break;
			}
		}
		if(cur==-1) cur=DI-1;
		addX(cur,X);
		
		while(cur<tar) {
			addL(cur+1,M[cur].back());
			delR(cur);
			cur++;
		}
		while(tar<cur) {
			addR(cur-1,M[cur][0]);
			delL(cur);
			cur--;
		}
		
		ret=0;
		int num=0;
		FOR(i,DI) if(M[i].size()) {
			ret+=S[i][num%2];
			num+=M[i].size();
		}
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
