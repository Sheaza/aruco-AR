#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <opencv2/opencv.hpp>
#include <filesystem>


int main(int argc, char* argv[]) {

    // ------------------
    // FILESYSTEM STUFF
    // ------------------

    auto _filename = "test.jpg";
    std::filesystem::path file_path = std::filesystem::current_path() 
        / std::filesystem::path("test.jpg");

    std::cout << "The path of the executed file is: " << std::filesystem::current_path() << "\n";
    std::cout << "The path of opening image:" << file_path << "\n";
    
    if (!std::filesystem::exists(file_path)) {
        std::cout << "File does not exist.\n\n";
        return -1;
    }
    else std::cout << "File does exist.\n\n";


    // --------------------------
    //  OPENGL & GLFW STUFF
    // --------------------------
    
    GLFWwindow* window;

    if (!glfwInit()) {
        std::cout << "glfw is not working\n";
        return -1;
    }
    else std::cout << "glfw is working\n";
    
        // --------------------------
        //  GLEW STUFF
        // --------------------------
        auto glew_initialized = glewInit();
        if (glew_initialized) std::cout << "glew is working\n";
        else std::cout << "glew is not working\n";
        // ---------------------------

    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        std::cout << "glfw is not working\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        
        glBegin(GL_TRIANGLES);
	    glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.0f, 0.5f);
        glVertex2f(0.5f, -0.5f);
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

   glfwTerminate();

    // --------------------------
    //  ARUCO STUFF
    // --------------------------

    cv::Mat inputImage = cv::imread(_filename, cv::IMREAD_COLOR);
    
    if (inputImage.empty()) std::cout << "opencv is not necessarily working.\n";
    else std::cout << "opencv is working\n";

    std::vector<int> markerIds;
    std::vector<std::vector<cv::Point2f>> markerCorners, rejectedCandidates;

    cv::aruco::DetectorParameters detectorParams = cv::aruco::DetectorParameters();
    cv::aruco::Dictionary dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_4X4_50);
    cv::aruco::ArucoDetector detector(dictionary, detectorParams); 

    detector.detectMarkers(inputImage, markerCorners, markerIds, rejectedCandidates);

    cv::aruco::drawDetectedMarkers(inputImage, markerCorners, markerIds);
    
    cv::imshow("Output Image", inputImage);
    cv::waitKey(0);

    return 0;
}