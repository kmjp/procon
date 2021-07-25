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

int S[101010];

 class Solution {
public:
	
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
		vector<pair<int,int>> V;
		int i;
		
		FOR(i,times.size()) {
			V.push_back({times[i][0]*2,i});
			V.push_back({times[i][1]*2-1,i});
		}
		set<int> T;
		FOR(i,10101) T.insert(i);
		sort(ALL(V));
		FORR(v,V) {
			int x=v.second;
			if(v.first==times[x][0]*2) {
				S[x]=*T.begin();
				T.erase(S[x]);
			}
			else {
				T.insert(S[x]);
			}
		}
        return S[targetFriend];
    }
};
