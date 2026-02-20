#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * РЕКУРСИВНО РАЗБИВАЕМ СТРОКУ НА ЭЛЕМЕНТАРНЫЕ "СПЕЦИАЛЬНЫЕ" ПОДСТРОКИ,
     * СОРТИРУЕМ ИХ И СОБИРАЕМ ОБРАТНО.
     */
    string makeLargestSpecial(string s) {
        if (s.empty()) return "";

        vector<string> substrings;
        int balance = 0;
        int start = 0;

        for (int i = 0; i < s.length(); ++i) {
            balance += (s[i] == '1' ? 1 : -1);
            
            // ЕСЛИ БАЛАНС НУЛЕВОЙ, МЫ НАШЛИ МИНИМАЛЬНУЮ СПЕЦИАЛЬНУЮ ПОДСТРОКУ
            if (balance == 0) {
                // ПОДСТРОКА ВНУТРИ ВНЕШНИХ '1' И '0' ТОЖЕ ДОЛЖНА БЫТЬ ОПТИМИЗИРОВАНА
                // МЫ УДАЛЯЕМ ПЕРВЫЙ '1' И ПОСЛЕДНИЙ '0', РЕКУРСИВНО ОБРАБАТЫВАЕМ ЦЕНТР
                substrings.push_back("1" + makeLargestSpecial(s.substr(start + 1, i - start - 1)) + "0");
                start = i + 1;
            }
        }

        // СОРТИРУЕМ ВСЕ НАЙДЕННЫЕ ПОДСТРОКИ В ОБРАТНОМ ПОРЯДКЕ (ПО УБЫВАНИЮ)
        sort(substrings.begin(), substrings.end(), greater<string>());

        // СКЛЕИВАЕМ РЕЗУЛЬТАТ
        string result = "";
        for (const string& sub : substrings) {
            result += sub;
        }
        
        return result;
    }
};