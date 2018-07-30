#include <stdio.h>
#include <queue>
using namespace std;
int n,m;
char map[26][26];
char res[7]={'1','2','3','4','|','-','+'};
bool visit[26][26];
int gx,gy;
int sx,sy;
int by,bx;
bool sucm=0,sucz=0;
int xd[4]={1,0,-1,0};
int yd[4]={0,1,0,-1};
int dir[7][4]={{1,1,0,0},{1,0,0,1},{0,0,1,1},{0,1,1,0},{0,1,0,1},{1,0,1,0},{1,1,1,1}};

int ch(char a)
{
    for(int i=0;i<7;i++)
    {
        if( res[i]== a)
        {
            return i;
        }
    }
}
int re(int a)
{
    if( a == 0) return 2;
    else if( a== 1) return 3;
    else if( a== 2) return 0;
    else if( a==3) return 1;
}

int bfs(int y, int x)
{
    queue<int> q,qd;
    int ny,nx,nd;
    for(int i=0;i<4;i++)
    {
        ny = y+yd[i];
        nx = x+xd[i];
        if( ny <0 || nx <0 || ny >=n || nx >=m) continue;
        if(map[ny][nx] == '.' || map[ny][nx] == 'Z')continue;
        q.push(y*26+x);
        qd.push(i);
        visit[y][x]=1;
    }
    while( !q.empty())
    {
        ny = q.front()/26;
        nx = q.front()%26;
        nd = qd.front();
        q.pop(); qd.pop();
        //printf("ny%d nx%d nd%d\n",ny,nx,nd);
        int ney,nex,ned;
        ney = ny+yd[nd];
        nex = nx+xd[nd];
        //printf("ney %d nex %d map %c\n",ney,nex,map[ney][nex]);
        if( map[ney][nex] == '.') return ney*26+nex;
        if( map[ney][nex] == 'Z') return 0;
        if( map[ney][nex] == '1')
        {       
            if( nd == 3) ned =0;
            else if(nd == 2) ned=1;
            else if(nd ==1 || nd == 0) continue;
            //printf("ney%d nex%d ned%d\n",ney,nex,ned);
            q.push(ney*26+nex);
            qd.push(ned);
        }
        else if( map[ney][nex] == '2')
        {
            if(nd == 2) ned=3;
            else if(nd ==1) ned=0;
            else if(nd ==3 || nd == 0) continue;
            q.push(ney*26+nex);
            qd.push(ned);
        }
        else if( map[ney][nex] == '3')
        {

            if(nd == 0) ned=3;
            else if(nd == 1) ned =2;
            else if(nd ==2 || nd == 3) continue;
            qd.push(ned);
            q.push(ney*26+nex);
        }
        else if( map[ney][nex] == '4')
        {
            if(nd == 0) ned=1;
            else if(nd ==3) ned =2;
            else if(nd ==1 || nd == 2) continue;
            q.push(ney*26+nex);
            qd.push(ned);
        }
        else if( map[ney][nex] == '|')
        {
            if( nd == 0 || nd == 2) continue;
            q.push(ney*26+nex);
            qd.push(nd);
        }else if( map[ney][nex] == '-')
        {
            //printf("ney%d nex%d ned%d\n",ney,nex,nd);
            if( nd == 1 || nd == 3) continue;
            q.push(ney*26+nex);
            qd.push(nd);
        }else if( map[ney][nex] == '+')
        {
            if( nd == 0)
            {
                for(int i=0;i<4;i++)
                {
                    if( i == 2) continue;
                    q.push(ney*26+nex);
                    qd.push(i);
                }
            }
            else if( nd == 1)
            {
                for(int i=0;i<4;i++)
                {
                    if( i == 3) continue;
                    q.push(ney*26+nex);
                    qd.push(i);
                }
            }
            else if( nd == 2)
            {
                for(int i=0;i<4;i++)
                {
                    if( i == 0) continue;
                    q.push(ney*26+nex);
                    qd.push(i);
                }
            }
            else if( nd == 3)
            {
                for(int i=0;i<4;i++)
                {
                    if( i == 1) continue;
                    q.push(ney*26+nex);
                    qd.push(i);
                }
            }       
        }
    }
    return 0;
}
int main(void)
{
    //for(int i=0;i<7;i++) printf("%c ",res[i]);
    scanf("%d %d",&n,&m);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf(" %1c",&map[i][j]);
            if( map[i][j] == 'M')
            {
                sy=i;sx=j;
            }
            else if( map[i][j] =='Z')
            {
                gy=i;gx=j;
            }
        }
    }
    //print();
    int pos= bfs(sy,sx);
     by = pos/26;
     bx = pos%26;
    //printf("y%d x%d\n",by+1,bx+1);

     int ney,nex;
     for(int i=0;i<7;i++)
     {
        int err_cnt=0;
        //printf("[%c]\n",res[i]);
        for(int j=0;j<4;j++)
        {
            if( dir[ch(res[i])][j])
            {
                ney = by+ yd[j];
                nex = bx+ xd[j];
                //printf("dir %d ney%d nex%d\n",j,ney,nex);
                if( map[ney][nex] == 'M' || map[ney][nex] == 'Z') continue;
                if( ney <0 || nex <0 || ney >=n || nex >=m)err_cnt++;
                if(dir[ch(map[ney][nex])][re(j)] ==0) err_cnt++;
                if( map[ney][nex] =='.') err_cnt++;
                //printf("err[%d]\n",err_cnt);
            }
            else if(!dir[ch(res[i])][j])
            {
                ney = by+ yd[j];
                nex = bx+ xd[j];
                if( ney <0 || nex <0 || ney >=n || nex >=m) continue;
                if( map[ney][nex]=='.') continue;
                if( map[ney][nex] == 'M' || map[ney][nex] == 'Z') err_cnt;
                if( dir[ ch(map[ney][nex])][re(j)]) err_cnt++;
            }
        }

        if(err_cnt == 0) printf("%d %d %c\n",by+1,bx+1,res[i]);
     }
    return 0;
}
