#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>

// Integration in C++

auto integral(double x0, double x1, int n) {
    if (n <= 0) return 0.0;
    double h = (x1 - x0) / n;
    double sum = 0.5 * (f(x0) + f(x1));
    for (int i = 1; i < n; ++i) {
        double xi = x0 + i * h;
        sum += f(xi);
    }
    return sum * h;
}

double f(double x) {
    return x * x; // Example function: f(x) = x^2
}

int main() {
    double a = 0.0;
    double b = 1.0;
    int n = 1000; // Number of subintervals

    double result = integral(a, b, n);
    std::cout << "Integral of f(x) from " << a << " to " << b << " is approximately: " << result << std::endl;

    return 0;
}
struct Buffer {
    std::vector<std::string> lines;
    std::string filename;
    bool modified = false; 
    void clear() { lines.clear(); modified = true; filename.clear(); }
    
