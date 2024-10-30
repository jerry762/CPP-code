#include <iostream>
#include <chrono>
#include <vector>
#include <random>
#include <algorithm>
#include <iomanip>
#include <future>
#include <mutex>

#define SIZE 50'000

std::mutex m;
static int numberNo = 0;

std::random_device rd;
std::uniform_int_distribution<int> dist;

#pragma region Sort algorithm

//* time complexity: O(n^2)
void BubbleSort(std::vector<int> vec);

//* time complexity: O(n^2)
void SelectionSort(std::vector<int> vec);

//* time complexity: O(n^2)
void InsertionSort(std::vector<int> vec);

//* time complexity: O(nlogn)
void MergeSort(std::vector<int> vec);
void MergeSort_Divide(std::vector<int> &vec, int left, int right);
void MergeSort_Conquer(std::vector<int> &vec, int left, int mid, int right);

//* time complexity: O(nlogn)
void QuickSort(std::vector<int> vec);
void QuickSort_Divide(std::vector<int> &vec, int left, int right);
int QuickSort_Partition(std::vector<int> &vec, int left, int right, int pivot);

//* time complexity: O(nlogn)
void HeapSort(std::vector<int> vec);
void HeapSort_Heapify(std::vector<int> &vec, int size, int root);
#pragma endregion

void PrintTimeAndOrder(std::string algo, std::chrono::duration<double> time_span);

int main()
{
    std::cout << "Running..." << std::endl;

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    std::default_random_engine gen(seed);
    std::uniform_int_distribution<int> dist(1, 1000000);

    std::vector<int> vec(SIZE);

    for (int &i : vec)
        i = dist(gen);

    std::future<void> bubble = std::async(std::launch::async, BubbleSort, vec);
    std::future<void> select = std::async(std::launch::async, SelectionSort, vec);
    std::future<void> insert = std::async(std::launch::async, InsertionSort, vec);
    std::future<void> merge = std::async(std::launch::async, MergeSort, vec);
    std::future<void> quick = std::async(std::launch::async, QuickSort, vec);
    std::future<void> heap = std::async(std::launch::async, HeapSort, vec);
}

void BubbleSort(std::vector<int> vec)
{
    std::chrono::time_point<std::chrono::steady_clock, std::chrono::duration<double>> start, end;
    std::chrono::duration<double> time_span;

    start = std::chrono::steady_clock::now();
    for (size_t i = 0; i < vec.size() - 1; i++)
    {
        bool change = false;

        for (size_t j = 0; j < vec.size() - i - 1; j++)
        {
            if (vec.at(j) > vec.at(j + 1))
            {
                std::swap(vec.at(j), vec.at(j + 1));
                change = true;
            }
        }
        if (!change)
            break;
    }
    end = std::chrono::steady_clock::now();

    time_span = end - start;
    PrintTimeAndOrder("Bubble_Sort: ", time_span);
}

void SelectionSort(std::vector<int> vec)
{
    std::chrono::time_point<std::chrono::steady_clock, std::chrono::duration<double>> start, end;
    std::chrono::duration<double> time_span;

    start = std::chrono::steady_clock::now();
    for (size_t i = 0; i < vec.size() - 1; i++)
    {
        size_t index = i;

        for (size_t j = i + 1; j < vec.size(); j++)
        {
            if (vec.at(index) > vec.at(j))
                index = j;
        }
        std::swap(vec.at(i), vec.at(index));
    }
    end = std::chrono::steady_clock::now();

    time_span = end - start;
    PrintTimeAndOrder("Select_Sort: ", time_span);
}

void InsertionSort(std::vector<int> vec)
{
    std::chrono::time_point<std::chrono::steady_clock, std::chrono::duration<double>> start, end;
    std::chrono::duration<double> time_span;

    start = std::chrono::steady_clock::now();
    for (size_t i = 1; i < vec.size(); i++)
    {
        int key = vec.at(i);
        int j = i - 1;

        while (j >= 0 && vec.at(j) > key)
        {
            vec.at(j + 1) = vec.at(j);
            j--;
        }
        vec.at(j + 1) = key;
    }
    end = std::chrono::steady_clock::now();

    time_span = end - start;
    PrintTimeAndOrder("Insert_Sort: ", time_span);
}

void MergeSort(std::vector<int> vec)
{
    std::chrono::time_point<std::chrono::steady_clock, std::chrono::duration<double>> start, end;
    std::chrono::duration<double> time_span;

    start = std::chrono::steady_clock::now();
    MergeSort_Divide(vec, 0, vec.size() - 1);
    end = std::chrono::steady_clock::now();

    time_span = end - start;
    PrintTimeAndOrder("Merge_Sort: ", time_span);
}

void MergeSort_Divide(std::vector<int> &vec, int left, int right)
{
    if (left >= right)
        return;

    int mid = (left + right) / 2;

    MergeSort_Divide(vec, left, mid);
    MergeSort_Divide(vec, mid + 1, right);
    MergeSort_Conquer(vec, left, mid, right);
}

void MergeSort_Conquer(std::vector<int> &vec, int left, int mid, int right)
{
    std::vector<int> leftSubArr(vec.begin() + left, vec.begin() + mid + 1);
    std::vector<int> rightSubArr(vec.begin() + mid + 1, vec.begin() + right + 1);

    leftSubArr.push_back(std::numeric_limits<int>::max());
    rightSubArr.push_back(std::numeric_limits<int>::max());

    int leftIndex = 0;
    int rightIndex = 0;

    for (size_t i = left; i <= right; i++)
    {
        if (leftSubArr.at(leftIndex) > rightSubArr.at(rightIndex))
        {
            vec.at(i) = rightSubArr.at(rightIndex);
            rightIndex++;
        }
        else
        {
            vec.at(i) = leftSubArr.at(leftIndex);
            leftIndex++;
        }
    }
}

void QuickSort(std::vector<int> vec)
{
    std::chrono::time_point<std::chrono::steady_clock, std::chrono::duration<double>> start, end;
    std::chrono::duration<double> time_span;

    start = std::chrono::steady_clock::now();
    QuickSort_Divide(vec, 0, vec.size() - 1);
    end = std::chrono::steady_clock::now();

    time_span = end - start;
    PrintTimeAndOrder("Quick_Sort: ", time_span);
}

void QuickSort_Divide(std::vector<int> &vec, int left, int right)
{
    if (left >= right)
        return;

    dist.param(decltype(dist)::param_type(left, right));

    int pivot = QuickSort_Partition(vec, left, right, dist(rd));

    QuickSort_Divide(vec, left, pivot - 1);
    QuickSort_Divide(vec, pivot + 1, right);
}

int QuickSort_Partition(std::vector<int> &vec, int left, int right, int pivot)
{
    int value = vec.at(pivot);
    int storeIndex = left;

    std::swap(vec.at(pivot), vec.at(right));

    for (size_t i = left; i < right; i++)
    {
        if (vec.at(i) < value)
        {
            std::swap(vec.at(i), vec.at(storeIndex));
            storeIndex++;
        }
    }

    std::swap(vec.at(storeIndex), vec.at(right));

    return storeIndex;
}

void HeapSort(std::vector<int> vec)
{
    std::chrono::time_point<std::chrono::steady_clock, std::chrono::duration<double>> start, end;
    std::chrono::duration<double> time_span;

    start = std::chrono::steady_clock::now();
    for (int i = vec.size() / 2 - 1; i >= 0; i--) //* build heap
        HeapSort_Heapify(vec, vec.size(), i);

    for (int i = vec.size() - 1; i > 0; i--)
    {
        std::swap(vec.at(0), vec.at(i));
        HeapSort_Heapify(vec, i, 0);
    }
    end = std::chrono::steady_clock::now();

    time_span = end - start;
    PrintTimeAndOrder("Heap_Sort: ", time_span);
}

void HeapSort_Heapify(std::vector<int> &vec, int size, int root)
{
    int max = root;
    int l = 2 * root + 1;
    int r = 2 * root + 2;

    if (l < size && vec.at(l) > vec.at(max))
        max = l;

    if (r < size && vec[r] > vec[max])
        max = r;

    if (max != root)
    {
        std::swap(vec.at(root), vec.at(max));
        HeapSort_Heapify(vec, size, max);
    }
}

void PrintTimeAndOrder(std::string algo, std::chrono::duration<double> time_span)
{
    std::lock_guard<std::mutex> lk(m);

    std::cout << std::left << std::setw(15) << algo
              << std::setw(10) << time_span.count() << "s <- " << ++numberNo << std::endl;
}