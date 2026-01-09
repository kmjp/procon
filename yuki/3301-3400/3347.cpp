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


int ask(vector<int> V) {
	cout<<"? "<<V.size();
	FORR(a,V) cout<<" "<<a;
	cout<<endl;
	string s;
	cin>>s;
	return s=="Yes";
}

int N;
int C[505];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<int> cur;
	for(i=1;i<=N;i++) {
		for(j=1;j<=N;j++) {
			vector<int> V(j,i);
			if(ask(V)) {
				C[i]=j;
			}
			else {
				break;
			}
		}
		if(C[i]==0) continue;
		if(cur.empty()) {
			FOR(j,C[i]) cur.push_back(i);
			continue;
		}
		vector<int> Q(C[i]+1);
		Q[0]=cur.size();
		for(j=1;j<=C[i];j++) {
			int L=0,R=Q[j-1]+1;
			while(R-L>=2) {
				int M=(L+R)/2;
				vector<int> D;
				FOR(k,M) D.push_back(cur[k]);
				FOR(k,j) D.push_back(i);
				if(ask(D)) {
					L=M;
				}
				else {
					R=M;
				}
				
			}
			Q[j]=L;
		}
		FOR(j,C[i]) {
			x=Q[j+1];
			cur.insert(cur.begin()+x,i);
		}
	}
	cout<<"!";
	FORR(a,cur) cout<<" "<<a;
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
