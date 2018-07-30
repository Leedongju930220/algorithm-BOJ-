#include <stdio.h>
#include <queue>
using namespace std;

char map[13][7];
int visit[13][7];
int visitx[100];
int visity[100];
bool ck[7];

int xd[4]={1,0,-1,0};
int yd[4]={0,1,0,-1};
int cont_cnt;

int bfs(int y, int x) // 뿌요 연결된 개수만 확인
{
    queue<int> q,qc;
    q.push( y*13+x);
    //printf("y%dnx%d\n",y,x);
    visit[y][x]=1;
    int color = map[y][x];

    int ny,nx,nc=0;
    while(!q.empty())
    {
        ny = q.front()/13;
        nx = q.front()%13;
        nc++;
        visitx[nc]= nx;
        visity[nc]= ny;
        //printf("visity[%d]=%d visitx[%d]=%d\n",nc,visity[nc],nc,visitx[nc]);
        //printf("ny%d nx%d nc%d\n",ny,nx,nc);
        q.pop(); 

        int nex,ney;
        for(int i=0; i<4;i++)
        {
            nex = nx + xd[i];
            ney = ny + yd[i];

            if(ney <0 || nex < 0 || ney >=12 || nex>=6) continue;

            if((int)map[ney][nex] == color && visit[ney][nex]==0 )
            {
                //printf("ney%d nex%d nec%d\n",ney,nex,nc+1);
                q.push(ney*13+nex);

                visit[ney][nex]=1;
            }
        }
    }
    //printf("bfs end %d\n",nc);
    return nc;
}

void del_puyo()
{
    queue<int>qd;
    for(int i=11;i>=0;i--)
    {
        for(int j=0; j<6;j++)
        {
            if(visit[i][j] >=4)
            {
                map[i][j]='.';
                visit[i][j]=0;
                if(ck[j]==0)
                {
                    for(int k=11;k>=0;k--) // 뿌요 없앤줄 세로 뿌요 위치 확인
                    {
                        if(map[k][j] != '.')
                        {
                            qd.push(k*13+j);
                            ck[j]=1;
                        }
                    }
                }
            }

        }
    }

    for(int i=0; i<7;i++) ck[i]=0;

    while(!qd.empty()) // 뿌요 하강
    {
        int ny,nx,ney;
        ny = qd.front()/ 13;
        nx = qd.front()% 13;
        qd.pop();
        //printf("ny%d nx%d\n",ny,nx);
        ney = ny+1;

        if( ney >=12) continue;
        if(map[ney][nx] == '.')
        {
            map[ney][nx]=map[ny][nx];
            map[ny][nx]='.';
            qd.push(ney*13+nx);
        }

    }
    /*
    printf("\n");
    for(int i=0; i<12;i++)
    {
        for(int j=0; j<6;j++)
        {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
    */
    for(int i=0; i<12;i++)for(int j=0; j<6;j++) visit[i][j]=0;

}

int comb_ck()
{
    int comb_cnt=0;
    for(int i=11; i>=0;i--) // 밑에서 부터 탐색
    {
        for(int j=0; j<6;j++)
        {
            if( map[i][j] !='.'&& visit[i][j]==0)
            {
                cont_cnt=bfs(i,j);

                if( cont_cnt >=4)
                {
                    comb_cnt++;
                    for(int k=1;k<=cont_cnt;k++)
                    {
                        visit[visity[k]][visitx[k]]=cont_cnt;
                    }
                }
            }

        }
    }
    return comb_cnt;
}

int main(void)
{
    for(int i=0; i<12;i++)
    {
        for(int j=0; j<6;j++)
        {
            scanf(" %c",&map[i][j]);
        }
    }

    bool success=1;
    int result=0;
    while(1)
    {

        success = comb_ck();
        if(success == 0) break;
        del_puyo();
        result++;
    }
    printf("%d",result);

    return 0;
}
