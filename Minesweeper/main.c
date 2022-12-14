#include<stdio.h>
#include <stddef.h>
#include <stdbool.h>
const int max_x_y[64] = {0};

void vInit(void);
void vDrawGameBlock(void);
void vAddMine(void);
void vSelectGameBlock(void);

static int sbOption = 0;
static int sbCase = 0;

int m[5]= {0};
int R[5]= {0};
int C[5]= {0};
bool FlagR = false;
bool FlagC = false;

int ScanCount = 4;

enum{
    R0 = 0,
    R1,
    R2,
    R3,
    R4,
    R5,
    R6,
    R7,
}T_Row;

enum{
    C0 = 0,
    C1,
    C2,
    C3,
    C4,
    C5,
    C6,
    C7,
}T_Column;

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

int msb = 0;
int lsb = 0;

bool InputErrFlag = false;
int temp =0;
int RSCount =0;

int a,b,c=0;
int x,y=0;

void vAddMine(void)
{
    printf("I am in AddMine : \n \n");

    vDrawGameBlock();

    printf("\n Choose 5 RC combination to Add Mine : \n");
    for(int i = 0;i<=ScanCount;i++)
    {
        scanf("%d",&temp);
        if(temp == m[0] || temp == m[1] || temp == m[2] || temp == m[3])
        {
            InputErrFlag = true;
            printf("Entered Row column is Repeated. Select different RC \n");
            ScanCount = ScanCount+1;
        }
         else if(temp>77)
        {
            InputErrFlag = true;
            printf("Please choose the Correct Row & Column \n");
            ScanCount = ScanCount+1;
        }
        else{
            InputErrFlag = false;
        }

        if(InputErrFlag == false)
        {
            m[RSCount] = temp;
            RSCount = RSCount + 1;
            if(RSCount >4)
                RSCount = RSCount-1;
        }

    }
/***********Code for debugging**********/
    for(int i = 0;i<=4;i++)
    {
        R[i] = m[i]/10;//Row//msb
        C[i] = m[i]%10;//Column//lsb
        printf("\n m : %d ",m[i]);
        printf(" msb is %d & lsb is %d \n",R[i],C[i]);
    }

    printf("\n");
/***************************************/
    for(int b=0;b<8;b++)
        printf("C%d ",b);

    printf("\n");

    for(x=0;x<8;x++)
    {
        for(y=0;y<8;y++)
        {
            if(x==R[x] && y==C[y])
                printf(" M ");
            else
                printf(" * ");
        }
        printf("R%d \n",x);
    }

}

void vDrawGameBlock(void)
{
    for(int b=0;b<8;b++)
        printf("C%d ",b);

    printf("\n");

    for(int i=0;i<8;i++)//Row
    {
        for(int j=0;j<8;j++)//Column
        {
            printf(" * ");
        }
        printf(" R%d \n",i);
    }
}

void vSelectGameBlock(void)
{
    printf("I am in Select Blocks : \n");
}
