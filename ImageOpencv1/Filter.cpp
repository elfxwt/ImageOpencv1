#include"TestImage.h"


int DElAY_CAPTION = 1500;
int DELAY_BLUR = 600;
int MAX_KERNEL_LENGTH = 31;
Mat src,dst;
char window_name[] = "Filter Demo";

int  display_caption(char *caption);
int display_dst(int delay);


int fiterDemo()
{
	
	namedWindow(window_name,CV_WINDOW_AUTOSIZE);
	src = imread("../image/1.jpg",1);
	if(display_caption("Original Image") != 0){return 0;}
	dst = src.clone();
	if(display_dst(DELAY_BLUR) != 0)
		{
			return 0;
		}

	if(display_caption("Homo Blur")!=0){return 0;};// 将背景模糊掉的效果
	for(int i = 1;i < MAX_KERNEL_LENGTH;i = i+2)
	{
		blur(src,dst,Size(i,i),Point(-1,-1));  // =>看了效果才发现是一个渐进的过程,size越大，效果越明显
		if(display_dst(DELAY_BLUR) != 0)
		{
			return 0;
		}
	}
	 //Guassian Blur
	if(display_caption("Gaus Blur")!=0){return 0;};  // 整体模糊，像老电影，阴暗下来的
	for(int i = 1;i < MAX_KERNEL_LENGTH;i = i+2)
	{
		GaussianBlur(src,dst,Size(i,i),0,0);
		if(display_dst(DELAY_BLUR) != 0)
		{
			return 0;
		}
	}
	
	if(display_caption("Median Blur")!=0){return 0;}; // 水彩画
	for(int i = 1;i < MAX_KERNEL_LENGTH;i = i+2)
	{
		medianBlur(src,dst,i);
		if(display_dst(DELAY_BLUR) != 0)
		{
			return 0;
		}
	}
	
	if(display_caption("Bila Blur")!=0){return 0;}; // 完全没有什么反应，非常好的保留了边缘信息
	for(int i = 1;i < MAX_KERNEL_LENGTH;i = i+2)
	{
		bilateralFilter(src,dst,i,i*2,i/2);
		if(display_dst(DELAY_BLUR) != 0)
		{
			return 0;
		}
	}

	display_caption("End:Press a key!");
	waitKey(0);
	return 0;
}

int display_caption(char *caption) // 标题延迟多少秒
{
	dst = Mat::zeros(src.size(),src.type());// 只得到一个黑色框架的，然后下面可以往上面写字。
	putText(dst,caption,Point(src.cols/4,src.rows/2),CV_FONT_HERSHEY_COMPLEX,1,Scalar(255,255,255));//定义字体，位置，颜色之类的
	imshow(window_name,dst);
	int c= waitKey(DElAY_CAPTION);
	if(c >= 0)
	{
		return -1;
	}
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