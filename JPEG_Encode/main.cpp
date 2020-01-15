#include <iostream>
#include <opencv.hpp>
#include <opencv2\highgui.hpp>


using namespace cv;
using namespace std;

int main()
{
	Mat img = imread("D:\\Lenna.jpg");
	imshow("img", img);
	cvWaitKey(0);
	
}