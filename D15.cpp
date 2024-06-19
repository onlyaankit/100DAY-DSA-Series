#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> find_primes(int max_value)
{
    std::vector<bool> is_prime(max_value + 1, true);
    for (int current = 2; current * current <= max_value; ++current)
    {
        if (is_prime[current])
        {
            for (int multiple_of_prime = current * current; multiple_of_prime <= max_value; multiple_of_prime += current)
            {
                is_prime[multiple_of_prime] = false;
            }
        }
    }
    std::vector<int> prime_numbers;
    for (int current = 2; current <= max_value; ++current)
    {
        if (is_prime[current])
        {
            prime_numbers.push_back(current);
        }
    }
    return prime_numbers;
}

bool can_sum_to_target(int sum_target, const std::vector<int> &prime_numbers)
{
    std::vector<int> prime_squares;
    for (int prime : prime_numbers)
    {
        int square = prime * prime;
        if (square < sum_target)
        {
            prime_squares.push_back(square);
        }
    }
    int n = prime_squares.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            for (int k = j + 1; k < n; ++k)
            {
                if (prime_squares[i] + prime_squares[j] + prime_squares[k] == sum_target)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    int test_cases;
    std::cin >> test_cases;
    std::vector<int> test_numbers(test_cases);
    for (int i = 0; i < test_cases; ++i)
    {
        std::cin >> test_numbers[i];
    }

    std::vector<int> all_primes = find_primes(100000);
    std::vector<std::string> results;
    for (int number : test_numbers)
    {
        if (can_sum_to_target(number, all_primes))
        {
            results.push_back("Yes");
        }
        else
        {
            results.push_back("No");
        }
    }

    for (const std::string &result : results)
    {
        std::cout << result << std::endl;
    }

 return 0;
}