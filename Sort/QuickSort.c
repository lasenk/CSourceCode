#include <stdio.h>
#include <sys/time.h>

int main()
{
    int isortlist[] = {474,294,179,281,217,480,203,663,365,16,907,402,697,665,130,608,158,882,589,786};
    int len = sizeof(isortlist)/sizeof(int);
    int i;
    struct timeval tstarttime;
    struct timeval tendtime;

    gettimeofday(&tstarttime, NULL);
    
    printf("Before QuickSort:");
    for(i = 0;i < len;i++)
        printf("%d ",isortlist[i]);
    printf("\n");

    QuickSortFunc(isortlist,0,sizeof(isortlist)/sizeof(int) - 1);

    printf("After QuickSort:");
    for(i = 0;i < len;i++)
        printf("%d ",isortlist[i]);

    gettimeofday(&tendtime, NULL);
    printf("\nTime costs:%ldus\n",1000000 * (tendtime.tv_sec-tstarttime.tv_sec)+ tendtime.tv_usec-tstarttime.tv_usec);
}
/*
    QuickSortFunc 快速排序入口函数
    函数要点：
        1.由于该函数用于递归调用，函数传入起始位置必须是存在的位置（首次调用传入数组最大长度-1）；
        2.通过判定起始位置小于结束位置来终止函数树最后子节点的调用；
        3.只有比哨岗位大或小才会进行替换，增强函数的稳定性；
        4.标志位替换后会进行++或--，减少对比次数；
*/
int QuickSortFunc(int datalist[],int startloc,int endloc)
{
    int i = startloc, j = endloc, X = datalist[i];
    int s;
    if(startloc < endloc)
    {
        while(i < j)
        {
            while(i < j && datalist[j] > X)
                j--;
            if(i < j)
            {
                datalist[i] = datalist[j];
                i++;
            }

            while(i < j && datalist[i] < X)
                i++;
            if(i < j)
            {
                datalist[j] = datalist[i];
                j--;
            }
        }

        //如果开始位置只比结束位置小1，以下代码会将对应点的值再度覆盖，尚未找到合适的方式来减少步骤
        datalist[i] = X;
        QuickSortFunc(datalist, 0, i - 1);
        QuickSortFunc(datalist, i + 1, endloc);
    }
}