#include <bits/stdc++.h>
using namespace std;

double f(double x){
    if (x == 0)
        return 999999;

    return (1.0 - 0.6 * x) / x;
}

void graph(double minX, double maxX) {
    for (double y = 2.0; y >= -2.0; y -= 0.1) {
        cout << fixed << setprecision(1) << setw(4) << y << " ";

        for (double x = minX; x <= maxX; x += 0.1) {
            double fx = f(x);

            if (abs(fx - y) < 0.05)
                cout << "*";
            else if (abs(y) < 0.05){
                if (abs(x) < 0.05)
                    cout << "+";
                else
                    cout << "-";
            }
            else if (abs(x) < 0.05)
                cout << "|";
            else
                cout << " ";
        }
        cout << endl;
    }
}

int main() {
    double x1, x2;
    int iterasi;

    cout << "Masukkan x1                    : ";
    cin >> x1;

    cout << "Masukkan x2                    : ";
    cin >> x2;

    cout << "Masukkan batas jumlah iterasi  : ";
    cin >> iterasi;

    cout << "\nIterasi\tx1\tx2\tnext\tf(next)" << endl;

    int a = 1;
    double next = 0;

    while(iterasi--) {
        next = x2 - ((f(x2) * (x1 - x2)) / (f(x1) - f(x2)));

        cout << fixed << setprecision(5);
        cout << a++ << "\t" << x1 << "\t" << x2 << "\t" << next << "\t" << f(next) << endl;

        if(f(x1) * f(next) < 0) {
            x2 = next;
        } else {
            x1 = next;
        }
    }

    double minGrafik = min(x1, x2) - 1.0;
    double maxGrafik = max(x1, x2) + 1.0;
    cout << endl;
    graph(minGrafik, maxGrafik);

    return 0;
}
