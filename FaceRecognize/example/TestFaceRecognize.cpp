#include "FaceRecognize.h"

using namespace std;
using namespace cv;

int main()
{
	Caffe_Predefine("F:\\FaceRecognize\\vgg_data\\VGG_FACE_deploy.prototxt", "F:\\FaceRecognize\\vgg_data\\VGG_FACE.caffemodel");//caffe初始化
	Mat lena = imread("1.jpg");//加载图片
	if (!lena.empty())
	{
		int i = 0;
		vector<float> print = ExtractFeature(lena);//提取特征
		
		while (i<print.size())
		{
			cout << print[i++] << endl;//打印特征值
		}
		cout << print.size() << endl;//2622
	}
	imshow("Extract feature", lena);
	waitKey(0);
}