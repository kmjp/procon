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
deque<int> A[1010];
int step[1010];
int M;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		FOR(j,N-1) {
			cin>>x;
			A[i].push_back(x-1);
		}
	}
	M=N*(N-1)/2;
	
	queue<int> Q;
	FOR(i,N) Q.push(i);
	
	int num=0;
	while(Q.size()) {
		int ok=0;
		
		queue<int> Q2;
		
		while(Q.size()) {
			i=Q.front();
			Q.pop();
			if(step[i]<=num && A[i].size() && A[A[i].front()].front()==i && step[A[i].front()]<=num) {
				step[i]=step[A[i].front()]=num+1;
				Q2.push(i);
				Q2.push(A[i].front());
				A[A[i].front()].pop_front();
				A[i].pop_front();
				M--;
			}
		}
		num++;
		if(M==0) break;
		swap(Q,Q2);
	}
	
	if(M) cout<<-1<<endl;
	else cout<<num<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
