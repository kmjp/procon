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

int T,N;
int ok[101];

pair<int,int> ask() {
	int i;
	int k=0;
	FOR(i,N) if(ok[i]) k++;
	cout<<"? "<<k;
	FOR(i,N) if(ok[i]) cout<<" "<<i+1;
	cout<<endl;
	cin>>i>>k;
	if(i>k) swap(i,k);
	return {i-1,k-1};
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	srand(time(NULL));
	
	cin>>T;
	while(T--) {
		cin>>N;
		while(1) {
			x=rand()%N;
			y=rand()%N;
			if(x==y) continue;
			FOR(i,N) ok[i]=1;
			ok[x]=ok[y]=0;
			auto p=ask();
			if(p.first==N/2-1&&p.second==N/2) break;
		}
		vector<int> C,cand;
		FOR(i,N) if(i!=x&&i!=y) C.push_back(i);
		while(C.size()) {
			i=C.back();
			C.pop_back();
			j=C.back();
			C.pop_back();
			ZERO(ok);
			ok[i]=ok[j]=ok[x]=ok[y]=1;
			auto p=ask();
			if(p.first==N/2||p.second==N/2||p.first==N/2-1||p.second==N/2-1) cand.push_back(i),cand.push_back(j);
		}
		
		FORR(c,cand) FORR(d,cand) if(c<d) {
			ZERO(ok);
			ok[c]=ok[d]=ok[x]=ok[y]=1;
			auto p=ask();
			if(p.first==N/2-1&&p.second==N/2) {
				cout<<"! "<<c+1<<" "<<d+1<<endl;
				goto out;
			}
		}
		out:
		;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
