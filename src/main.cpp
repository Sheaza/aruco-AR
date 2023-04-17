#include <opencv2/opencv.hpp>

int main()
{
    // Load the input image
    cv::Mat inputImage = cv::imread("sample.jpg");

    // Detect the markers in the input image
    std::vector<int> markerIds;
    std::vector<std::vector<cv::Point2f>> markerCorners, rejectedCandidates;

    cv::aruco::DetectorParameters detectorParams = cv::aruco::DetectorParameters();
    cv::aruco::Dictionary dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_4X4_50);
    cv::aruco::ArucoDetector detector(dictionary, detectorParams); 

    detector.detectMarkers(inputImage, markerCorners, markerIds, rejectedCandidates);

    //Draw the detected markers on the input image
    cv::aruco::drawDetectedMarkers(inputImage, markerCorners, markerIds);
    
    // Display the output image
    cv::imshow("Output Image", inputImage);
    cv::waitKey(0);

    return 0;
}
