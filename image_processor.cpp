//
// Created by Ceram J on 2024/12/29.
//

#include "image_processor.h"
#include <iostream>

ImageProcessor::ImageProcessor(const std::string &imagePath) {
    originalImage = cv::imread(imagePath);
    if (originalImage.empty()) {
        std::cerr << "无法加载图片 : " << imagePath << std::endl;
        throw std::runtime_error("图片加载失败!");
    }
}

void ImageProcessor::displayOriginal() const {
    cv::imshow("originalImage", originalImage);
}

void ImageProcessor::convertToGray() {
    cv::cvtColor(originalImage, grayImage, cv::COLOR_BGR2GRAY);
}

void ImageProcessor::applyGaussisBlur() {
    if (grayImage.empty()) {
        std::cerr << "请先转换为灰度图!" << std::endl;
        return;
    }

    cv::GaussianBlur(originalImage, original_blurredImage, cv::Size(5, 5), 1.5);
    cv::GaussianBlur(grayImage, gray_blurredImage, cv::Size(5,5), 1.5);
}

void ImageProcessor::detectEdges() {
    if (gray_blurredImage.empty()) {
        std::cerr << "请先进行去噪处理!" << std::endl;
        return;
    }

    cv::Canny(gray_blurredImage, edgeImage, 50, 150);
}


void ImageProcessor::displayProcessed() const {
    if (!grayImage.empty()) {
        cv::imshow("GrayImage", grayImage);
    }
    if (!gray_blurredImage.empty()) {
        cv::imshow("Gray_BlurredImage", gray_blurredImage);
    }
    if (!original_blurredImage.empty()) {
        cv::imshow("Original_BlurredImage", original_blurredImage);
    }
    if (!edgeImage.empty()) {
        cv::imshow("Edge Detected Image", edgeImage);
    }
}

void ImageProcessor::saveRessults(
    const std::string &grayPath,
    const std::string &gray_blurredPath,
    const std::string& original_blurredPath,
    const std::string& edgeImage_Path) const {
    if (!grayImage.empty()) {
        cv::imwrite(grayPath, grayImage);
    }
    if (!gray_blurredImage.empty()) {
        cv::imwrite(gray_blurredPath, gray_blurredImage);
    }
    if (!original_blurredImage.empty()) {
        cv::imwrite(original_blurredPath, original_blurredImage);
    }
    if (!edgeImage.empty()) {
        cv::imwrite(edgeImage_Path,edgeImage);
    }
}

void ImageProcessor::saveComparison(const std::string &comparisonPath) const {
    if (originalImage.empty() || edgeImage.empty()) {
        std::cerr << "无法生成前后对比图!" << std::endl;
        return;
    }

    cv::Mat resizedEdge;
    cv::resize(edgeImage,resizedEdge, originalImage.size());

    cv::Mat edgeBGR;
    cv::cvtColor(resizedEdge, edgeBGR, cv::COLOR_GRAY2BGR);

    cv::Mat comparison;
    cv::hconcat(originalImage, edgeBGR, comparison);

    cv::imwrite(comparisonPath, comparison);
}








