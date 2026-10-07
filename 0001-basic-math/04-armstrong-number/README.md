# Armstrong Number

## Problem Statement

Given a positive integer `n`, determine whether it is an **Armstrong number**.

An Armstrong number is a number where the sum of each digit raised to the power of the total number of digits is equal to the original number.

### Example 1

```text
Input: n = 153
Output: true
```

### Explanation

`153` has 3 digits:

```text
1³ + 5³ + 3³
= 1 + 125 + 27
= 153
```

Therefore, `153` is an Armstrong number.

### Example 2

```text
Input: n = 123
Output: false
```

```text
1³ + 2³ + 3³
= 1 + 8 + 27
= 36
```

Since `36 != 123`, `123` is not an Armstrong number.

## Approach

1. Store the original number.
2. Count the number of digits.
3. Extract each digit using `% 10`.
4. Raise each digit to the power of the number of digits.
5. Add the results.
6. Compare the sum with the original number.

## C++ Solution

```cpp
#include <cmath>

class Solution {
public:
    bool isArmstrong(int n) {
        int original = n;
        int digits = 0;
        int temp = n;

        while (temp != 0) {
            digits++;
            temp /= 10;
        }

        int sum = 0;
        temp = n;

        while (temp != 0) {
            int digit = temp % 10;
            sum += static_cast<int>(pow(digit, digits));
            temp /= 10;
        }

        return sum == original;
    }
};
```

## Key Concepts

- Modulo `% 10` extracts the last digit.
- Integer division `/ 10` removes the last digit.
- `pow(digit, digits)` calculates the required power.
- The final comparison determines whether the number is an Armstrong number.

## Complexity

- **Time:** `O(d)`, where `d` is the number of digits.
- **Space:** `O(1)`.

## Common Armstrong Numbers

```text
0, 1, 2, 3, 4, 5, 6, 7, 8, 9
153, 370, 371, 407
1634, 8208, 9474
```
