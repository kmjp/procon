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

bitset<1024> ok[1010];

class Solution {
public:
	vector<int> movesToStamp(string S, string T) {
		int num[1010]={};
		int did[1010]={};
		int fix[1010]={};
		vector<int> R;
		
		int NS=S.size();
		int NT=T.size();
		int i,j,k,x,y;
		FOR(i,NT-NS+1) {
			FOR(j,NS) {
				ok[i][j]=S[j]==T[i+j];
				num[i]+=ok[i][j];
			}
		}
		
		FOR(i,1000) {
			FOR(j,NT-NS+1) if(num[j]==NS && did[j]==0) {
				did[j]=1;
				R.push_back(j);
				FOR(x,NS) if(fix[j+x]==0) {
					fix[j+x]=1;
					FOR(y,NT-NS+1) {
						int l=j+x-y;
						if(l<0 || l>=NS) continue;
						if(ok[y][l]==0) {
							ok[y][l]=1;
							num[y]++;
						}
					}
				}
			}
		}
		
		FOR(i,NT-NS+1) if(did[i]==0) return {};
		reverse(ALL(R));
		return R;
		
	}
};
