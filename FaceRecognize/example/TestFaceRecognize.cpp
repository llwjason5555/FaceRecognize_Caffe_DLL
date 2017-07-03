#include "FaceRecognize.h"

using namespace std;
using namespace cv;

int main()
{
	Caffe_Predefine("F:\\FaceRecognize\\vgg_data\\VGG_FACE_deploy.prototxt", "F:\\FaceRecognize\\vgg_data\\VGG_FACE.caffemodel");//caffe��ʼ��
	Mat lena = imread("1.jpg");//����ͼƬ
	if (!lena.empty())
	{
		int i = 0;
		vector<float> print = ExtractFeature(lena);//��ȡ����
		
		while (i<print.size())
		{
			cout << print[i++] << endl;//��ӡ����ֵ
		}
		cout << print.size() << endl;//2622
	}
	imshow("Extract feature", lena);
	waitKey(0);
}