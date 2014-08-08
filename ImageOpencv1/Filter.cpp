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

	if(display_caption("Homo Blur")!=0){return 0;};// ������ģ������Ч��
	for(int i = 1;i < MAX_KERNEL_LENGTH;i = i+2)
	{
		blur(src,dst,Size(i,i),Point(-1,-1));  // =>����Ч���ŷ�����һ�������Ĺ���,sizeԽ��Ч��Խ����
		if(display_dst(DELAY_BLUR) != 0)
		{
			return 0;
		}
	}
	 //Guassian Blur
	if(display_caption("Gaus Blur")!=0){return 0;};  // ����ģ�������ϵ�Ӱ������������
	for(int i = 1;i < MAX_KERNEL_LENGTH;i = i+2)
	{
		GaussianBlur(src,dst,Size(i,i),0,0);
		if(display_dst(DELAY_BLUR) != 0)
		{
			return 0;
		}
	}
	
	if(display_caption("Median Blur")!=0){return 0;}; // ˮ�ʻ�
	for(int i = 1;i < MAX_KERNEL_LENGTH;i = i+2)
	{
		medianBlur(src,dst,i);
		if(display_dst(DELAY_BLUR) != 0)
		{
			return 0;
		}
	}
	
	if(display_caption("Bila Blur")!=0){return 0;}; // ��ȫû��ʲô��Ӧ���ǳ��õı����˱�Ե��Ϣ
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

int display_caption(char *caption) // �����ӳٶ�����
{
	dst = Mat::zeros(src.size(),src.type());// ֻ�õ�һ����ɫ��ܵģ�Ȼ���������������д�֡�
	putText(dst,caption,Point(src.cols/4,src.rows/2),CV_FONT_HERSHEY_COMPLEX,1,Scalar(255,255,255));//�������壬λ�ã���ɫ֮���
	imshow(window_name,dst);
	int c= waitKey(DElAY_CAPTION);
	if(c >= 0)
	{
		return -1;
	}
	return 0;
}

int display_dst(int delay)//ÿһ�����ӳٶ�����
{
	imshow(window_name,dst);
	int c = waitKey(delay);
	if(c >= 0)
	{
		return -1;
	}
	return 0;

}