#include <opencv2/opencv.hpp>
#include <opencv2/core/utils/logger.hpp>
#include <iostream>

void main(int argc, char *argv[])
{
  if (argc != 2) {
    std::cout << "Please Enter input file to read" << std::endl;
    return;
  }
  std::string inputFile = argv[1];
  cv::VideoCapture cap(inputFile);
  if (!cap.isOpened()) {
    std::cout << "Error opening video stream or file" << std::endl;
    return;
  }
  for (int i = 0; i < 10; i++) {
    cv::Mat frame;
    cap >> frame;

  }
  std::cout << "finished" << std::endl;
  std::getchar();
  return;
}
