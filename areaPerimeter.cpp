#include <iostream>
using namespace std;
class Rectangle{
    private:
    double width;
    double length;

    public:
    //setters
    void setWidth(double w){
        if(w>0) width = w;
        else
        cout<<"Invalid width! Must be greater than 0.\n";
    }
    void setLength(double l){
        if(l>0) length = l;
        else
        cout<<"Invalid length! Must be greater than 0.\n"; 
    }
    //getters
    double getWidth() const{
        return width;
    }
    double getLength() const{
        return length;
    }
    //calculation fuctions
    double calculateArea() const{
        return width*length;
    }
    double calculatePerimeter() const{
        return 2*(width+length);
    }
};
int main(){
    //creating, setting and retrieving the dimensions and calculating the area and perimeter for rectangle one and two.
    Rectangle rect1;
    rect1.setWidth(5.0);
    rect1.setLength(10.0);

    cout<<"RECTANGLE ONE"<<"\n";
    cout<<"Width: "<<rect1.getWidth() << "\n";
    cout<<"Length: "<<rect1.getLength() << "\n";
    cout<<"Area: "<< rect1.calculateArea() <<"\n";
    cout<<"Perimeter: "<< rect1.calculatePerimeter() <<"\n";

    Rectangle rect2;
    rect2.setWidth(10.0);
    rect2.setLength(20.0);

    cout<<"RECTANGLE TWO"<<"\n";
    cout<<"Width: "<<rect2.getWidth() << "\n";
    cout<<"Length: "<<rect2.getLength() << "\n";
    cout<<"Area: "<< rect2.calculateArea() <<"\n";
    cout<<"Perimeter: "<< rect2.calculatePerimeter() <<"\n";


return 0;
}