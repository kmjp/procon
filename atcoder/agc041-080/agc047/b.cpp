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


int N;
string S[202020];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,18> bt[26];

int same[202020][20];
int num[202020][26];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	vector<int> cand;
	cin>>N;
	FOR(i,N) {
		cand.push_back(i);
		cin>>S[i];
		reverse(ALL(S[i]));
	}
	sort(S,S+N);
	
	FOR(i,N-1) {
		j=0;
		while(j<S[i].size()&&j<S[i+1].size()&&S[i][j]==S[i+1][j]) j++;
		same[i][0]=j;
	}
	FOR(i,N) {
		//cout<<i<<" "<<S[i]<<endl;
		FORR(c,S[i]) {
			c-='a';
			num[i][c]++;
		}
		FOR(j,26) if(num[i][j]) bt[j].add(i,1);
	}
	
	FOR(i,18) {
		FOR(j,N) {
			same[j][i+1]=min(same[j][i],same[min(N,j+(1<<i))][i]);
		}
	}
	
	ll ret=0;
	for(i=1;i<=1010000;i++) {
		vector<int> cand2;
		FORR(c,cand) {
		//	cout<<i<<c<<endl;
			if(S[c].size()==i) {
				char tc=S[c].back();
				bt[tc].add(c,-1);
				
				x=c;
				y=c;
				for(j=18;j>=0;j--) {
					if(same[x][j]>=i-1) x+=1<<j;
					if(x>=N) x=N;
					if(y-(1<<j)>=0 && same[y-(1<<j)][j]>=i-1) y-=1<<j;
				}
				ret+=bt[tc](x)-bt[tc](y-1);
				//cout<<"!"<<c<<" "<<x<<" "<<y<<" "<<bt[tc](x+1)-bt[tc](y-1)<<endl;
			}
			else {
				cand2.push_back(c);
			}
		}
		FORR(c,cand2) {
			char tc=S[c][i-1];
			num[c][tc]--;
			if(num[c][tc]==0) bt[tc].add(c,-1);
		}
		swap(cand,cand2);
	}
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
