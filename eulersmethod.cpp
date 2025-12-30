// program euler's method for solving ordinary differential equations
#include <iostream>
#include <functional>


auto euler_method(std::function<double(double, double)> f, double y0, double x0, double h, int n) {
    double y = y0;
    double x = x0;

    for (int i = 0; i < n; ++i) {
        y += h * f(x, y);
        x += h;
    }

    return y;
}

int main() {
    // Example: dy/dx = x + y, with initial condition y(0) = 1
    auto f = [](double x, double y) { return x * x + x * y - x ; };
    double y0 = 1.0; // initial value
    double x0 = 0.0; // initial x
    double h = 0.1;  // step size
    int n = 100;     // number of steps

    double result = euler_method(f, y0, x0, h, n);
    std::cout << "Approximate solution after " << n << " steps: " << result << std::endl;

    return 0;
}