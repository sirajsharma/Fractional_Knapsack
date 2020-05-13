#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

double get_optimal_value(int capacity, vector<double> weights, vector<double> values, int n)
{
    double value = 0.0000;
    vector<double> single_item_value(n);

    for (size_t i = 0; i < n; i++)
    {
        if (capacity == 0)
        {
            return value;
        }
        single_item_value[i] = (values[i] / weights[i]);
    }

    if((n == 1) && (capacity >= weights[n - 1]))
    {
        value = values[n - 1];
        return value;
    }

    while (capacity > 0)
    {
        int index = max_element(single_item_value.begin(), single_item_value.end())  - single_item_value.begin();
        single_item_value[index] = 0;
        if (capacity >= weights[index])
        {
            value += values[index];
            capacity -= weights[index];
        } else
        {
            value = value + (capacity * (values[index] / weights[index]));
            capacity -= capacity;
        }
    }

    return value;
}

int main()
{
    int n;
    int capacity;
    cin >> n >> capacity;
    vector<double> values(n);
    vector<double> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i] >> weights[i];
    }

    double optimal_value = get_optimal_value(capacity, weights, values, n);

    cout << fixed << setprecision(4) << optimal_value << endl;
    return 0;
}
