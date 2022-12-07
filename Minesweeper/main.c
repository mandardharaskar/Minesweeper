#include<stdio.h>
const int max_x_y[64] = {0};

void vDrawGameBlock(void);
void vAddMine(void);
void vSelectGameBlock(void);


int main()
{
    int num = 1;
    printf("Hello World\n");
    vAddMine();
    vDrawGameBlock();
    vSelectGameBlock();

    return 0;
}

void vAddMine(void)
{


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



}
