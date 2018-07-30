#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

vector<int> ordn[101],ordc[101];
vector<char> ord[101];
queue<int> roby[101],robx[101];
queue<int> rdir[101];
int a,b,n,m;
int map[101][101];
int xd[4]={1,-1,0,0};
int yd[4]={0,0,-1,1};
int acc_wallnum;
int acc_rob1,acc_rob2;

int dir_change(char a)
{
    if( a == 'E') return 0;
    else if( a == 'W') return 1;
    else if( a == 'S') return 2;
    else if( a == 'N') return 3;
}
int turn_left(int nd)
{
    if( nd == 0) return 3;
    else if( nd == 3) return 1;
    else if( nd == 1) return 2;
    else if( nd == 2) return 0;
}

int turn_right(int nd)
{
    if( nd == 0) return 2;
    else if( nd == 2) return 1;
    else if( nd == 1) return 3;
    else if( nd ==3) return 0;
}

int main(void)// E =69, W=87, S=83, N=78
{             // L =76 R = 82 F =70
    //printf("L%d R%d F%d ",'L','R','F');
    scanf("%d %d",&a,&b);
    scanf("%d %d",&n,&m);

    for(int i=1;i<=n;i++)
    {
        int x,y,dir;
        char z;
        scanf("%d %d %c",&x,&y,&z);
        roby[i].push(y);
        robx[i].push(x);
        dir = dir_change(z);
        rdir[i].push(dir);
        map[y][x]=i;
    }

    for(int i=0; i< m; i++)
    {
        int num,cnt;
        char order;
        scanf("%d %c %d",&num,&order,&cnt);
        ordn[i].push_back(num);
        ordc[i].push_back(cnt);
        ord[i].push_back(order);
    }

    for(int i=0; i<m ; i++)
    {
        int r_num,mov_cnt, order;
        r_num = ordn[i][0];
        mov_cnt = ordc[i][0];
        order = ord[i][0];
        //printf("rnum %d movcnt %d  order %c \n",r_num,mov_cnt,order);

        int ry,rx,rd;
        ry = roby[r_num].front(); 
        rx = robx[r_num].front(); 
        rd = rdir[r_num].front();
        map[ry][rx]=0;

        bool accident_wall =0;
        bool accident_rob =0;
        bool move_end=0;

        while( !(move_end))
        {       
            ry = roby[r_num].front();
            rx = robx[r_num].front();
            rd = rdir[r_num].front();
            roby[r_num].pop(); rdir[r_num].pop();robx[r_num].pop();

            //printf("rnum %d  y%d  x%d d%d \n",r_num,ry,rx,rd);
            int rney,rnex;
            if( order == 'F')
            {
                for(int i=1;i<=mov_cnt;i++)
                {
                    rney = ry + yd[rd]*i;
                    rnex = rx + xd[rd]*i;
                    //printf("rnum %d  ny%d  nx%d d%d \n",r_num,rney,rnex,rd);
                    if( rney < 1 || rnex <1 || rney > b || rnex > a  ) 
                    {
                        accident_wall=1;
                        acc_wallnum= r_num;
                        break;
                    }

                    if( map[rney][rnex] == 0 )
                    {
                        if( i == mov_cnt)
                        {
                            roby[r_num].push( rney);
                            robx[r_num].push( rnex);
                            rdir[r_num].push(rd);
                            map[rney][rnex]=r_num;
                            move_end=1;

                        }
                        continue;
                    }
                    else if( map[rney][rnex] !=0)
                    {
                        accident_rob =1;
                        acc_rob1 = r_num;
                        acc_rob2 = map[rney][rnex];
                        break;
                    }

                }

            }// L명령
            else if( order == 'L')
            {   
                for(int i=0; i< mov_cnt; i++)
                {
                    rd = turn_left(rd);
                    //printf("rnum %d  ny%d  nx%d rd%d \n",r_num,ry,rx,rd);
                    if( i == mov_cnt-1)
                    {
                        roby[r_num].push( ry);
                        robx[r_num].push( rx);
                        rdir[r_num].push(rd);
                        map[ry][rx]=r_num;
                        move_end=1;
                        //printf("L rnum %d  ny%d  nx%d rned%d \n",r_num,ry,rx,rd);
                    }
                }
            }//R명령
            else if( order == 'R')
            {
                for(int i=0; i< mov_cnt; i++)
                {
                    rd = turn_right(rd);

                    if( i == mov_cnt-1)
                    {
                        roby[r_num].push( ry);
                        robx[r_num].push( rx);
                        rdir[r_num].push(rd);
                        map[ry][rx]=r_num;
                        move_end=1;

                    }
                }
            }
            if(accident_wall || accident_rob ) break;       
    }// while( !q.empty())

        if( accident_wall)
        {
            printf("Robot %d crashes into the wall\n",acc_wallnum);
            break;
        }
        else if( accident_rob)
        {
            printf("Robot %d crashes into robot %d\n",acc_rob1,acc_rob2);
            break;
        }
        else if( i == m -1) 
        {
                printf("OK\n");
        }

    }// m개 명령 수행

    return 0;

    }
