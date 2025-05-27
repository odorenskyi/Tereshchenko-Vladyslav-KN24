#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <bitset>
#include <cmath>

// Функція для обчислення (можна змінити за потреби)
double s_calculation(double x, double y, double z) {
    double denominator = y - z;
    if (denominator == 0 || (x + denominator) < 0) {
        return std::nan(""); // повертаємо NaN при помилці
    }
    return std::sqrt(x + denominator);
}

// Завдання 10.1
void task_10_1(const std::string& input_filename, const std::string& output_filename) {
    std::ofstream outfile(output_filename);
    if (!outfile.is_open()) {
        std::cerr << "Помилка: Не вдалося відкрити вихідний файл '" << output_filename << "' для запису." << std::endl;
        return;
    }

    // 1. Авторська інформація
    outfile << "  Авторська інформація:\n";
    outfile << "  Ім'я та прізвище: Влад Терещенко\n";
    outfile << "  Установа/організація: ЦНТУ\n";
    outfile << "  Місто: Кропивницький\n";
    outfile << "  Країна: Україна\n";
    outfile << "  Рік розробки: 2025\n\n";

    // 2. Випадкове число
    std::srand(std::time(nullptr));
    int random_number = std::rand() % (100 - 10 + 1) + 10;
    outfile << "Випадкове число (від 10 до 100): " << random_number << "\n\n";

    // 3. Перевірка вірша
    const std::vector<std::string> original_poem_lines = {
        "Як парость виноградної лози, плекайте мову.",
        "Пильно й ненастанно політь бур'ян.",
        "Чистіша від сльози вона хай буде.",
        "Вірно і слухняно нехай вона щоразу служить вам,",
        "Хоч і живе своїм живим життям."
    };

    std::ifstream infile(input_filename);
    std::vector<std::string> input_poem_lines;
    std::string current_line;
    bool file_read_error = false;

    if (infile.is_open()) {
        while (std::getline(infile, current_line)) {
            input_poem_lines.push_back(current_line);
        }
        infile.close();
        if (!input_poem_lines.empty() && input_poem_lines.back().empty()) {
            input_poem_lines.pop_back();
        }
    } else {
        std::cerr << "Помилка: Не вдалося відкрити вхідний файл '" << input_filename << "' для читання." << std::endl;
        file_read_error = true;
    }

    outfile << "Повідомлення про пунктуацію:\n";
    if (file_read_error) {
        outfile << "  Не вдалося прочитати вхідний файл для перевірки пунктуації.\n";
    } else if (input_poem_lines == original_poem_lines) {
        outfile << "  Текст віршу із вхідного файла НЕ має пунктуаційних помилок (відповідно до авторського оригіналу).\n";
    } else {
        outfile << "  Текст віршу із вхідного файла МАЄ пунктуаційні помилки або відрізняється від оригіналу.\n";
    }

    outfile.close();
    std::cout << "Завдання 10.1 виконано. Результати записано у файл: " << output_filename << std::endl;
}

// Завдання 10.2
void task_10_2(const std::string& filename) {
    std::ofstream file(filename, std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Не вдалося відкрити файл для запису!" << std::endl;
        return;
    }

    file << "ABCDEFGHIJKLMNOPQRSTUVWXYZ\n";

    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    file << "Дата і час дозапису: " << std::put_time(&tm, "%Y-%m-%d %H:%M:%S") << "\n";

    file.close();
}

// Завдання 10.3
void task_10_3(double x, double y, double z, unsigned int b, const std::string& filename) {
    std::ofstream file(filename, std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Помилка: Не вдалося відкрити файл '" << filename << "' для запису." << std::endl;
        return;
    }

    double result = s_calculation(x, y, z);
    file << "Результат функції s_calculation(" << x << ", " << y << ", " << z << ") = ";
    if (std::isnan(result)) {
        file << "невизначено (ділення на нуль або від'ємний підкореневий вираз)" << std::endl;
    } else {
        file << result << std::endl;
    }

    file << "Число " << b << " у двійковому коді: " << std::bitset<32>(b) << std::endl;

    file.close();
    std::cout << "Завдання 10.3 виконано. Результати дописано у файл: " << filename << std::endl;
}
