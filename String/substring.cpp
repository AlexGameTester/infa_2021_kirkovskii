#include <iostream>
using std::cin;
using std::cout;
using std::endl;

struct string
{
    char *str = NULL;
    size_t size = 0;
    size_t capacity = 0;

    size_t calc_capacity(size_t size)
    {
        size_t cap = 1;
        while (cap < size)
        {
            cap *= 2;
        }

        return cap;
    }

    string()
    {
    }

    string(size_t cnt, char c)
    {
        size = cnt;
        capacity = calc_capacity(cnt);
        str = new char[capacity];
        for (int i = 0; i < size; i++)
        {
            str[i] = c;
        }
    }

    string(char *cstr)
    {
        size_t c_size = 0;
        while (cstr[c_size] != '\0')
        {
            c_size++;
        }
        size = c_size;
        capacity = calc_capacity(c_size);

        str = new char[capacity];
        for (int i = 0; i < c_size; i++)
        {
            str[i] = cstr[i];
        }
    }

    string(const string &s)
    {
        size = s.size;
        capacity = s.capacity;
        delete[] str;
        str = new char[capacity];
        for (int i = 0; i < size; i++)
        {
            str[i] = s.str[i];
        }
    }

    ~string()
    {
        delete[] str;
    } //очистить всю используемую память

    string &operator=(const string &new_str)
    {
        size = new_str.size;
        capacity = new_str.capacity;
        delete[] str;
        str = new char[capacity];
        for (int i = 0; i < size; i++)
        {
            str[i] = new_str.str[i];
        }

        return *this;
    }

    bool operator==(const string &other)
    {
        if (size != other.size)
        {
            return false;
        }

        for (int i = 0; i < size; i++)
        {
            if (str[i] != other.str[i])
            {
                return false;
            }
        }

        return true;
    }

    bool operator!=(const string &other)
    { // так будет немного быстрее работать, чем если просто !(this == other) использовать
        if (size != other.size)
        {
            return true;
        }

        for (int i = 0; i < size; i++)
        {
            if (str[i] != other.str[i])
            {
                return true;
            }
        }

        return false;
    }

    bool operator>(const string &other) // Большей считается строка, стоящая ниже в алфавитном списке, или более длинная, если символы совпадают
    {
        size_t minSize = size > other.size ? other.size : size;
        for (int i = 0; i < minSize; i++)
        {
            if (str[i] > other.str[i])
            {
                return true;
            }
        }
        return size > other.size;
    }

    bool operator<(const string &other)
    {
        size_t minSize = size > other.size ? other.size : size;
        for (int i = 0; i < minSize; i++)
        {
            if (str[i] < other.str[i])
            {
                return true;
            }
        }
        return size < other.size;
    }

    string &operator+=(const string &other)
    {
        append(other);
        return *this;
    }

    char operator[](unsigned int pos) {}

    void append(const string other)
    {
        size_t new_size = size + other.size;
        if (capacity < new_size)
        {
            resize(calc_capacity(new_size));
        }

        for (int i = 0; i < other.size; i++)
        {
            str[size + i] = other.str[i];
        }
        size = new_size;
    } // дописать в конец данной строки другую

    void resize(unsigned int new_capacity)
    {
        if (new_capacity > capacity)
        {
            char *new_str = new char[new_capacity];
            for (int i = 0; i < size; i++)
            {
                new_str[i] = str[i];
            }

            delete[] str;
            str = new_str;
            capacity = new_capacity;
        }
    } // увеличить/уменьшить емкость строки

    void reserve(unsigned int capacity)
    {
        size_t additional_capacity = capacity - (this->capacity - this->size);
        if (additional_capacity > 0)
        {
            resize(this->capacity + additional_capacity);
        }
    } // зарезервировать память в нужном объеме

    void insert(unsigned int pos, string other); // Вставка другой строки внутрь данной

    void shrink_to_fit(); //очистить неиспользуемую память

    void clear(); //очистить содержимое строки, занимаемое место при этом не меняется

    friend std::ostream &operator<<(std::ostream &ostr, const string &str)
    {
        char *arr = str.str;
        if (str.size == str.capacity)
        {
            arr = new char[str.capacity + 1];
            for (int i = 0; i < str.capacity + 1; i++)
            {
                arr[i] = str.str[i];
            }
        }
        arr[str.size] = '\0';
        ostr << arr;

        return ostr;
    }
    friend std::istream &operator>>(std::istream &istr, string &str)
    {
        char *cstr;
        istr >> cstr;
        size_t c_size = 0;
        while (cstr[c_size] != '\0')
        {
            c_size++;
        }
        str.size = c_size;
        str.capacity = str.calc_capacity(c_size);

        str.str = new char[str.capacity];
        for (int i = 0; i < c_size; i++)
        {
            str.str[i] = cstr[i];
        }
        string new_str(cstr);

        return istr;
    }
};

string operator+(const string &str1, const string &str2)
{
    string tmp;
    tmp.append(str1);
    tmp.append(str2);
    return tmp;
}

int stoi(const string str, size_t pos = 0, int base = 10);
// Преобразование числа, записанного символами в строке, в int
// base - основание системы счисления
// Числа могут быть отрицательными
// Обработка чисел в сс > 10. Большие и маленькие буквы.

int main()
{
    string s1;
    string s2((size_t)12, 'c');
    string s3(s2);
    string s4((size_t)8, '+');
    std::cout << "Size: " << s2.size << ". Capacity " << s2.capacity << std::endl;
    std::cout << "s2 == s3: " << (s2 == s3) << std::endl;
    std::cout << "s3 == s2: " << (s3 == s2) << std::endl;
    std::cout << "s1 == s2: " << (s1 == s2) << std::endl;
    for (int i = 0; i < 3; i++)
    {
        s4 += s2;
        std::cout << "S4. Size: " << s4.size << ". Capacity: " << s4.capacity << endl;
    }

    cout << s4 << endl;

    string s6("Some string");
    cout << "String s6 from char*: " << s6 << endl;

    string s7("Aaaaaa");
    string s8("Aaaaab");
    // cout << "S8 before: " << s8 << endl;
    // cout << "S8 before: " << s8 << endl;
    // cout << "S8 before: " << s8 << endl;
    // cout << "S8 before: " << s8 << endl;
    cout << s7 << " > " << s8 << "?  " << (s7 > s8) << endl;
    cout << s7 << " > " << s8 << "?  " << (s7 > s8) << endl;
    string s9 = s8;
    cout << "S8: " << s8 << endl;
    cout << "S9: " << s9 << endl;
    cout << "s9 == s8: " << s9 << " == " << s8 << ": " << (s9 == s8) << endl;

    string s5;
    cout << "Enter string: ";
    cin >> s5;
    cout << "Inputed string s5: " << s5 << endl;

    return 0;
}