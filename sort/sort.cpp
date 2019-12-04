// sort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

// 交换算法
// iDataA: input/output, 数据A
// iDataB: input/output, 数据B
template <typename T>
void swap(T& iDataA, T& iDataB)
{
    T tmp;
    tmp = iDataA;
    iDataA = iDataB;
    iDataB = tmp;
}

// 插入排序: 一维排序, 时间复杂度O(n^2), 空间复杂度O(1), 稳定
// iDataArr: input/output, 数据数组
// iDataSize: input, 数据长度
// bOrder: input, 排序顺序, 0-从高到低(升序), 1-从低到高(降序)
template <typename T>
void InsertSort1D(T *iDataArr, int iDataSize, bool bOrder=1)
{
    int i = 0, j = 0;
    T tmp = 0;
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
template <typename T>
void InsertSort1D(std::vector<T> &iDataArr, int iDataSize, bool bOrder = 1)
{
    int i = 0, j = 0;
    T tmp = 0;
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
template <typename T>
void SelectSort1D(T* iDataArr, int iDataSize, bool bOrder=1)
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
template <typename T>
void SelectSort1D(std::vector<T> &iDataArr, int iDataSize, bool bOrder = 1)
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
template <typename T>
void BubbleSort1D(T* iDataArr, int iDataSize, bool bOrder = 1)
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
template <typename T>
void BubbleSort1D(std::vector<T> &iDataArr, int iDataSize, bool bOrder = 1)
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
template <typename T>
int Paritition1(T* iDataArr, int iLeft, int iRight, bool bOrder = 1)
{
    T pivot = iDataArr[iLeft];
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
template <typename T>
int Paritition1(std::vector<T> &iDataArr, int iLeft, int iRight, bool bOrder = 1)
{
    T pivot = iDataArr[iLeft];
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
template <typename T>
void QuickSort1D(T* iDataArr, int iLeft, int iRight, bool bOrder = 1)
{
    if (iLeft < iRight)
    {
        T pivot = Paritition1(iDataArr, iLeft, iRight, bOrder);
        QuickSort1D(iDataArr, iLeft, pivot - 1, bOrder);
        QuickSort1D(iDataArr, pivot + 1, iRight, bOrder);
    }
}
template <typename T>
void QuickSort1D(std::vector<T> &iDataArr, int iLeft, int iRight, bool bOrder = 1)
{
    if (iLeft < iRight)
    {
        T pivot = Paritition1(iDataArr, iLeft, iRight, bOrder);
        QuickSort1D(iDataArr, iLeft, pivot - 1, bOrder);
        QuickSort1D(iDataArr, pivot + 1, iRight, bOrder);
    }
}

// 合并
template <typename T>
void merge(T* src, T* dst, int begin, int mid, int end, bool bOrder = 1)
{
    int begin1 = begin;
    int begin2 = mid;
    int index = begin;
    while (begin1 < mid && begin2 < end)
    {
        if (bOrder) // 升序
        {
            if (src[begin1] < src[begin2])
            {
                dst[index++] = src[begin1++];
            }
            else
            {
                dst[index++] = src[begin2++];
            }
        }
        else // 降序
        {
            if (src[begin1] > src[begin2])
            {
                dst[index++] = src[begin1++];
            }
            else
            {
                dst[index++] = src[begin2++];
            }
        }
    }
    while (begin1 < mid)
    {
        dst[index++] = src[begin1++];
    }
    while (begin2 < end)
    {
        dst[index++] = src[begin2++];
    }
    memcpy(src + begin, dst + begin, (end - begin) * sizeof(T));
}
template <typename T>
void _merge_sort(T* arr, T* tmp, int left, int right, bool bOrder = 1)
{
    if (left + 1 >= right)
    {
        return;
    }
    int mid = left + (right - left) / 2;
    _merge_sort(arr, tmp, left, mid, bOrder);
    _merge_sort(arr, tmp, mid, right, bOrder);
    merge(arr, tmp, left, mid, right, bOrder);
}
// 归并排序, 时间复杂度O(nlogn), 空间复杂度O(n), 稳定
// iDataArr: input/output, 数据数组
// iDataSize: input, 数据长度
// bOrder: input, 排序顺序, 0-从高到低(升序), 1-从低到高(降序)
template <typename T>
void MergeSort1D(T* arr, int size, bool bOrder = 1)
{
    T* tmp = (T*)malloc(size * sizeof(T));
    _merge_sort(arr, tmp, 0, size, bOrder);
    free(tmp);
}
// 合并
template <typename T>
void merge(std::vector<T> &src, std::vector<T> &dst, int begin, int mid, int end, bool bOrder = 1)
{
    int begin1 = begin;
    int begin2 = mid;
    int index = begin;
    while (begin1 < mid && begin2 < end)
    {
        if (bOrder) // 升序
        {
            if (src[begin1] < src[begin2])
            {
                dst[index++] = src[begin1++];
            }
            else
            {
                dst[index++] = src[begin2++];
            }
        }
        else // 降序
        {
            if (src[begin1] > src[begin2])
            {
                dst[index++] = src[begin1++];
            }
            else
            {
                dst[index++] = src[begin2++];
            }
        }
    }
    while (begin1 < mid)
    {
        dst[index++] = src[begin1++];
    }
    while (begin2 < end)
    {
        dst[index++] = src[begin2++];
    }
    std::copy(dst.begin() + begin, dst.begin() + end, src.begin() + begin);
}
template <typename T>
void _merge_sort(std::vector<T> &arr, std::vector<T> &tmp, int left, int right, bool bOrder = 1)
{
    if (left + 1 >= right)
    {
        return;
    }
    int mid = left + (right - left) / 2;
    _merge_sort(arr, tmp, left, mid, bOrder);
    _merge_sort(arr, tmp, mid, right, bOrder);
    merge(arr, tmp, left, mid, right, bOrder);
}
// 归并排序, 时间复杂度O(nlogn), 空间复杂度O(n), 稳定
// iDataArr: input/output, 数据数组
// iDataSize: input, 数据长度
// bOrder: input, 排序顺序, 0-从高到低(升序), 1-从低到高(降序)
template <typename T>
void MergeSort1D(std::vector<T> &arr, int size, bool bOrder = 1)
{
    std::vector<T> tmp(size);
    _merge_sort(arr, tmp, 0, size, bOrder);
}

int test1()
{
    int test_data[] = { 3,6,1,9,4,2,0,5,8,7,10 };
    int test_size = sizeof(test_data) / sizeof(test_data[0]);
    for (int i = 0; i < test_size; i++)
    {
        printf("%d, ", test_data[i]);
    }
    printf("\n");
    MergeSort1D(test_data, test_size, 0);
    //BubbleSort1D(test_data, test_size, 0);
    //QuickSort1D(test_data, 0, test_size-1, 1);
    for (int i = 0; i < test_size; i++)
    {
        printf("%d, ", test_data[i]);
    }
    printf("\n");
    printf("test1 down!\n");
    return 0;
}

int test2()
{
    std::vector<uint16_t> test_data = { 3,6,1,9,4,2,0,5,8,7,10,20,15,19,16,18 };
    int test_size = test_data.size();
    for (int i = 0; i < test_size; i++)
    {
        printf("%d, ", test_data[i]);
    }
    printf("\n");
    MergeSort1D(test_data, test_size, 0);
    //BubbleSort1D(test_data, test_size, 0);
    //QuickSort1D(test_data, 0, test_size-1, 1);
    for (int i = 0; i < test_size; i++)
    {
        printf("%d, ", test_data[i]);
    }
    printf("\n");
    printf("test2 down!\n");
    return 0;
}

int main()
{
    test1();
    test2();
}
