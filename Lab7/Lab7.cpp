#include "pch.h"
#include <iostream>
using std::cout;
using std::endl;
using std::ostream;
using std::istream;
using namespace std;
namespace SpaceTask1 {

    class TLong { // long long 8 -byte
        long long hi, lo; // 16 byte 
    public:
        TLong() :hi(0), lo(0) {}
        TLong(long long h, long long l) :hi(h), lo(l) {}
        TLong(long long h) :hi(h), lo(h) {}
        TLong& operator = (const TLong& s) {
            hi = s.hi; lo = s.lo; return *this;
        };
        TLong& operator=(int s) {
            this->hi = s;
            this->lo = s;
            return *this;
        };
        TLong& operator+(TLong& a) {

            this->hi += a.hi;
            this->lo += a.lo;
            return *this;
        }
        TLong& operator/(int a) {

            this->hi /= a;
            this->lo /= a;
            return *this;
        }
        bool operator > (const TLong& s) {
            if (hi > s.hi) return true;
            if (hi == s.hi && lo >= s.lo) return true;
            return false;
        }
        friend ostream& operator<<(ostream& os, TLong& s);
    };

    ostream& operator<<(ostream& os, TLong& s) {
        os << "H " << s.hi << ":L " << s.lo << " ";
        return os;
    }
    // функція - шаблон
    template <typename T>
    T average(T Array[], int y) {
        T aver = T(0);
        for (int i = 0; i < y; i++) {
            aver = aver + Array[i];
        }
        aver = aver / y;
        return aver;
    }
    // специфікація функції - шаблон для типу char*
    template<> char* average(char* Array[], int y)
    {
        char* result = new char[100];
        int tmp;
        int numLetters = 0;
        int a = 0;


        for (int i = 0; i < 100; i++) {
            tmp = 0;
            numLetters = 0;
            for (int j = 0; j < y; j++) {
                if (strlen(Array[j]) >= i) {
                    tmp += Array[j][i];
                    numLetters++;
                }
            }
            if (numLetters > 0) {
                result[i] = (char)tmp / numLetters;
            }
            else {
                result[i] = '\0';
                break;
            }
        }
        return result;
    }

    int mainTask1()
    {
        cout << "template\n";
        int a[5] = { 6, 5, 3, 2, 1 };
        double b[4] = { 8.3, 2, 4.5, 5468267 };
        char* c[4] = { (char*)"Ann", (char*)"Hello", (char*)"Hi", (char*)"How are you" };
        TLong d[4] = { TLong(1,2),TLong(9,6), TLong(5,8), TLong(5,3) };
        int A;
        double B;
        char* C;
        TLong D;
        A = average(a, 5);cout << "A = " << A << endl;
        B = average(b, 4);cout << "B = " << B << endl;
        C = average(c, 4);cout << "C = " << C << endl;
        D = average(d, 4);cout << "D = " << D << endl;
        return 0;
    }


}
namespace SpaceTask2 {

    class TLong { // long long 8 -byte
        long long hi, lo; // 16 byte 
    public:
        TLong() :hi(0), lo(0) {}
        TLong(long long h, long long l) :hi(h), lo(l) {}
        TLong(long long h) :hi(h), lo(h) {}
        TLong& operator = (const TLong& s) {
            hi = s.hi; lo = s.lo; return *this;
        };
        TLong& operator=(int s) {
            this->hi = s;
            this->lo = s;
            return *this;
        };
        TLong& operator+(TLong& a) {

            this->hi += a.hi;
            this->lo += a.lo;
            return *this;
        }
        TLong& operator/(int a) {

            this->hi /= a;
            this->lo /= a;
            return *this;
        }
        bool operator > (const TLong& s) {
            if (hi > s.hi) return true;
            if (hi == s.hi && lo > s.lo) return true;
            return false;
        }
        bool operator < (const TLong& s) {
            if (hi < s.hi) return true;
            if (hi == s.hi && lo < s.lo) return true;
            return false;
        }
        friend ostream& operator<<(ostream& os, TLong& s);
    };

    ostream& operator<<(ostream& os, TLong& s) {
        os << "H " << s.hi << ":L " << s.lo << " ";
        return os;
    }

    template <typename T>
    void QuickSort(T Array[], /* масив для сортування */
        unsigned int N, /* розмір масиву */
        int L, /* ліва межа сортування */
        int R) /* права межа сортування */
    {
        int iter = L,
            jter = R;

        int middle = (R + L) / 2;

        T x = Array[middle];
        T w;

        do
        {
            while (Array[iter] < x)
            {
                iter++;
            }

            while (x < Array[jter])
            {
                jter--;
            }

            if (iter <= jter)
            {
                w = Array[iter];
                Array[iter] = Array[jter];
                Array[jter] = w;

                iter++;
                jter--;
            }
        } while (iter < jter);

        if (L < jter)
        {
            QuickSort(Array, N, L, jter);
        }

        if (iter < R)
        {
            QuickSort(Array, N, iter, R);
        }
    }


    template <typename T>
    void sort(T* x, int n) {
        QuickSort(x, n, 0, n - 1);
    }

    void QuickSortChar(char* Array[], int y) {
        char* tmp;
        for (int i = 0; i < y - 1; i++) {
            for (int j = i + 1; j < y; j++)
                if (strlen(Array[i]) > strlen(Array[j])) {
                    tmp = Array[i];
                    Array[i] = Array[j];
                    Array[j] = tmp;
                }
        }

    }

    // специфікація функції - шаблон для типу char*
    template<> void sort(char* x[], int y)
    {
        QuickSortChar(x, y);
    }

    int mainTask2()
    {
        cout << "template\n";
        int a[5] = { 6, 5, 3, 2, 1 };
        double b[4] = { 8.3, 2, 4.5, 5468267 };
        char* c[4] = { (char*)"Ann", (char*)"Hello", (char*)"Hi", (char*)"How are you" };
        TLong d[4] = { TLong(1,2),TLong(9,6), TLong(5,8), TLong(5,3) };
        int A;
        double B;
        char C;
        TLong D;
        sort(a, 5);
        cout << "Massive a" << endl;

        for (int i = 0; i < 5; i++) {
            cout << a[i] << " ";
        }


        sort(b, 4);
        cout << endl << "Massive b" << endl;

        for (int i = 0; i < 4; i++) {
            cout << b[i] << " ";
        }

        sort(c, 4);
        cout << endl << "Massive c" << endl;

        for (int i = 0; i < 4; i++) {
            cout << c[i] << " ";
        }

        sort(d, 4);
        cout << endl << "Massive d" << endl;

        for (int i = 0; i < 4; i++) {
            cout << d[i] << " ";
        }

        return 0;
    }
}