#include "Source.h"

int main(void)
{

    int choice;

    cout << "[?] => Calculate the greatest common factor or the least common multiple:" << endl
        << "[i] => Enter `1` for greatest common factor." << endl
        << "[i] => Enter `2` for least common multiple." << endl
        << "> Enter choice: ";

    cin >> choice;
    cout << endl;

    switch (choice)
    {
    case 1:
        cout << "[!] => Calculation Started [GCF]" << endl;
        gcf();
        break;

    case 2:
        cout << "[!] => Calculation Started [LCM]" << endl;
        lcm();
        break;

    default:
        cout << "[!] => Invalid option." << endl;
        break;
    }
}

int prime_size = 0;

void gcf(void)
{
    int* primes;
    int prime_denominators[10000] = { 0 };

    int j = 0;
    int gcf = 1;
    int gcf1 = 0;
    int gcf2 = 0;
    int print_once = 0;

    cout << "> Enter the first number: ";
    cin >> gcf1;

    cout << "> Enter the second number: ";
    cin >> gcf2;

    int gcf1_start = gcf1;
    int gcf2_start = gcf2;

    primes = calculatePrime(gcf1, gcf2);

    for (int i = 0; i <= prime_size; i++)
    {
        while (gcf1 % primes[i] == 0 && gcf2 % primes[i] == 0)
        {
            gcf1 = gcf1 / primes[i];
            gcf2 = gcf2 / primes[i];

            prime_denominators[j] = primes[i];

            if (print_once == 0 && prime_denominators[j] != 0)
            {
                cout << endl
                    << "[i] => "
                    << "Number 1 "
                    << "Number 2 "
                    << "Prime-Denominator" << endl;

                print_once++;
            }

            cout << "[i] => " << gcf1 << "\t" << gcf2 << "\t " << prime_denominators[j] << endl;

            j++;
        }

        if (gcf1 == 1 || gcf2 == 1)
        {
            break;
        }
    }

    for (int i = 0; i < 10000; i++)
    {
        if (prime_denominators[i] != 0)
        {
            gcf = gcf * prime_denominators[i];
        }
    }

    cout << endl
        << "[OK] => The greatest common factor of " << gcf1_start << " and " << gcf2_start << " is: " << gcf << endl;
}

void lcm(void)
{
    int* primes;
    int prime_denominators[10000] = { 0 };

    int j = 0;
    int lcm = 1;
    int lcm1 = 0;
    int lcm2 = 0;
    int print_once = 0;

    cout << "> Enter the first number: ";
    cin >> lcm1;

    cout << "> Enter the second number: ";
    cin >> lcm2;

    int lcm1_start = lcm1;
    int lcm2_start = lcm2;

    primes = calculatePrime(lcm1, lcm2);

    for (int i = 0; i <= prime_size; i++)
    {
        while (lcm1 % primes[i] == 0 || lcm2 % primes[i] == 0)
        {
            if (lcm1 % primes[i] == 0)
            {
                lcm1 = lcm1 / primes[i];
            }
            if (lcm2 % primes[i] == 0)
            {
                lcm2 = lcm2 / primes[i];
            }

            prime_denominators[j] = primes[i];

            if (print_once == 0 && prime_denominators[j] != 0)
            {
                cout << endl
                    << "[i] => "
                    << "Number 1 "
                    << "Number 2 "
                    << "Prime-Denominator" << endl;

                print_once++;
            }

            cout << "[i] => " << lcm1 << "\t" << lcm2 << "\t " << prime_denominators[j] << endl;

            j++;
        }

        if (lcm1 == 1 && lcm2 == 1)
        {
            break;
        }
    }

    for (int i = 0; i < 10000; i++)
    {
        if (prime_denominators[i] != 0)
        {
            lcm = lcm * prime_denominators[i];
        }
    }

    cout << endl
        << "[OK] => The least common factor of " << lcm1_start << " and " << lcm2_start << " is: " << lcm << endl;
}

int* calculatePrime(int num1, int num2)
{

    int num, j, k = 0;
    int* primes = NULL;

    (num1 >= num2) ? (num = num1) : (num = num2);

    for (int i = 2; i <= num; i++)
    {
        for (j = 2; j <= i; j++)
        {
            if (i % j == 0)
            {
                break;
            }
        }

        if (i == j)
        {
            prime_size++;
        }
    }

    primes = new int(prime_size);
    for (int i = 2; i <= num; i++)
    {
        for (j = 2; j <= i; j++)
        {
            if (i % j == 0)
            {
                break;
            }
        }

        if (i == j)
        {
            primes[k] = i;
            k++;
        }
    }

    return primes;
}