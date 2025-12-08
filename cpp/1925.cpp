class Solution {
public:
  int countTriples(int n) {
    int result = 0;
    for(int a = 2; a * a < n; a++){
      for(int b = 1; b < a; b++){
        if (__gcd(a, b) == 1 && (a - b) % 2 == 1) {
          int c = a * a + b * b;
          if (c > n) break;
          result += 2 * (n / c); 
        }
      }
    }
    return result;
  }
};