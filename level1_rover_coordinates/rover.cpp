#include <iostream>
#include <cmath>
using namespace std;

/* Function to calculate distance between two points */
double calculateDistance(double x1, double y1, double x2, double y2){
    return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}

/* Function to validate input values */
bool validateInputs(double u, double a, double vmax){
    if (a <= 0){
        cout << "Error: Acceleration must be positive\n";
        return false;
    }

    if (vmax <= 0){
        cout << "Error: Maximum speed must be greater than 0\n";
        return false;
    }

    if (vmax < u){
        cout << "Error: Maximum speed cannot be less than initial velocity\n";
        return false;
    }

    return true;
}

/* Function to calculate travel time */
double calculateTime(double distance, double u, double a, double vmax){
    if (u == vmax){
        return distance / vmax;
    }

    double t1 = (vmax - u) / a;
    double s1 = u * t1 + 0.5 * a * t1 * t1;

    if (s1 >= distance){
        double A = 0.5 * a;
        double B = u;
        double C = -distance;
        double discriminant = B*B - 4*A*C;
        double t = (-B + sqrt(discriminant)) / (2*A);
        return t;
    }

    double remaining = distance - s1;
    double t2 = remaining / vmax;
    return t1 + t2;
}

int main(){
    double x1, y1, x2, y2;
    double u, a, vmax;
    cout << "Enter origin coordinates (x1 y1):";
    cin >> x1 >> y1;
    cout << "Enter destination coordinates (x2 y2):";
    cin >> x2 >> y2;
    double distance = calculateDistance(x1, y1, x2, y2);

    if (distance == 0){
        cout << "Distance to destination is 0 meters\n";
        cout << "Time required is 0 seconds\n";
        return 0;
    }

    cout << "Enter initial velocity:";
    cin >> u;
    cout << "Enter acceleration:";
    cin >> a;
    cout << "Enter maximum velocity:";
    cin >> vmax;
    if (!validateInputs(u, a, vmax)){
        return 0;
    }
    double time = calculateTime(distance, u, a, vmax);
    cout << "Distance to destination:"<< distance <<" meters\n";
    cout << "Time required:"<< time <<" seconds\n";
    return 0;
}
