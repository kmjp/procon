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



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int H, int W, ListNode* head) {
		vector<vector<int>> M;
		int y,x;
		M.resize(H);
		FOR(y,H) M[y].resize(W,-1);
		int dx[4]={1,0,-1,0};
		int dy[4]={0,1,0,-1};
		int dir=0;
		y=x=0;
		while(head) {
			M[y][x]=head->val;
			head=head->next;
			if(head) {
				while(1) {
					dir%=4;
					if(y+dy[dir]<0||y+dy[dir]>=H||x+dx[dir]<0||x+dx[dir]>=W) {
						dir++;
						continue;
					}
					else if(M[y+dy[dir]][x+dx[dir]]!=-1) {
						dir++;
						continue;
					}
					break;
				}
				y+=dy[dir];
				x+=dx[dir];
			}
		}
        return M;
    }
};
