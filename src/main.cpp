#include <opencv2/opencv.hpp>

int main() {
    // Load an image from file
    cv::Mat image = cv::imread("sample.jpg");

    // Check if the image was loaded successfully
    if (image.empty()) {
        std::cout << "Failed to load image" << std::endl;
        return 1;
    }

    // Display the image in a window
    cv::imshow("Image", image);

    // Wait for a key press and then exit
    cv::waitKey(0);
    return 0;
}
