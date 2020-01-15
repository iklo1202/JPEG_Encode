#include <iostream>
#include <opencv.hpp>
#include <opencv2\highgui.hpp>

using namespace cv;
using namespace std;

#include "basic.h"
#include "jpegEncoder.h"


void showKentImg(kentImg* img)
{
	int width = img->width;
	int height = img->height;
	Mat tempImg(height, width, CV_8UC1);
	memcpy(tempImg.data, img->data, width*height);
	
	imshow("TempImg", tempImg);
	cvWaitKey(0);
}




int main()
{
	Mat cvImg = imread("D:\\Lenna.jpg");
	vector<Mat> bgr(3);
	split(cvImg, bgr);


	kentImg* bImg = new kentImg(cvImg.cols, cvImg.rows, bgr[0].data);
	kentImg* gImg = new kentImg(cvImg.cols, cvImg.rows, bgr[1].data);
	kentImg* rImg = new kentImg(cvImg.cols, cvImg.rows, bgr[2].data);


	JPEG_Encoder* jpegEncoder = new JPEG_Encoder(bImg->width, bImg->height);
	jpegEncoder->Encode(bImg, gImg, rImg);


	showKentImg(jpegEncoder->vImg);


	cvWaitKey(0);
	
}