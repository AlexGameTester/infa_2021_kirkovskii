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

        return cap + 1; // additional slot for '\0' symbol
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

        str[size] = '\0';
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

        if (str)
            delete[] str;
        str = new char[capacity];
        for (int i = 0; i < c_size; i++)
        {
            str[i] = cstr[i];
        }

        str[size] = '\0';
    }

    string(const string &s)
    {
        size = s.size;
        capacity = s.capacity;
        if (str)
            delete[] str;
        str = new char[capacity];
        for (int i = 0; i < size; i++)
        {
            str[i] = s.str[i];
        }

        str[size] = '\0';
    }

    ~string()
    {
        if (str)
            delete[] str;
        size = 0;
        capacity = 0;
    } //очистить всю используемую память

    string &operator=(const string &new_str)
    {
        size = new_str.size;
        capacity = new_str.capacity;
        if (str)
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
    {
        return !(*this == other);
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
            else if (str[i] < other.str[i])
            {
                return false;
            }
            //TODO: If < return false
        }
        return size > other.size;
    }

    bool operator<(const string &other)
    {
        return !(*this > other) and *this != other;
    }

    string &operator+=(const string &other)
    {
        append(other);
        return *this;
    }
    string &operator+=(const char c)
    {
        reserve(1);
        str[size] = c;
        size++;
        str[size] = '\0';
    }

    char operator[](unsigned int pos) const
    {
        return str[pos];
    }

    void append(const string other)
    {
        size_t new_size = size + other.size;
        if (capacity < new_size + 1)
        {
            resize(calc_capacity(new_size));
        }

        for (int i = 0; i < other.size; i++)
        {
            str[size + i] = other.str[i];
        }
        size = new_size;
        str[size] = '\0';
    } // дописать в конец данной строки другую

    void resize(size_t new_capacity)
    {
        if (new_capacity > capacity)
        {
            char *new_str = new char[new_capacity];
            for (int i = 0; i < size; i++)
            {
                new_str[i] = str[i];
            }

            if (str)
                delete[] str;
            str = new_str;
            capacity = new_capacity;
        }
        else if (new_capacity < size)
        {
            capacity = new_capacity + 1; // saving space for '\0'
            size = new_capacity;
            char *new_str = new char[new_capacity];
            for (int i = 0; i < new_capacity; i++)
            {
                new_str[i] = str[i];
            }
            if (str)
                delete[] str;
            str = new_str;
            str[size] = '\0';
        }
    } // увеличить/уменьшить емкость строки

    void reserve(size_t capacity)
    {
        //TODO: Здесь и в других местах проверять на возможность переполнения
        // size_t additional_capacity = capacity - (this->capacity - this->size);
        if (capacity + this->size + 1 > this->capacity)
        {
            resize(calc_capacity(capacity + this->size));
        }
    } // зарезервировать память в нужном объеме

    void insert(size_t pos, string &other)
    {
        capacity = calc_capacity(size + other.size);
        char *new_str = new char[capacity];
        for (size_t i = 0; i < size + other.size; i++)
        {
            if (i < pos)
            {
                new_str[i] = str[i];
            }
            else if (i >= pos && i < pos + other.size)
            {
                new_str[i] = other.str[i - pos];
            }
            else
            {
                new_str[i] = str[i - pos - other.size];
            }
        }
        size += other.size;
        if (str)
            delete[] str;
        str = new_str;
        str[size] = '\0';
    } // Вставка другой строки внутрь данной

    void shrink_to_fit()
    {
        if (capacity > size)
        {
            char *new_str = new char[size + 1];
            for (int i = 0; i < size; i++)
            {
                new_str[i] = str[i];
            }
            if (str)
                delete[] str;
            str = new_str;
            str[size] = '\0';
            capacity = size + 1;
        }
    } //очистить неиспользуемую память

    void clear()
    {
        for (size_t i = 0; i < size; i++)
        {
            str[i] = 0;
        }
        size = 0;
    } //очистить содержимое строки, занимаемое место при этом не меняется

    friend std::ostream &operator<<(std::ostream &ostr, const string &str)
    {
        ostr << str.str;

        return ostr;
    }
    friend std::istream &operator>>(std::istream &istr, string &str)
    {
        char tmp;
        while (!istr.eof() && (tmp = istr.get()) && (tmp != ' ') && (tmp != '\n'))
        {
            str += tmp; // Нужно написать += для char
        }
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

int min(int a, int b)
{
    return a > b ? b : a;
}
int stoi(const string str, size_t pos = 0, int base = 10)
{
    int result = 0;
    char tmp;
    for (size_t i = 0; i < str.size - pos; i++)
    {
        //TODO: Не забыть проверить знак
        tmp = str[pos + i];
        int n1 = tmp - '0';
        int n2 = tmp - 'a';
        int n3 = tmp - 'A';
    }
}
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
    cout << s7 << " > " << s8 << "?  " << (s7 > s8) << endl;
    cout << s7 << " > " << s8 << "?  " << (s7 > s8) << endl;
    s7.resize(2);
    cout << s7 << " > " << s8 << "?  " << (s7 > s8) << endl;
    s8.resize(2);
    cout << s7 << " > " << s8 << "?  " << (s7 > s8) << endl;
    s8.append("Qwv");
    cout << s7 << " > " << s8 << "?  " << (s7 > s8) << endl;
    s7.append("Qww");
    cout << s7 << " > " << s8 << "?  " << (s7 > s8) << endl;
    string s9 = s8;
    cout << "S8: " << s8 << endl;
    cout << "S9: " << s9 << endl;
    cout << "s9 == s8: " << s9 << " == " << s8 << ": " << (s9 == s8) << endl;

    string s10 = "SAjfos";
    s10 += " SOme string";
    cout << "S10: " << s10 << endl;
    cout << "S10 capacity:" << s10.capacity << endl;
    s10.shrink_to_fit();
    cout << "S10 shrinked capacity:" << s10.capacity << endl;

    string s5;
    cout << "Enter string: ";
    cin >> s5;
    cout << "Inputed string s5: " << s5 << endl;
    s5.insert(2, s10);
    s5.insert(5, s10);
    cout << "S5: " << s5 << endl;
    return 0;
}