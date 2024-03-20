// �������� ��������� �� 1 ����
// � ������� DelNum �������� try/catch ����. � ������� main ������������ throw.

#include <iostream>  
#include <ctime>  
using namespace std;

template<typename Type>
class MyException {
    Type report;
public:
    MyException() {}
    MyException(Type report) {
        this->report = report;
    }
    ~MyException() {}
};

template<typename Type>
class Array {
    Type* arr;
    Type n;
public:
    ~Array() {
        delete[] arr;
    };
    Array();
    Array(Type size) {
        n = size;
        arr = new Type[n];
    }

    friend void DelNum(Array<Type>& arr) {
        int m = 0; // ������� ���-�� ��������� �����  
        for (int i = 0; i < arr.n; i++) {
            for (int k = 2; k <= arr.arr[i] / 2; k++) {
                if (arr.arr[i] % k == 0) {
                    m++;
                }
            }
            if (m != 0) {
                cout << arr.arr[i] << " ";
                m = 0;
            }
        }
        cout << endl;
    }
    

    template<typename Type>
    friend istream& operator>>(istream& in, Array<Type>& arr);

    template<typename Type>
    friend ostream& operator<<(ostream& out, Array<Type>& arr);

    template<typename Type>
    friend void DelNum(Array<Type>& arr);
};


template<typename Type>
istream& operator>>(istream& in, Array<Type>& arr) {
    srand(time(0));
    for (int i = 0; i < arr.n; i++) {
        arr.arr[i] = rand() % 100 + 1;
    }
    return in;
}

template<typename Type>
ostream& operator<<(ostream& out, Array<Type>& arr) {
    srand(time(0));
    cout << "��� ������ �����: ";
    for (int i = 0; i < arr.n; i++) {
        cout << arr.arr[i] << " ";
    }
    cout << endl;
    return out;
}

template<typename Type>
void DelNum(Array<Type>& arr) { // ���� try/catch
    try {
        int m = 0; // ������� ���-�� ��������� �����  
        for (int i = 0; i < arr.n; i++) {
            for (int k = 2; k <= arr.arr[i] / 2; k++) {
                if (arr.arr[i] % k == 0) {
                    m++;
                }
            }
            if (m != 0) {
                cout << arr.arr[i] << " ";
                m = 0;
            }
        }
        cout << endl;
    }
    catch (MyException& e) {
        cerr << "������" << endl;
    }
    catch (exception& ex) {
        cerr << "������" << endl;
    }
}


int main() {
    setlocale(LC_ALL, "rus");
    int n;
    cout << "������� ����� �������: ";
    cin >> n;

    if (n <= 0) throw exception("����� ������� ������ ���� ������ ����"); // throw

    Array<int>arr(n);
    cin >> arr;
    cout << arr;
    DelNum(arr);
    system("pause");
    return 0;
}
