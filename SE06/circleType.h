class circleType {
public:
    void setRadius(double r);

    double getRadius();

    double area();

    double circumference();

    circleType(double r = 0);

private:
    double radius;
};