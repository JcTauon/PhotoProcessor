#include <iostream>
#include "image_processor.h"

int main()
{
    try {
        ImageProcessor processor("/Users/ceramj/CLionProjects/PhotoProcess/grass.JPG");

        processor.displayOriginal();

        processor.convertToGray();

        processor.applyGaussisBlur();

        processor.detectEdges();

        processor.displayProcessed();

        processor.saveRessults("gray_image.jpg",
            "gary_blur_image.jpg",
            "original_blur_image.jpg",
            "edgeImage.jpg");

        processor.saveComparison("comparison_image.jpg");

        cv::waitKey(0);
    }catch (const std::exception& e) {
        std::cerr << "发生异常" << e.what() << std::endl;
    }
    return 0;
}
