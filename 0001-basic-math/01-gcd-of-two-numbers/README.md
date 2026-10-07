# GCD of Two Numbers

## Concept
The Greatest Common Divisor (GCD) is the largest positive integer that divides both numbers.

## Approach: Euclidean Algorithm

```text
GCD(a, b) = GCD(b, a % b)
```

Repeat until the second number becomes `0`. The first number is the GCD.

## Complexity
- Time: `O(log(min(a, b)))`
- Space: `O(1)`

## Key takeaway
Use remainders to reduce the problem instead of checking every possible divisor.
