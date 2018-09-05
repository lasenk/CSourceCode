#include <stdio.h>
#include <sys/time.h>

int main(void)
{
    int isortlist[] = {474,294,179,281,217,480,203,663,365,16,907,402,697,665,130,608,158,882,589,786};
    int templist[sizeof(isortlist)/sizeof(int)];
    int len = sizeof(isortlist)/sizeof(int);
    int i;
    struct timeval tstarttime;
    struct timeval tendtime;

    gettimeofday(&tstarttime, NULL);

    printf("Before MergeSort:");
    for(i = 0;i < len;i++)
        printf("%d ",isortlist[i]);
    printf("\n");

    MergeSort(isortlist, 0, sizeof(isortlist)/sizeof(int) - 1, templist);

    printf("After MergeSort:");
    for(i = 0;i < len;i++)
        printf("%d ",isortlist[i]);

    gettimeofday(&tendtime, NULL);
    printf("\nTime costs:%ldus\n",1000000 * (tendtime.tv_sec-tstarttime.tv_sec)+ tendtime.tv_usec-tstarttime.tv_usec);
}

/*
    MergeSort归并排序函数入口
    函数要点：
        1.归并排序以深度2作为最低深度开始进行排序，排序完以后再以上一层（*2）进行排序，依次类推直到排序完成；
*/
int MergeSort(int datalist[], int ileft, int iright, int templist[])
{
    int imid = 0;
    if(ileft < iright)
    {
        imid = (ileft + iright)/2;
        MergeSort(datalist, ileft, imid, templist);
        MergeSort(datalist, imid + 1, iright, templist);
        AdjustMerge(datalist, ileft, imid, iright, templist);
    }
}

int AdjustMerge(int datalist[], int ileft, int imid, int iright, int templist[])
{
    int i = ileft;
    int j = imid + 1;
    int t = 0;
    while(i <= imid && j <= iright)
    {
        if(datalist[i] <= datalist[j])
            templist[t++] = datalist[i++];
        else
            templist[t++] = datalist[j++];
    }

    while(i <= imid)
        templist[t++] = datalist[i++];

    while(j <= iright)
        templist[t++] = datalist[j++];
    
    t = 0;
    while(ileft <= iright)
        datalist[ileft++] = templist[t++];
}