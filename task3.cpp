/*(Quick sort является одним из самых быстрых и универсальных алгоритмов сортировки, 
который в большинтсве случаев, а также в случаях наиболее часто встречающихся на практике, 
показывает лучший результат по скорости в сравнение с остальными алгоритмами)*/

void quickSort(int *arr, int size)
{
    int i = 0;
    int j = size - 1;
    int mid = arr[size / 2];

    do {
        while(arr[i] < mid)
        {
            i++;
        }
        while(arr[j] > mid)
        {
            j--;
        }

        if (i <= j)
        {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);

    if(j > 0) {

        quickSort(arr, j + 1);
    }
    if (i < size) {

        quickSort(&arr[i], size - i);
    }
}
