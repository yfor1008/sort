// sort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

// 交换算法
// iDataA: input/output, 数据A
// iDataB: input/output, 数据B
void swap(int& iDataA, int& iDataB)
{
    int tmp;
    tmp = iDataA;
    iDataA = iDataB;
    iDataB = tmp;
}

// 插入排序: 一维排序, 时间复杂度O(n^2), 空间复杂度O(1), 稳定
// iDataArr: input/output, 数据数组
// iDataSize: input, 数据长度
// bOrder: input, 排序顺序, 0-从高到低(升序), 1-从低到高(降序)
void InsertSort1D(int *iDataArr, int iDataSize, bool bOrder=1)
{
    int i = 0, j = 0;
    int tmp = 0;
    for (i = 1; i < iDataSize; i++) // 默认第0张有序，因而从第1张开始
    {
        tmp = iDataArr[i];
        j = i;
        if (bOrder) // 升序
        {
            while (j > 0 && iDataArr[j - 1] > tmp) // 前面比当前位置大，互换
            {
                iDataArr[j] = iDataArr[j - 1];
                j--;
            }
            iDataArr[j] = tmp;
        }
        else // 降序
        {
            while (j > 0 && iDataArr[j - 1] < tmp) // 前面比当前位置小，互换
            {
                iDataArr[j] = iDataArr[j - 1];
                j--;
            }
            iDataArr[j] = tmp;
        }
    }
}

// 选择排序: 一维排序, 时间复杂度O(n^2), 空间复杂度O(1), 不稳定
// iDataArr: input/output, 数据数组
// iDataSize: input, 数据长度
// bOrder: input, 排序顺序, 0-从高到低(升序), 1-从低到高(降序)
void SelectSort1D(int* iDataArr, int iDataSize, bool bOrder=1)
{
    int i = 0, j = 0;
    int k = 0;
    for (i = 0; i < iDataSize; i++)
    {
        k = i;
        for (j = i + 1; j < iDataSize; j++)
        {
            if (bOrder) // 升序
            {
                if (iDataArr[k] > iDataArr[j])
                {
                    k = j;
                }
            }
            else // 降序
            {
                if (iDataArr[k] < iDataArr[j])
                {
                    k = j;
                }
            }
        }
        if (k != i)
        {
            swap(iDataArr[k], iDataArr[i]);
        }
    }
}

// 冒泡排序: 一维排序, 时间复杂度O(n^2), 空间复杂度O(1), 稳定
// iDataArr: input/output, 数据数组
// iDataSize: input, 数据长度
// bOrder: input, 排序顺序, 0-从高到低(升序), 1-从低到高(降序)
void BubbleSort1D(int* iDataArr, int iDataSize, bool bOrder = 1)
{
    int i = 0, j = 0;
    for (i = 0; i < iDataSize; i++)
    {
        for (j = 0; j < iDataSize - i - 1; j++)
        {
            if (bOrder) // 升序
            {
                if (iDataArr[j] > iDataArr[j + 1])
                {
                    swap(iDataArr[j], iDataArr[j + 1]);
                }
            }
            else // 降序
            {
                if (iDataArr[j] < iDataArr[j + 1])
                {
                    swap(iDataArr[j], iDataArr[j + 1]);
                }
            }
        }
    }
}

// 
int Paritition1(int* iDataArr, int iLeft, int iRight, bool bOrder = 1)
{
    int pivot = iDataArr[iLeft];
    while (iLeft < iRight)
    {
        if (bOrder) // 升序
        {
            while (iLeft < iRight && iDataArr[iRight] >= pivot)
            {
                iRight--;
            }
            if (iRight > iLeft)
            {
                iDataArr[iLeft] = iDataArr[iRight];
            }
            while (iLeft < iRight && iDataArr[iLeft] <= pivot)
            {
                iLeft++;
            }
            if (iLeft < iRight)
            {
                iDataArr[iRight] = iDataArr[iLeft];
            }
        }
        else // 降序
        {
            while (iLeft < iRight && iDataArr[iRight] <= pivot)
            {
                iRight--;
            }
            if (iRight > iLeft)
            {
                iDataArr[iLeft] = iDataArr[iRight];
            }
            while (iLeft < iRight && iDataArr[iLeft] >= pivot)
            {
                iLeft++;
            }
            if (iLeft < iRight)
            {
                iDataArr[iRight] = iDataArr[iLeft];
            }
        }
    }
    iDataArr[iLeft] = pivot;
    return iLeft;
}

// 快速排序: 一维排序, 时间复杂度O(nlogn), 空间复杂度O(logn), 不稳定
// iDataArr: input/output, 数据数组
// iLeft: input, 数组最左边的index, 从0开始
// iRight: input, 数组最右边的index, 数组长度-1
// bOrder: input, 排序顺序, 0-从高到低(升序), 1-从低到高(降序)
void QuickSort1D(int* iDataArr, int iLeft, int iRight, bool bOrder = 1)
{
    if (iLeft < iRight)
    {
        int pivot = Paritition1(iDataArr, iLeft, iRight, bOrder);
        QuickSort1D(iDataArr, iLeft, pivot - 1, bOrder);
        QuickSort1D(iDataArr, pivot + 1, iRight, bOrder);
    }
}

int main()
{
    int test_data[] = { 3,6,1,9,4,2,0,5,8,7,10 };
    int test_size = sizeof(test_data) / sizeof(test_data[0]);
    for (int i = 0; i< test_size; i++)
    {
        printf("%d", test_data[i]);
    }
    printf("\n");
    //BubbleSort1D(test_data, test_size, 0);
    QuickSort1D(test_data, 0, test_size-1, 1);
    for (int i = 0; i < test_size; i++)
    {
        printf("%d", test_data[i]);
    }
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
