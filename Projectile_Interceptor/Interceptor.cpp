
#include <iostream>
#include <cmath>
using namespace std;

class Ball {
private:

    double x , y;
    double vx , vy;
    const double gravity = -9.8;

public:

    Ball (double x, double y, double vx, double vy) {
        this-> x = x;
        this-> y = y;
        this-> vx = vx;
        this-> vy = vy;
    }



    double get_xcoord () {
        return x;
    }

    double get_ycoord () {
        return y;
    }

    double get_horiz_velocity() {
        return vx;
    }

    double get_vert_velocity() {
        return vy;
    }


    void updatePositions(double dt) {
        x += vx * dt;          //Horizontal velocity remains same
        vy = vy + (gravity * dt);    //Vertical Velocity decrease till summit
        y += vy * dt;
    }


};


class Interceptor{
private:

    double x_dist;
    double maxSpeed;

public:

    Interceptor(double startX, double maxSpeed) {
        this->x_dist = startX;
        this-> maxSpeed = maxSpeed;
    }

    double get_x_distance() {
        return x_dist;
    }

    void moveTowards(double targetX, double dt){
        double distanceToCover = abs(targetX - get_x_distance());
        double maxStep = maxSpeed * dt;

        if (distanceToCover <= maxStep) {
            x_dist = targetX;
            cout<< "Bang On!! Strike"<< endl;
        } else {
            double dir_vector = targetX - x_dist;
            if (dir_vector > 0) {
                x_dist += maxStep;
            } else if (dir_vector < 0) {
                x_dist -= maxStep;
            }
        }
    }
};