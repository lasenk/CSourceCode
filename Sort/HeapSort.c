#include <stdio.h>
#include <sys/time.h>

int main(void)
{
    int isortlist[] = {474,294,179,281,217,480,203,663,365,16,907,402,697,665,130,608,158,882,589,786};
    int len = sizeof(isortlist)/sizeof(int);
    int i;
    struct timeval tstarttime;
    struct timeval tendtime;

    gettimeofday(&tstarttime, NULL);

    printf("Before HeapSort:");
    for(i = 0;i < len;i++)
        printf("%d ",isortlist[i]);
    printf("\n");

    HeapSort(isortlist,sizeof(isortlist)/sizeof(int));

    printf("After HeapSort:");
    for(i = 0;i < len;i++)
        printf("%d ",isortlist[i]);

    gettimeofday(&tendtime, NULL);
    printf("\nTime costs:%ldus\n",1000000 * (tendtime.tv_sec-tstarttime.tv_sec)+ tendtime.tv_usec-tstarttime.tv_usec);
}

/*
    HeapSort 堆排序函数入口
    函数要点：
        1.第一个循环构造初始堆，遍历所有非叶子节点找出最大的数放置至堆顶；
        2.将堆顶与堆尾进行交换，再找出当前能找出的最大元素；（反复执行本要点的两个步骤）
*/
int HeapSort(int datalist[], int ilistlen)
{
    int i = 0;
    int iswap = 0;

    for(i = ilistlen/2 -1; i >= 0; i--)
    {
        AdjustHeap(datalist, i, ilistlen);
    }

    for(i = ilistlen - 1; i >0; i--)
    {
        iswap = datalist[0];
        datalist[0] = datalist[i];
        datalist[i] = iswap;
        AdjustHeap(datalist, 0, i);
    }
}

int AdjustHeap(int datalist[], int iloc, int ilistlen)
{
    int i = 0;
    int itemp = datalist[iloc];
    for(i = iloc*2 + 1; i < ilistlen; i = i*2 + 1)
    {
        if(i + 1 < ilistlen && datalist[i] < datalist[i + 1])
            i++;
        if(datalist[i] > itemp)
        {
            datalist[iloc] = datalist[i];
            iloc = i;
        }
        else
            break;
    }
    datalist[iloc] = itemp;
}