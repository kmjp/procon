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

int L[101010],R[101010];
int S[101010];


class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
		int i,N=s.size();
		FOR(i,N) {
			if(i) L[i]=L[i-1],S[i]=S[i-1];
			else L[i]=-1,S[i]=0;
			if(s[i]=='|') {
				L[i]=i;
			}
			else {
				S[i]++;
			}
		}
		R[N]=N;
		for(i=N-1;i>=0;i--) {
			if(s[i]=='|') {
				R[i]=i;
			}
			else R[i]=R[i+1];
		}
		vector<int> V;
		FORR(a,queries) {
			if(R[a[0]]>a[1]) {
				V.push_back(0);
			}
			else {
				a[0]=R[a[0]];
				a[1]=L[a[1]];
				V.push_back(S[a[1]]-S[a[0]]);
			}
		}
		return V;
        
    }
};
