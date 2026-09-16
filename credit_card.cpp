#include <iostream>
#include <string>

// Function prototypes
bool isValid(long long number);
int sumOfDoubleEvenPlace(long long number);
int getDigit(int number);
int sumOfOddPlace(long long number);
bool prefixMatched(long long number, int d);
int getSize(long long d);
long long getPrefix(long long number, int k);

int main() {
    long long cardNumber;
    std::cout << "Enter a credit card number as a long integer: ";
    std::cin >> cardNumber;

    if (isValid(cardNumber)) {
        std::cout << cardNumber << " is valid" << std::endl;
    } else {
        std::cout << cardNumber << " is invalid" << std::endl;
    }

    return 0;
}

// Return true if the card number is valid
bool isValid(long long number) {
    int size = getSize(number);

    // Check size requirement (between 13 and 16 digits)
    if (size < 13 || size > 16) {
        return false;
    }

    // Check valid prefixes (4 for Visa, 5 for MasterCard, 37 for Amex, 6 for Discover)
    if (!prefixMatched(number, 4) && 
        !prefixMatched(number, 5) && 
        !prefixMatched(number, 37) && 
        !prefixMatched(number, 6)) {
        return false;
    }

    // Luhn algorithm check (Mod 10 check)
    int totalSum = sumOfDoubleEvenPlace(number) + sumOfOddPlace(number);
    return (totalSum % 10 == 0);
}

// Get the result from Step 2 (doubling every second digit from right to left)
int sumOfDoubleEvenPlace(long long number) {
    int sum = 0;
    number /= 10; // Start from the second digit from the right

    while (number > 0) {
        int digit = (number % 10) * 2;
        sum += getDigit(digit);
        number /= 100; // Move to the next even-place digit
    }

    return sum;
}

// Return this number if it is a single digit, otherwise return the sum of the two digits
int getDigit(int number) {
    if (number < 10) {
        return number;
    }
    return (number / 10) + (number % 10);
}

// Return sum of odd place digits in number
int sumOfOddPlace(long long number) {
    int sum = 0;

    while (number > 0) {
        sum += number % 10;
        number /= 100; // Move to the next odd-place digit
    }

    return sum;
}

// Return true if the digit d is a prefix for number
bool prefixMatched(long long number, int d) {
    int dSize = getSize(d);
    return getPrefix(number, dSize) == d;
}

// Return the number of digits in d
int getSize(long long d) {
    int count = 0;
    while (d > 0) {
        d /= 10;
        count++;
    }
    return count;
}

// Return the first k number of digits from number. 
// If the number of digits in number is less than k, return number.
long long getPrefix(long long number, int k) {
    int size = getSize(number);
    if (size < k) {
        return number;
    }

    for (int i = 0; i < size - k; i++) {
        number /= 10;
    }

    return number;
}