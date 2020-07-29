#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<math.h>

int judge_if_my_head(int value)
{
    if(value>=91350&&value<=91353){return 1;}
    int reverse_value=-value;
    if(reverse_value>=913500&&reverse_value<=913502){return 1;}
    if(reverse_value>=912510&&reverse_value<=913512){return 1;}
    if(reverse_value>=913520&&reverse_value<=913522){return 1;}
    if(reverse_value>=913530&&reverse_value<=913532){return 1;}
    return 0;
}

int judge_if_my_neck(int value)
{
    if(value>=19221350&&value<=19221359){return 1;}
    if(value>=192213510&&value<=192213599){return 1;}
    return 0;
}

int judge_props_num(int value)
{
    if(value>=19221350&&value<=19221359){return value%10;}
    if(value>=192213510&&value<=192213599){return value%100;}
    return 0;
}

int get_now_direction(int my_head,int my_neck)
{
    int direction;
    if(my_head-my_neck==1){direction=2;}
    if(my_head-my_neck==-1){direction=0;}
    if(my_head-my_neck==40){direction=3;}
    if(my_head-my_neck==-40){direction=1;}
    return direction;
}

int test_distance(int apos,int bpos)
{
    int aposX=apos%40;
    int aposY=apos/40;
    int bposX=bpos%40;
    int bposY=bpos/40;
    int distance=0;
    distance=abs(aposX-bposX)+abs(aposY-bposY);
    return distance;
}


int react(int *map)
{
    int my_head=-1;
    int my_neck=-1;
    int my_shield=-1;
    int direction=-1;
    int min=10000;
    int food_pos=0;
    for(int i=0;i<1200;i++)
    {
        if(judge_if_my_head(map[i])){my_head=i;}
        if(judge_if_my_neck(map[i]))
        {
            my_neck=i;
            my_shield=judge_props_num(map[i]);
        }
    }
    if(my_shield>5)
    {
        return 4;
    }

    int headX=my_head%40;
    int headY=my_head/40;
    direction=get_now_direction(my_head,my_neck);
    int cannotgo[4]={0};
    if(direction==0){cannotgo[2]=1;}
    else if(direction==2){cannotgo[0]=1;}
    else if(direction==1){cannotgo[3]=1;}
    else if(direction==3){cannotgo[1]=1;}
    if(headX==0){cannotgo[0]=1;}
    if(headX==39){cannotgo[2]=1;}
    if(headY==0){cannotgo[1]=1;}
    if(headY==29){cannotgo[3]=1;}
    if(headX>=1)
    {
        if(map[my_head-1]>10000&&map[my_head-1]!=1922135){cannotgo[0]=1;}
    }
    if(headX<39)
    {
        if(map[my_head+1]>10000&&map[my_head+1]!=1922135){cannotgo[2]=1;}
    }
    if(headY>=1)
    {
        if(map[my_head-40]>10000&&map[my_head-40]!=1922135){cannotgo[1]=1;}
    }
    if(headY<29)
    {
        if(map[my_head+40]>10000&&map[my_head+40]!=1922135){cannotgo[3]=1;}
    }

        for(int i=-2;i<3;i++)
        {
            for(int j=-2;j<3;j++)
            {
                if((headY+i)*40+headX+j>0)
                {
                    if(map[(headY+i)*40+headX+j]>=60000&&map[(headY+i)*40+headX+j]<91350)
                    {
                        if(i>0&&j>0)
                        {
                            if(cannotgo[0]==0)
                            {
                                return 0;
                            }
                            else if(cannotgo[1]==0)
                            {
                                return 1;
                            }
                        }
                        if(i>0&&j<0)
                        {
                            if(cannotgo[1]==0)
                            {
                                return 1;
                            }
                            else if(cannotgo[2]==0)
                            {
                                return 2;
                            }
                        }
                        if(i<0&&j>0)
                        {
                            if(cannotgo[0]==0)
                            {
                                return 0;
                            }
                            if(cannotgo[3]==0)
                            {
                                return 3;
                            }
                        }
                        if(i<0&&j<0)
                        {
                            if(cannotgo[2]==0)
                            {
                                return 2;
                            }
                            if(cannotgo[3]==0)
                            {
                                return 3;
                            }
                        }
                    }
                    if(map[(headY+i)*40+headX+j]>=91360&&map[(headY+i)*40+headX+j]<99999)
                    {
                        if(my_shield<=3)
                        {
                            if(i>0&&j>0)
                            {
                                if(cannotgo[0]==0)
                                {
                                    return 0;
                                }
                                else if(cannotgo[1]==0)
                                {
                                    return 1;
                                }
                            }
                            if(i>0&&j<0)
                            {
                                if(cannotgo[2]==0)
                                {
                                    return 2;
                                }
                                else if(cannotgo[1]==0)
                                {
                                    return 1;
                                }
                            }
                            if(i<0&&j>0)
                            {
                                if(cannotgo[3]==0)
                                {
                                    return 3;
                                }
                                if(cannotgo[0]==0)
                                {
                                    return 0;
                                }
                            }
                            if(i<0&&j<0)
                            {
                                if(cannotgo[2]==0)
                                {
                                    return 2;
                                }
                                if(cannotgo[3]==0)
                                {
                                    return 3;
                                }
                            }
                        }
                        if(my_shield>=3)
                        {
                            return 4;
                        }

                        if(i<0&&j==0)
                        {
                            if(cannotgo[0]==0)
                            {
                                return 0;
                            }
                            if(cannotgo[2]==0)
                            {
                                return 2;
                            }
                            if(cannotgo[3]==0)
                            {
                                return 3;
                            }
                        }
                        if(i>0&&j==0)
                        {
                            if(cannotgo[0]==0)
                            {
                                return 0;
                            }
                            if(cannotgo[2]==0)
                            {
                                return 2;
                            }
                            if(cannotgo[1]==0)
                            {
                                return 1;
                            }
                        }
                        if(i==0&&j<0)
                        {
                            if(cannotgo[1]==0)
                            {
                                return 1;
                            }
                            if(cannotgo[3]==0)
                            {
                                return 3;
                            }
                            if(cannotgo[2]==0)
                            {
                                return 2;
                            }
                        }
                        if(i==0&&j>0)
                        {
                            if(cannotgo[1]==0)
                            {
                                return 1;
                            }
                            if(cannotgo[3]==0)
                            {
                                return 3;
                            }
                            if(cannotgo[0]==0)
                            {
                                return 0;
                            }
                        }
                    }
                }
            }
        }

    if(headY>25)
    {
        if(cannotgo[0]==0){return 0;}
        if(cannotgo[1]==0){return 1;}

    }

    for(int i=-8;i<9;i++)
    {
        for(int j=-8;j<9;j++)
        {
            if((headY+i)*40+headX+j>0&&headY+i<25)
            {
                if(my_shield<=2)
                {
                    if((map[(headY+i)*40+headX+j]<0&&map[(headY+i)*40+headX+j]>=-10000)||(map[(headY+i)*40+headX+j]>0&&map[(headY+i)*40+headX+j]<=10))
                    {
                        int temp=test_distance(my_head,(headY+i)*40+headX+j);
                        if(temp<min)
                        {
                            min=temp;
                            food_pos=(headY+i)*40+headX+j;
                        }

                        if(temp==min&&map[(headY+i)*40+headX+j]<map[food_pos])
                        {
                            food_pos=(headY+i)*40+headX+j;
                        }

                    }
                }
                else
                {
                    if((map[(headY+i)*40+headX+j]<0&&map[(headY+i)*40+headX+j]>=-200)||(map[(headY+i)*40+headX+j]>0&&map[(headY+i)*40+headX+j]<=10))
                    {
                        int temp=test_distance(my_head,(headY+i)*40+headX+j);
                        if(temp<min)
                        {
                            min=temp;
                            food_pos=(headY+i)*40+headX+j;
                        }
                        if(temp>=min&&temp<min+4&&(abs(headX+j-20)+abs(headY+i-15))<(abs(food_pos%40-20)+abs(food_pos/40-15)))
                        {
                            food_pos=(headY+i)*40+headX+j;
                        }
                        if(temp>=min&&temp<min+3&&map[(headY+i)*40+headX+j]<map[food_pos])
                        {
                            food_pos=(headY+i)*40+headX+j;
                        }
                    }
                }
            }

        }
    }
    if(food_pos%40<headX&&cannotgo[0]==0){return 0;}
    if(food_pos%40>headX&&cannotgo[2]==0){return 2;}
    if(food_pos%40==headX)
    {
        if(food_pos/40<headY&&cannotgo[1]==0){return 1;}
        if(food_pos/40>headY&&cannotgo[3]==0){return 3;}
    }
    for(int i=0;i<4;i++)
    {
        if(cannotgo[i]==0)
        {
            return i;
        }

    }
    if(my_shield>0)
    {
        return 4;
    }
    return 0;
}


int main()
{
    int amap[1200];
    for(int i=0;i<1200;i++)
    {
        scanf("%d",&amap[i]);
    }
    int des=react(amap);
    printf("%d",des);
    return 0;
}
