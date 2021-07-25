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


ll S[101010];
int T[101010];
class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        ZERO(S);
        ZERO(T);
        FORR(s,segments) {
			S[s[0]]+=s[2];
			S[s[1]]-=s[2];
			T[s[0]]++;
			T[s[1]]++;
		}
		vector<vector<ll>> V;
		int i;
		for(i=1;i<=100020;i++) {
			S[i]+=S[i-1];
			if(S[i]) {
				if(S[i]==S[i-1]&&T[i]==0) V.back()[1]++;
				else {
					V.push_back({i,i+1,S[i]});
				}
			}
			
		}
		return V;
    }
};
