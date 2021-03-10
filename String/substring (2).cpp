#include <iostream>

struct string {
    char *str;
    size_t size;
    size_t capacity;

    string() {  }

    string(size_t cnt, char c) {  }

    string(const string& s) {  }

    ~string();     //очистить всю используемую память

    string& operator= (const string& new_str) {  }

    bool operator== (const string& other) {  }

    bool operator!= (const string& other) {  }

    bool operator> (const string& other) {  }

    bool operator< (const string& other) {  }

    string& operator+= (const string& other) {  }

    char operator[] (unsigned int pos) {  }

    void append(const string other);  // дописать в конец данной строки другую

    void resize(unsigned int new_capacity);  // увеличить/уменьшить емкость строки

    void reserve(unsigned int capacity); // зарезервировать память в нужном объеме

    void insert(unsigned int pos, string other);  // Вставка другой строки внутрь данной

    void shrink_to_fit();  //очистить неиспользуемую память

    void clear();   //очистить содержимое строки, занимаемое место при этом не меняется

    friend std::ostream& operator<< (std::ostream& ostr, const string& str) {  }
    friend std::istream& operator>> (std::istream& istr, const string& str) {  }

};


string operator + (const string & str1, const string & str2)
{

}


int stoi(const string str, size_t pos = 0, int base = 10 );
// Преобразование числа, записанного символами в строке, в int
// base - основание системы счисления
// Числа могут быть отрицательными
// Обработка чисел в сс > 10. Большие и маленькие буквы.
