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
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
		int N=friends.size();
		int D[101][101]={};
		int x,y,z;
		FOR(x,N) FOR(y,N) D[x][y]=(x==y)?0:1010;
		FOR(x,N) FORR(f,friends[x]) D[x][f]=1;
		FOR(z,N) FOR(x,N) FOR(y,N) D[x][y]=min(D[x][y],D[x][z]+D[z][y]);
		map<string,int> M;
		FOR(x,N) if(D[id][x]==level) {
			FORR(w,watchedVideos[x]) M[w]++;
		}
		vector<pair<int,string>> S;
		FORR(m,M) S.push_back({m.second,m.first});
		sort(ALL(S));
		vector<string> T;
		FORR(s,S) T.push_back(s.second);
		return T;
    }
};
