#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {

    // Load the video file
    VideoCapture cap("/Users/elliotarledge/Desktop/Python Testing/c++/learn/dji.mp4");

    // Check if the video file was opened successfully
    if (!cap.isOpened()) {
        cerr << "Error: could not open video file" << endl;
        return -1;
    }

    // Create a window to display the video frames
    namedWindow("Video", WINDOW_NORMAL);

    // Loop over the video frames and display them in the window
    while (true) {

        // Read the next frame from the video file
        Mat frame;
        cap.read(frame);

        // Check if the frame was read successfully
        if (frame.empty()) {
            break;
        }

        // Display the current frame in the window
        imshow("Video", frame);

        // Wait for a key press (or 30 milliseconds) to allow the frame to be displayed
        if (waitKey(30) >= 0) {
            break;
        }
    }

    // Release the video file and destroy the window
    cap.release();
    destroyAllWindows();

    return 0;
}