class Solution
{
public:
  int myAtoi(string s)
  {
    int index = 0;
    int n = s.size();

    while (index < n && s[index] == ' ')
    {
      index++;
    }

    int sign = 1;
    if (index < n && (s[index] == '-' || s[index] == '+'))
    {
      sign = (s[index] == '-') ? -1 : 1;
      index++;
    }

    long result = 0;
    while (index < n && isdigit(s[index]))
    {
      int digit = s[index] - '0';

      if (result > INT_MAX / 10 ||
          (result == INT_MAX / 10 && digit > INT_MAX % 10))
      {
        return (sign == 1) ? INT_MAX : INT_MIN;
      }

      result = result * 10 + digit;
      index++;
    }

    return sign * result;
  }
};
