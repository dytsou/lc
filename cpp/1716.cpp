class Solution {
public:
    int totalMoney(int n) {
       return getWholeWeekMoney(countWeek(n)) + getLeftDaysMoney(n, getLeftDays(n));
    }
private:
    int countWeek(int n){
        return n/7;
    }
    int getWholeWeekMoney(int weekCount){
        int result = 0;
        for(int i = 28, j = 0; j < weekCount; i+=7, j++){
            result += i;
        }
        return result;
    }
    int getLeftDays(int n){
        return n % 7;
    }
    int getLeftDaysMoney(int n, int leftDays){
        int result = 0;
        for(int i = 0; i < leftDays; i++){
            result += i + countWeek(n) + 1;
        }
       return result;
    }
};
