//
// Created by Ceram J on 2024/12/25.
//

#ifndef USEOPENCV_H
#define USEOPENCV_H
#include <opencv2/opencv.hpp>
#include <string>

class ImageProcessor {
public:
    explicit ImageProcessor(const std::string & imagePath);

    void displayOriginal() const;

    void convertToGray();

    void applyGaussisBlur();

    void detectEdges();

    void displayProcessed() const;

    void saveRessults(const std::string& grayPath,
        const std::string& gray_blurredPath,
        const std::string& original_blurredPath,
        const std::string& edgeImage_Path) const;

    void saveComparison(const std::string& comparisonPath) const;

private:
    cv::Mat originalImage;
    cv::Mat grayImage;
    cv::Mat gray_blurredImage;
    cv::Mat original_blurredImage;
    cv::Mat edgeImage;
};


#endif //USEOPENCV_H
