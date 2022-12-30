#include<stdio.h>
#include <stddef.h>
#include <stdbool.h>
const int max_x_y[64] = {0};

void vInit(void);
void vDrawGameBlock(void);
void vAddMine(void);
void vPlayGame(void);
void vSelectGameBlock(void);

static int sbOption = 0;
static int sbCase = 0;

int m[5]= {0};
int R[5]= {0};
int C[5]= {0};
bool FlagR = false;
bool FlagC = false;

int msb = 0;
int lsb = 0;

bool InputErrFlag = false;
bool bSetMineFlag = false;
int temp,tempprev =0;
int RSCount =1;
int ScanCount = 5;

bool InputErrFlag2 = false;
bool bSetMineFlag2 = false;
int temp2,tempprev2 =0;
int RSCount2 =1;
int ScanCount2 = 5;
bool bRepeatInputFlag =false;
bool bGameOverFlag =false;


int PB[60]= {0};//play Block Input
int PBR[60]= {0};//Play block Row
int PBC[60]= {0};//Play Block column

int a,b,c=1;
int x,y=1;

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

    printf("\nSelect the Below Choice from the Number :\n");
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
            vInit();
            break;

        case PLAY:
            vPlayGame();//vSelectGameBlock();
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
    for(int i = 1;i<=ScanCount;i++)
    {
        scanf("%d",&temp);
        if((temp>88) || (temp == 0) || (temp%10 == 9) || (temp%10 == 0))//check the column is not 9th
        {
            InputErrFlag = true;
            printf("Please choose the Correct Row & Column \n");
            ScanCount = ScanCount+1;
        }
        else if(temp == m[1] || temp == m[2] || temp == m[3] || temp == m[4])
        {
            InputErrFlag = true;
            printf("Entered Row column is Repeated. Select different RC \n");
            ScanCount = ScanCount+1;
        }
        else{
            InputErrFlag = false;
        }

        if(InputErrFlag == false)
        {
            m[RSCount] = temp;
            RSCount = RSCount + 1;
            if(RSCount >5)
                RSCount = RSCount-1;

        }

    }

/***********Code for debugging**********/
    for(int i = 1;i<=5;i++)
    {
        R[i] = m[i]/10;//Row//msb
        C[i] = m[i]%10;//Column//lsb
        printf("\n m : %d ",m[i]);
        printf(" msb is %d & lsb is %d \n",R[i],C[i]);
    }

    printf("\n");
/***************************************/
    for(int b=1;b<9;b++)
        printf("C%d ",b);

    printf("\n");

    for(x=1;x<9;x++)
    {
        for(y=1;y<9;y++)
        {
            if(x==R[1] && y==C[1])
                bSetMineFlag = true;
            else if(x==R[2] && y==C[2])
                bSetMineFlag = true;
            else if(x==R[3] && y==C[3])
                bSetMineFlag = true;
            else if(x==R[4] && y==C[4])
                bSetMineFlag = true;
            else if(x==R[5] && y==C[5])
                bSetMineFlag = true;
            else
                bSetMineFlag = false;

            if(bSetMineFlag)
                printf(" M ");
            else
                printf(" * ");
        }
        printf("R%d \n",x);
    }

}

void vPlayGame(void)
{
  vDrawGameBlock();

    for(int i = 1;i<=ScanCount2;i++)
    {
        printf("\nPlease Enter Row & Column \n");

        scanf("%d",&temp2);

        for(int a=1;a<RSCount2;a++)
        {
            if(temp2 == PB[a])
                bRepeatInputFlag = true;
        }

        if((temp2>88) || (temp2 == 0))
        {
            InputErrFlag2 = true;
            printf("Please choose the Correct Row & Column \n");
            ScanCount2 = ScanCount2+1;
        }
        else if(bRepeatInputFlag == true)
        {
            InputErrFlag2 = true;
            printf("Entered Row column is Repeated. Select different RC \n");
            ScanCount2 = ScanCount2+1;
        }
        else{
            InputErrFlag2 = false;
        }

        if(InputErrFlag2 == false)
        {
            PB[RSCount2] = temp2;

//--------------Calculate the selected block---------------------------
/***********Code for debugging**********/
 //           for(int i = 1;i<=RSCount2;i++)
 //           {
            PBR[RSCount2] = PB[RSCount2]/10;//Row//msb
            PBC[RSCount2] = PB[RSCount2]%10;//Column//lsb
            printf("\n PB : %d ",PB[RSCount2]);
            printf(" msb is %d & lsb is %d \n",PBR[RSCount2],PBC[RSCount2]);
//            }
            printf("\n");
/***************************************/
//--------------if input is right draw new block with no. around the block--------
            for(int b=1;b<9;b++)
                printf("C%d ",b);

            printf("\n");

            for(x=1;x<9;x++)
            {
                for(y=1;y<9;y++)
                {
                    if((x==R[1]==PBR[RSCount2]) && (y==C[1]==PBR[RSCount2]))
                    {
                        bGameOverFlag = true;
                        bSetMineFlag = true;
                    }
                    else if((x==R[2]==PBR[RSCount2]) && (y==C[2]==PBR[RSCount2]))
                    {
                        bGameOverFlag = true;
                        bSetMineFlag = true;
                    }
                    else if((x==R[3]==PBR[RSCount2]) && (y==C[3]==PBR[RSCount2]))
                    {
                        bGameOverFlag = true;
                        bSetMineFlag = true;
                    }
                    else if((x==R[4]==PBR[RSCount2]) && (y==C[4]==PBR[RSCount2]))
                    {
                        bGameOverFlag = true;
                        bSetMineFlag = true;
                    }
                    else if((x==R[5]==PBR[RSCount2]) && (y==C[5]==PBR[RSCount2]))
                    {
                        bGameOverFlag = true;
                        bSetMineFlag = true;
                    }
                    else
                        bSetMineFlag = false;

                    if(bSetMineFlag)
                    {
                        printf(" M ");
                    }
                    else if(!bSetMineFlag)
                    {
                        printf(" * ");

                    }
                }
                printf("R%d \n",x);
            }

            RSCount2 = RSCount2 + 1;// increase the index after every input

            if(bGameOverFlag)
            {
                printf("\n*Game Over* \n");
                ScanCount2 =0;
                break;
            }

            if(RSCount2 > 60)
                RSCount2 = RSCount2-1;

        }

    }


}

void vDrawGameBlock(void)
{
    for(int b=1;b<9;b++)
        printf("C%d ",b);

    printf("\n");

    for(int i=1;i<9;i++)//Row
    {
        for(int j=1;j<9;j++)//Column
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
