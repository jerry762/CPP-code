#include <iostream>
#include <chrono>
#include <vector>
#include <random>
#include <algorithm>
#include <iomanip>

#define SIZE 50'000

//* time complexity: O(n^2)
void bubble_sort(std::vector<int> &vec);

//* time complexity: O(n^2)
void selection_sort(std::vector<int> &vec);

//* time complexity: O(n^2)
void insertion_sort(std::vector<int> &vec);

//* time complexity: O(nlogn)
void merge_sort(std::vector<int> &vec, int left, int right);
void merge(std::vector<int> &vec, int left, int mid, int right);

//* time complexity: O(nlogn)
void quick_sort(std::vector<int> &vec, int left, int right);
int partition(std::vector<int> &vec, int left, int right, int pivot);

//* time complexity: O(nlogn)
void heap_sort(std::vector<int> &vec);
void heapify(std::vector<int> &vec, int size, int root);

std::random_device rd;
std::uniform_int_distribution<int> dist(1, 100);

int main()
{
    std::cout << "Running..." << std::endl;

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine gen(seed);
    std::uniform_int_distribution<int> dist(1, 1000000);

    std::chrono::time_point<std::chrono::steady_clock, std::chrono::duration<double>> start, end;
    std::chrono::duration<double> time_span_bubble, time_span_insert, time_span_select, time_span_merge, time_span_quick, time_span_heap;
    std::vector<int> vec_ori(SIZE);

    for (int &i : vec_ori)
        i = dist(gen);

    std::vector<int> vec_bubble(vec_ori), vec_select(vec_ori), vec_insert(vec_ori), vec_merge(vec_ori), vec_quick(vec_ori), vec_heap(vec_ori);

    //* bubble test

    start = std::chrono::steady_clock::now();

    bubble_sort(vec_bubble);

    end = std::chrono::steady_clock::now();

    time_span_bubble = end - start;

    //* select test

    start = std::chrono::steady_clock::now();

    selection_sort(vec_select);

    end = std::chrono::steady_clock::now();

    time_span_select = end - start;

    //* insert test

    start = std::chrono::steady_clock::now();

    insertion_sort(vec_insert);

    end = std::chrono::steady_clock::now();

    time_span_insert = end - start;

    //* merge test

    start = std::chrono::steady_clock::now();

    merge_sort(vec_merge, 0, vec_merge.size() - 1);

    end = std::chrono::steady_clock::now();

    time_span_merge = end - start;

    //* quick test

    start = std::chrono::steady_clock::now();

    quick_sort(vec_quick, 0, vec_quick.size() - 1);

    end = std::chrono::steady_clock::now();

    time_span_quick = end - start;

    //* heap test

    start = std::chrono::steady_clock::now();

    heap_sort(vec_heap);

    end = std::chrono::steady_clock::now();

    time_span_heap = end - start;

    std::cout << std::left << std::setw(15) << "Bubble_Sort: " << std::setw(10) << time_span_bubble.count() << "s" << std::endl;
    std::cout << std::left << std::setw(15) << "Select_Sort: " << std::setw(10) << time_span_select.count() << "s" << std::endl;
    std::cout << std::left << std::setw(15) << "Insert_Sort: " << std::setw(10) << time_span_insert.count() << "s" << std::endl;
    std::cout << std::left << std::setw(15) << "Merge_Sort: " << std::setw(10) << time_span_merge.count() << "s" << std::endl;
    std::cout << std::left << std::setw(15) << "Quick_Sort: " << std::setw(10) << time_span_quick.count() << "s" << std::endl;
    std::cout << std::left << std::setw(15) << "Heap_Sort: " << std::setw(10) << time_span_heap.count() << "s" << std::endl;
}

void bubble_sort(std::vector<int> &vec)
{
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
}

void selection_sort(std::vector<int> &vec)
{
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
}

void insertion_sort(std::vector<int> &vec)
{
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
}

void merge_sort(std::vector<int> &vec, int left, int right)
{
    if (left >= right)
        return;

    int mid = (left + right) / 2;

    merge_sort(vec, left, mid);      //* divide
    merge_sort(vec, mid + 1, right); //* divide
    merge(vec, left, mid, right);    //* combine
}

void merge(std::vector<int> &vec, int left, int mid, int right)
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

void quick_sort(std::vector<int> &vec, int left, int right)
{
    if (left >= right)
        return;

    dist.param(decltype(dist)::param_type(left, right));

    int pivot = partition(vec, left, right, dist(rd));

    quick_sort(vec, left, pivot - 1);
    quick_sort(vec, pivot + 1, right);
}

int partition(std::vector<int> &vec, int left, int right, int pivot)
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

void heap_sort(std::vector<int> &vec)
{
    //* build heap
    for (int i = vec.size() / 2 - 1; i >= 0; i--)
        heapify(vec, vec.size(), i);

    for (int i = vec.size() - 1; i > 0; i--)
    {
        std::swap(vec.at(0), vec.at(i));

        heapify(vec, i, 0);
    }
}

void heapify(std::vector<int> &vec, int size, int root)
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

        heapify(vec, size, max);
    }
}