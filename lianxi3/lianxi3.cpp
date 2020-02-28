// lianxi3.cpp : �������̨Ӧ�ó������ڵ㡣
//


#include "stdafx.h"
#include<opencv.hpp>

using namespace cv;

int main()
{
	Mat srcMat = imread("D:\\1.jpg");
	int  height = srcMat.rows;
	int width = srcMat.cols;
	uchar threshold = 100;
	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {

			uchar average = (srcMat.at<Vec3b>(j, i)[0] + srcMat.at<Vec3b>(j, i)[1] + srcMat.at<Vec3b>(j, i)[2]) / 3;
			if (average > threshold) average = 255;
			else average = 0;
			srcMat.at<Vec3b>(j, i)[0] = average;
			srcMat.at<Vec3b>(j, i)[1] = average;
			srcMat.at<Vec3b>(j, i)[2] = average;
		}
	}
	imshow("src", srcMat);
	waitKey(0);
	return 0;
}

