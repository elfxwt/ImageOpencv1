#include"TestImage.h"



// IplImage * srcImage;
// IplImage *destImage ;
//
// void recallback(int thres)
// {
//	 cvCanny(srcImage,destImage,thres,thres*3,3);
//	 cvShowImage("edgeDetect",destImage);
// }
// void edgeDetect()
//{
//
//	destImage = cvCreateImage(cvGetSize(srcImage),IPL_DEPTH_8U,1);
//
//	cvNamedWindow("src",CV_WINDOW_AUTOSIZE);
//	cvNamedWindow("edgeDetect",CV_WINDOW_NORMAL);
//
//	
//	int initPos = 1;
//	cvCreateTrackbar("Threshold","edgeDetect",&initPos,100,recallback); // 要用静态函数才能作为回调函数
//
//	cvShowImage("src",srcImage);
//	recallback(1);
//	cvWaitKey();
//
//	cvDestroyAllWindows();
//	cvReleaseImage(&destImage);
//
//}

Mat scr,srt_gray;
Mat dst,detected_edge;
int Thresh = 0;
int lowThreshold;
int const max_lowThreshold = 100;
int ratio = 3;
int kernel_size = 3;
char * window_name = "source image";
char *binWindowName = "binary image";
const char* barName = "binaryImageBarname";
int DELAY = 200;

void on_trackerbar(int ,void*)
{
	threshold(scr,dst,Thresh,255,THRESH_BINARY_INV);
	
	imshow(binWindowName,dst);

}
int display_dst(int delay);

int main()
{
	//
	//String path = "../image/kimi.png";
	//Mat image = imread(path,-1);
	//int showLevel = -1;
	////srcImage = cvLoadImage(path.c_str(),CV_LOAD_IMAGE_GRAYSCALE);
	////edgeDetect();
	////MyImage *testimg = new MyImage(path,showLevel);
	//Mat result = image;
	//imshow("the input image",image);
	//blur(image,image,Size(7,7));
	//imshow("blur result",result);
	//waitKey(0);
	scr = imread("../image/1.jpg");
	if(!scr.data )
		return -1;
	dst.create(scr.size(),scr.type());
	cvtColor(scr,srt_gray,CV_BGR2GRAY); // 变成灰度图的方法
	namedWindow(window_name,CV_WINDOW_AUTOSIZE);
	imshow(window_name,scr);
	namedWindow(binWindowName,CV_WINDOW_AUTOSIZE);

	createTrackbar(barName,binWindowName,&Thresh,254,on_trackerbar);
	
	on_trackerbar(0,0);
	
	waitKey();
	
	return 0;
	


	
}

int display_dst(int delay)//每一幅画延迟多少秒
{
	imshow(window_name,dst);
	int c = waitKey(delay);
	if(c >= 0)
	{
		return -1;
	}
	return 0;

}