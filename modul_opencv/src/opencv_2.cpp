#include<opencv4/opencv2/opencv.hpp>
#include<iostream>

int main(){
    cv::Mat src = cv::imread("/home/ichbinwil/folder_wildan/Modul-Oprec/modul_opencv/rubik.png");
    cv::Mat src_resize;
    cv::resize(src,src_resize,cv::Size(240,240));
    img_resize.convertTo

    cv::namedWindow("img_resize",cv::WINDOW_AUTOSIZE);
    cv::imshow("img_resize",src_resize);
    return 0;
}