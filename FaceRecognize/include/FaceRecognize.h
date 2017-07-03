#ifndef _FACERECOGNIZE_H
#define _FACERECOGNIZE_H

#ifdef FACERECOGNIZE_API_EXPORTS  
#define FACERECOGNIZE_API __declspec(dllexport)  
#else  
#define FACERECOGNIZE_API __declspec(dllimport)  
#endif  


#include <iostream> 
#include <vector>
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/imgproc/imgproc.hpp> 
// must predefined


FACERECOGNIZE_API void Caffe_Predefine(std::string param_file, std::string pretrained_param_file);//caffe初始化，param_file为prototxt文件地址，pretrained_param_file为caffemodel文件地址

FACERECOGNIZE_API std::vector<float> ExtractFeature(cv::Mat FaceROI);//给一个图片 返回一个vector<float>容器







#endif