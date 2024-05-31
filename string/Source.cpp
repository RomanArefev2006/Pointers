#include <iostream>
#include <string>

using namespace std;

string to_lower(const string& s);
string to_upper(const string& s);
string shrink(const string& s);
bool is_palindrome(const string& s);
bool is_int_number(const string& s);
bool to_int_number(const string& s);
bool is_bin_number(const string& s);
int bin_to_dec(const string& s);
bool is_hex_number(const string& s);
int hex_to_dec(const string& s);

int main() {
    setlocale(LC_ALL, "RU");
    cout << to_lower("HELLO") << endl;
    cout << to_upper("hello") << endl;
    cout << shrink("Хорошо        живет    на   свете      Винни    Пух") << endl;
    cout << is_palindrome("Анна") << endl;
    cout << is_int_number("123") << endl;
    cout << to_int_number("123") << endl;
    cout << is_bin_number("1010") << endl;
    cout << bin_to_dec("1010") << endl;
    cout << is_hex_number("1a2f") << endl;
    cout << hex_to_dec("1a2f") << endl;

    return 0;
}

string to_lower(const string& s) {
    string result = s;
    for (char& c : result) {
        if (c >= 'A' && c <= 'Z') {
            c = c + ('a' - 'A');
        }
    }
    return result;
}

string to_upper(const string& s) {
    string result = s;
    for (char& c : result) {
        if (c >= 'a' && c <= 'z') {
            c = c - ('a' - 'A');
        }
    }
    return result;
}


string shrink(const string& s) {
    string result;
    bool in_word = false;
    for (size_t i = 0; i < s.length(); ++i) {
        if (s[i] != ' ' && s[i] != '\t') {
            if (in_word) {
                result += s[i];
            }
            else {
                if (!result.empty()) {
                    result += ' ';
                }
                result += s[i];
                in_word = true;
            }
        }
        else {
            in_word = false;
        }
    }
    return result;
}

bool is_palindrome(const string& s) {
    string cleaned;
    for (char c : s) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            if (c >= 'A' && c <= 'Z') {
                c = c + ('a' - 'A');
            }
            cleaned += c;
        }
    }
    size_t len = cleaned.length();
    for (size_t i = 0; i < len / 2; ++i) {
        if (cleaned[i] != cleaned[len - 1 - i]) {
            return false;
        }
    }
    return true;
}

bool is_int_number(const string& s) {
    if (s.empty() || (s.size() == 1 && !isdigit(s[0]))) {
        return false;
    }
    size_t i = 0;
    if (s[0] == '-' || s[0] == '+') {
        i = 1;
    }
    for (; i < s.size(); ++i) {
        if (!isdigit(s[i])) {
            return false;
        }
    }
    return true;
}

bool to_int_number(const string& s) {
    if (is_int_number(s)) {
        return true;
    }
    else {
        cout << "Не число";
    }
}

bool is_bin_number(const string& s) {
    for (char c : s) {
        if (c != '0' && c != '1') {
            return false;
        }
    }
    return true;
}

int bin_to_dec(const string& s) {
    if (is_bin_number(s)) {
        return stoi(s, nullptr, 2);
    }
    else {
        cout << "Not a binary number";
    }
}

bool is_hex_number(const string& s) {
    size_t len = s.length();
    size_t start = 0;
    if (len > 2 && s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
        start = 2;
    }
    for (size_t i = start; i < len; ++i) {
        char c = s[i];
        if (!(isdigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))) {
            return false;
        }
    }
    return true;
}

int hex_to_dec(const string& s) {
    if (is_hex_number(s)) {
        return stoi(s, nullptr, 16);
    }
    else {
        throw "Not a hexadecimal number";
    }
}