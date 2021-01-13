
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;
Mat rotate(Mat original, double angle)      
{
    Mat rotated;     
    Point2f pt(original.cols / 2., original.rows / 2.);
    Mat r = getRotationMatrix2D(pt, angle, 1.0);      
    warpAffine(original, rotated, r, Size(original.cols, original.rows));
    return rotated;
}

int main()
{
    Mat original = imread("image.jpg");
   
    resize(original, original, Size(), 0.3, 0.3, INTER_LINEAR);

    Mat rotated;
    double angle;
    cout << "Enter Angle you want to rotate this: ";
    cin >> angle;
    rotated = rotate(original, angle);

    imshow("Original Image", original);
    imshow("Rotated Image", rotated);
    waitKey(0);                     
    return 0;
}