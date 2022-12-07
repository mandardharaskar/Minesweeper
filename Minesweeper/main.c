#include<stdio.h>
const int max_x_y[64] = {0};

void vInit(void);
void vDrawGameBlock(void);
void vAddMine(void);
void vSelectGameBlock(void);

static int sbOption = 0;
static int sbCase = 0;

int m1,m2,m3,m4,m5 = 0;

enum{
    MINE = 1,
    PLAY,
    TEST,
}Game_Modes;

int main()
{

    printf("Hello World\n");
    vInit();
    return 0;
}

void vInit(void)
{
    //Game_Modes xT_Play;

    printf("Select the Below Choice from the Number :\n");
    printf("1. Add Mines.\n");
    printf("2. Play Game.\n");
    printf("3. Test Case.\n");
    scanf("%d",&sbOption);
    printf("Selected Option No : %d \n \n",sbOption);
    sbSetOptionsNo(sbOption);

    switch(sbOption)
    {
        case MINE:
            vAddMine();
            break;

        case PLAY:
            vSelectGameBlock();
            break;

        case TEST:
            vTestCase();
            break;

        default :
            break;
    }
}

void vTestCase(void)
{
    printf("I am in TestCase : \n");
}


int sbSetOptionsNo(int sbOpt)
{
    sbCase = sbOpt;
    return sbCase;
}

void vAddMine(void)
{
    printf("I am in AddMine : \n \n");

    vDrawGameBlock();

    printf("\n Choose 5 RC combination to Add Mine : \n");
    scanf("%d",&m1);
    scanf("%d",&m2);
    scanf("%d",&m3);
    scanf("%d",&m4);
    scanf("%d",&m5);

    printf("Mine are added at : %d\n %d\n %d\n %d\n %d\n ",m1,m2,m3,m4,m5);

    for(int i=0;i<9;i++)//Row
    {
        if(i<1)
            printf("    ");
        else
            printf(" R%d",i-1);

        for(int j=0;j<8;j++)//Column
        {
            if(i<1)
                printf("C%d ",j);
            else
            {
                if(i==m1%10 && j==m1/10 )
                    printf(" M ");
                else if(i==m2%10 && j==m2/10 )
                    printf(" M ");
                else if(i==m3%10 && j==m3/10 )
                    printf(" M ");
                else if(i==m4%10 && j==m4/10 )
                    printf(" M ");
                else if(i==m5%10 && j==m5/10 )
                    printf(" M ");
                else
                    printf(" * ");
            }

        }
        printf("\n");
    }

}

void vDrawGameBlock(void)
{
    for(int i=0;i<9;i++)//Row
    {
        if(i<1)
            printf("    ");
        else
            printf(" R%d",i-1);

        for(int j=0;j<8;j++)//Column
        {
            if(i<1)
                printf("C%d ",j);
            else
                printf(" * ");
        }
        printf("\n");
    }
}

void vSelectGameBlock(void)
{
    printf("I am in Select Blocks : \n");
}
