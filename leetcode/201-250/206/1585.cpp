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



class Solution {
public:
    bool isTransformable(string s, string t) {
		int N=s.size();
		deque<int> Q[10];
		int i,j;
		FOR(i,N) Q[s[i]-'0'].push_back(i);
		FOR(i,N) {
			int x=t[i]-'0';
			if(Q[x].empty()) return 0;
			int y=Q[x].front();
			Q[x].pop_front();
			FOR(j,x) if(Q[j].size()&&Q[j].front()<y) return 0;
			
		}
		
        return 1;
    }
};
