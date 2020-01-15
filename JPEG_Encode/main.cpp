#include <iostream>
#include <opencv.hpp>
#include <opencv2\highgui.hpp>

using namespace cv;
using namespace std;

#include "basic.h"


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


	ImageList* imgList = new ImageList();
	ImageNode* node1 = new ImageNode(bImg);
	ImageNode* node2 = new ImageNode(gImg);
	ImageNode* node3 = new ImageNode(rImg);

	imgList->Add(node1);
	imgList->Add(node2);
	imgList->Add(node3);



	showKentImg(imgList->pHead->img);


	cvWaitKey(0);
	
}