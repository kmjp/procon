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

int N,H;
int D[101010],C[101010];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> bt;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>H;
	int cur=H;
	ll ret=0;
	deque<int> Q;
	
	FOR(i,N) {
		cin>>D[i]>>C[i];
		
		bt.add(i,H-cur);
		bt.add(i+1,-(H-cur));
		
		while(Q.size() && C[Q.back()]<=C[i]) Q.pop_back();
		Q.push_back(i);
		while(cur<=D[i]) {
			x=Q[0];
			//cout<<i<<" "<<cur<<" "<<D[i]<<endl;
			
			if(Q.size()>=2 && bt(x)<=C[Q[1]]) {
				Q.pop_front();
			}
			else {
				int num=bt(x)/C[x];
				int need=(D[i]-cur+1+C[x]-1)/C[x];
				//cout<<"!"<<x<<" "<<bt(x)<<" "<<C[x]<<" "<<num<<" "<<need<<" "<<ret<<endl;
				if(num==0 && (Q.size()==1 || bt(x)>=C[Q[1]])) {
					y=bt(x);
					
					cur=min(H,cur+y);
					bt.add(0,-y);
					bt.add(i+1,y);
					ret++;
				}
				else {
					y=min(num,need);
					cur+=y*C[x];
					bt.add(0,-y*C[x]);
					bt.add(i+1,y*C[x]);
					ret+=y;
				}
			}
			
			
		}
		cur-=D[i];
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
